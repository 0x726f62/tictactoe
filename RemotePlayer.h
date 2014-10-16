/**
* \file RemotePlayer.h
* \brief Header file represents remote player functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef REMOTEPLAYER_H
#define REMOTEPLAYER_H

#include "Player.h"

/******************************************************************************/

/**
* \brief Remote player functionality
*
*/
class RemotePlayer : public Player
{
    public:
        /**
        * Creates instance of RemotePlayer
        * \param name Name for the player
        * \param userInterface Pointer to grafic UI
        * \param gameLogic Pointer to GameLogic object
        * \param stone Game Pointer to object Stone
        * \param val Integer representation of RemotePlayer
        * \param networkInterface Pointer to network UI
        */
        RemotePlayer(const std::string & name,
                     IUserInterface * userInterface,
                     GameLogic * gameLogic,
                     Stone * stone,
                     int val,
                     INetwork * networkInterface);
        /** Destructor */
        virtual ~RemotePlayer();
        /**
         * Receive Coordinate from the player
         * \return Pointer to the received Coordinate
         */
        virtual const Coordination * ReceiveAndValidInput();
        /**
         * Set Coordinate for the Stone
         * \param coor Pointer to the received Coordinate
         */
        virtual void PrepareStone(const Coordination * coor);
        /**
         * Print new data into terminal or sends thme over network
         */
        virtual void Update();
    protected:

    private:
};

#endif // REMOTEPLAYER_H
