/**
* \file AI.cpp
* \brief Source file represents AI functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "AI.h"

/******************************************************************************/

AI::AI(const std::string & name ,
        IUserInterface * userInterface,
        GameLogic * gameLogic,
        Stone * stone,
        int val,
        INetwork * networkInterface) :
        LocalPlayer(name, userInterface, gameLogic, stone, val, networkInterface)
{
    //ctor
    srand ( time(NULL) );
}

/******************************************************************************/

AI::~AI()
{
    //dtor
}

/******************************************************************************/

const Coordination * AI::ComputeMove()
{
    int x, y;

    while(1)
    {
        x = rand() % m_gameLogic->Getcols();
        y = rand() % m_gameLogic->Getrows();

        if (  ! m_gameLogic->CheckExistingXY(x, y) ) break;

    }

    return new Coordination(x,y);
}

/******************************************************************************/

const Coordination * AI::ReceiveAndValidInput()
{
    m_userInterface->DrawInMsgList(std::string("Local AI ") + m_name + " moving " + "with stone " + m_stone->ToString());
    return ComputeMove();
}
