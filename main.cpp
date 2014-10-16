/**
* \file main.cpp
* \brief Main file of program.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*
* \mainpage TicTacToe doxygen documentation
*
* \section DESCRIPTION
*
* This project was created for subject PA2 as a semestral work in C\\C++.
* It implements turn based game for 2 players, where one player
* is trying put his stones in row of 5. It uses grafical library
* ncurese and unix sockets for game over network.
*/

#include <iostream>
#include "IUserInterface.h"
#include "UserInterfaceNcurse.h"
#include "Cross.h"
#include "Circle.h"
#include "GameField.h"
#include "Coordination.h"
#include "LocalHuman.h"
#include "AI.h"
#include "RemotePlayer.h"
#include "PlayerRotator.h"
#include "INetwork.h"
#include "NetworkTCPClient.h"
#include "NetworkTCPServer.h"

/**
* Main function fo the program
* \param argc Number of arguments
* \param argv Arguments
* \return Returns 0, if SUCCESS
*/
int main(int argc, char *argv[])
{
    std::string strIP, strPort;
    bool remote, server, ai, set;

    //improvised menu, takes params from pTerminal
    
    remote = server = ai = set = false;

    if ( argc == 2 )
    {
        if( strcmp(argv[1],"1") == 0)
        {
            ai = false;
            set = true;
        }
        if(strcmp(argv[1],"2") == 0)
        {
            ai = true;
            set = true;
        }

        remote = false;
    }

    if ( argc == 4 )
    {
        if(strcmp(argv[1],"3") == 0)
        {
            strIP=argv[2];
            strPort=argv[3];
            set = true;
            server=true;
        }
        if(strcmp(argv[1],"4") == 0)
        {
            strIP=argv[2];
            strPort=argv[3];
            set = true;
            server = false;
        }

            remote = true;
    }

    if (!set)
    {
        std::cout << "USAGE: " << argv[0] << " number [IP] [port]"<<std::endl;
        std::cout << "1 - local pvp" << std::endl;
        std::cout << "2 - local ai" << std::endl;
        std::cout << "3 IP port - remote server IP port" << std::endl;
        std::cout << "4 IP port - remote client IP port" << std::endl;

        return EXIT_SUCCESS;
    }

    PlayerRotator rotator;
    const Coordination * coop;
    bool end = false;
    Coordination coor;
    GameLogic gameLogic(NLINES,NCOLS);

    UserInterfaceNcurse nInterface;
    IUserInterface * userInterface = &nInterface;

    GameField field(userInterface, &coor);
    Cross cross(userInterface, &coor, "cross");
    Circle circle(userInterface, &coor, "circle");

    Stone * CrossPrototype = &cross;
    Stone * CirclePrototype = &circle;

    INetwork * networkInterface;
    Player * curPlayer;

    if (remote)
    {
        if(server)
        {
            networkInterface = new NetworkTCPServer(strIP, std::stoi(strPort));

            curPlayer = new RemotePlayer("RP1",userInterface, &gameLogic, CrossPrototype, 1, networkInterface);
            rotator.Add(curPlayer);
            rotator.Add(new LocalHuman("LP2",userInterface, &gameLogic, CirclePrototype, 2, networkInterface));
        } else{
            networkInterface = new NetworkTCPClient(strIP, std::stoi(strPort));

            curPlayer = new LocalHuman("LP1",userInterface, &gameLogic, CirclePrototype, 2, networkInterface);
            rotator.Add(curPlayer);
            rotator.Add(new RemotePlayer("RP2",userInterface, &gameLogic, CrossPrototype, 1, networkInterface));
        }

    } else{
        networkInterface = NULL;
        curPlayer = new LocalHuman("LP1",userInterface, &gameLogic, CrossPrototype, 1, networkInterface);
        rotator.Add(curPlayer);
        if (ai)
        {
            rotator.Add(new AI("LAI2",userInterface, &gameLogic, CirclePrototype, 2, networkInterface));
        }else{
            rotator.Add(new LocalHuman("LP2",userInterface, &gameLogic, CirclePrototype, 2, networkInterface));
        }
    }

    userInterface->DrawInMsgList("Creating board ...");
    field.Draw();


    //TODO bugs
    //check winner diagonal
    // menu

    try
    {
        if (remote)
        {
            userInterface->DrawInMsgList("Initiating connection and waiting for clients ...");
            networkInterface->init();
            userInterface->DrawInMsgList("Connection established");
        }
        while (1)
        {
            coop = curPlayer->ReceiveAndValidInput();

            if (coop == NULL)
            {
                userInterface->DrawInMsgList("Lost Connection");
                break;
            }

            curPlayer->StoreMove(coop);

            if ( curPlayer->HasWon() ) end = true;

            if ( (!end) && curPlayer->HasTied() ) end = true;

            curPlayer->PrepareStone(coop);

            curPlayer = rotator.Next();

            curPlayer->Update();

            if (end) break;
        }

    } catch (std::exception & e)
    {
        if(networkInterface) delete networkInterface;

        std::cerr << e.what() << std::endl;

        return EXIT_FAILURE;
    }


    if(networkInterface) delete networkInterface;

    userInterface->DrawInMsgList("Game over!");
    userInterface->DrawInMsgList("Press any key to quit ...");
    getch();

    return EXIT_SUCCESS;
}

