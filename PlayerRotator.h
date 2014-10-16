/**
* \file PlayerRotator.h
* \brief Header file represents functionality for changing turns.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef PLAYERROTATOR_H
#define PLAYERROTATOR_H

#include "Player.h"

/******************************************************************************/

/**
* \brief Rotates players
*
* Rotates players between turns
*/
class PlayerRotator
{
    public:
        /** Default constructor */
        PlayerRotator();
        /** Destructor */
        virtual ~PlayerRotator();
        /**
        * Adds player into list
        */
        void Add(Player * player);
        /**
        * Rotates player and returns cur player
        * \return a Player pointer
        */
        Player * Next();
        /**
        * Returns next player, do not rotate
        * \return a Player pointer
        */
        Player * PeakNext();
    protected:
    private:
        std::vector<Player *> m_players; //!< Member variable "m_players"
        int m_curPlayer; //!< Member variable "m_curPlayer"
};
#endif // PLAYERROTATOR_H
