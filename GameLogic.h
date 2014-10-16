/**
* \file GameLogic.h
* \brief Header file represents business layer.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/


#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "BoardData.h"

/******************************************************************************/

/**
* Number of same stones in row to win
*/
#define NINROW 5

/******************************************************************************/

/**
* \brief Processing data
*
* Evaluates game's board data
*/
class GameLogic
{
    public:
        /**
        * Creates instance of GameLogic
        * \param rows value for m_rows
        * \param cols value for m_cols
        */
        GameLogic(int rows, int cols);
        /** Destructor */
        virtual ~GameLogic();
        /** Access m_rows
         * \return The current value of m_rows
         */
        int Getrows() const { return m_rows; }

        /** Access m_cols
         * \return The current value of m_cols
         */
        int Getcols() const { return m_cols; }
        /**
        * Check of dupliced Coordinate
        * \param coor Pointer to Coordinate
        * \return If Coordinate already exists, returns true
        */
        bool ValidateMove( const Coordination * coor) const;
        /**
        * Validate Coordinate
        * \param x Coordinate x
        * \param y Coordinate y
        * \return If Coordinate(x,y) is validated, returns true
        */
        bool CheckExistingXY(int x, int y) const;
        /**
        * Adds Integer representation of Coordinate into game board data
        * \param coor Pointer to Coordinate
        * \param move Integer representation of Player
        */
        void AddMove(const Coordination * coor, int move);
        /**
        * Check of game is tied
        * \return If game is tied, returns true
        */
        bool IsTie() const;
        /**
        * Check if somebody won
        * \return If somebody won, returns true
        */
        bool IsWinner(int playerID) const;
    protected:
    private:
        /**
        * Check if somebody has stones in row vertically
        * \param Player integer representation
        * \return If somebody has stones in row vertically, returns true
        */
        bool IsVerticalRow( int playerID ) const;
        /**
        * Check if somebody has stones in row horizontally
        * \param Player integer representation
        * \return If somebody has stones in row horizontally, returns true
        */
        bool IsHorizontalRow( int playerID ) const;
        /**
        * Check if somebody has stones in row diagonally right
        * \param Player integer representation
        * \return If somebody has stones in row diagonally right, returns true
        */
        bool IsDiagRightRow(int playerID) const;
        /**
        * Check if somebody has stones in row diagonally left
        * \param Player integer representation
        * \return If somebody has stones in row diagonally left, returns true
        */
        bool IsDiagLeftRow(int playerID) const;
        /**
        * Check of dupliced Coordinate
        * \param x Coordinate x
        * \param y Coordinate y
        * \return If Coordinate(x,y) already exists, returns true
        */
        bool CheckExistingCoor(const Coordination * coor) const;

        int m_rows; //!< Member variable "m_rows"
        int m_cols; //!< Member variable "m_cols"

        BoardData m_boardData; //!< Member variable "m_boardData"
};

#endif // GAMELOGIC_H
