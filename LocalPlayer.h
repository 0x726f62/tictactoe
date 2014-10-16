/**
* \file LocalPlayer.h
* \brief Header file represents abstract local player.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include "Player.h"

/******************************************************************************/

/**
* \brief Abstract Local player
*
*/
class LocalPlayer : public Player
{
    public:

        /** Destructor */
        virtual ~LocalPlayer();
        virtual void PrepareStone(const Coordination * coor);
    protected:
        /**
        * Creates instance of LocalPlayer
        * \param name Name for the player
        * \param userInterface Pointer to grafic UI
        * \param gameLogic Pointer to GameLogic object
        * \param stone Game Pointer to object Stone
        * \param val Integer representation of LocalPlayer
        * \param networkInterface Pointer to network UI
        */
        LocalPlayer(const std::string & name,
                    IUserInterface * userInterface,
                    GameLogic * gameLogic,
                    Stone * stone,
                    int val,
                    INetwork * networkInterface);
        /**
         * Print new data into terminal or sends the over network
         */
        virtual void Update();
    private:
};

#endif // LOCALPLAYER_H
