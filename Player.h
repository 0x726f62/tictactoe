/**
* \file Player.h
* \brief Header file represents abstract player.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "IUserInterface.h"
#include "INetwork.h"
#include "GameLogic.h"
#include "Stone.h"
#include "Coordination.h"

/******************************************************************************/

/**
* \brief Abstract Player
*
* Contains grafical and network interaces and has access to board data and logic
*/
class Player
{
    public:
        /** Destructor */
        virtual ~Player();
        /** Access m_name
         * \return The current value of m_name
         */
        std::string Getname() { return m_name; }
        /** Set m_name
         * \param val New value to set
         */
        void Setname(const std::string & val) { m_name = val; }
        /** Access m_intRep
         * \return The current value of m_intRep
         */
        int GetIntRep() const { return m_intRep; }
        /**
         * Store Coordinate into BoardData
         */
        void StoreMove( const Coordination * coor);

        /**
         * Print new data into terminal or sends thme over network
         */
        virtual void Update() = 0;
        /**
         * Receive Coordinate from the player
         * \return Pointer to the received Coordinate
         */
        virtual const Coordination * ReceiveAndValidInput() = 0;
        /**
         * Set Coordinate for the Stone
         * \param coor Pointer to the received Coordinate
         */
        virtual void PrepareStone(const Coordination * coor) = 0;
        /**
         * Check if the player has won
         * \return True if Player has won
         */
        virtual bool HasWon();
        /**
         * Check if the players has tied the game
         * \return True if thegame is tied
         */
        virtual bool HasTied();


    protected:
        /**
        * Creates instance of Player
        * \param name Name for the player
        * \param userInterface Pointer to grafic UI
        * \param gameLogic Pointer to GameLogic object
        * \param stone Game Pointer to object Stone
        * \param val Integer representation of player
        * \param networkInterface Pointer to network UI
        */
        Player( const std::string & name,
                IUserInterface * userInterface,
                GameLogic * gameLogic,
                Stone * stone,
                int val,
                INetwork * networkInterface);

        std::string m_name; //!< Member variable "m_name"
        IUserInterface * m_userInterface; //!< Member variable "m_userInterface"
        GameLogic * m_gameLogic; //!< Member variable "m_gameLogic"
        Stone * m_stone; //!< Member variable "m_stone"
        int m_intRep; //!< Member variable "m_intRep"
        INetwork * m_networkInterface; //!< Member variable "m_networkInterface"
};

#endif // PLAYER_H
