/**
* \file LocalHuman.h
* \brief Header file represents local player functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef LOCALHUMAN_H
#define LOCALHUMAN_H

#include "LocalPlayer.h"

/******************************************************************************/

/**
* \brief Human player functionality
*
*/
class LocalHuman : public LocalPlayer
{
    public:
        /**
        * Creates instance of LocalHuman
        * \param name Name for the LocalHuman
        * \param userInterface Pointer to grafic UI
        * \param gameLogic Pointer to GameLogic object
        * \param stone Game Pointer to object Stone
        * \param val Integer representation of LocalHuman
        * \param networkInterface Pointer to network UI
        */
        LocalHuman( const std::string & name,
                    IUserInterface * userInterface,
                    GameLogic * gameLogic,
                    Stone * stone,
                    int val,
                    INetwork * networkInterface);
        /** Destructor */
        virtual ~LocalHuman();
        /**
         * Receive Coordinate from the player
         * \return Pointer to the received Coordinate
         */
        virtual const Coordination * ReceiveAndValidInput();
    protected:
    private:
};

#endif // LOCALHUMAN_H
