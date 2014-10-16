/**
* \file BoardData.h
* \brief Header file represents data layer for board coordinates.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef BOARDDATA_H
#define BOARDDATA_H

#include <vector>
#include "Coordination.h"

/******************************************************************************/

/**
* \brief Data layer game's board state.
*
* Contains data about game's board state.
*/
class BoardData
{
    public:
        /**
        * Creates instance of BoardData
        * \param rows Number of rows
        * \param cols Number of columns
        */
        BoardData(int rows, int cols);
        /** Destructor */
        virtual ~BoardData();
        /**
        * Adds Integer representation of Coordinate into game board data
        * \param coor Pointer to Coordinate
        * \param move Integer representation of Player
        */
        void AddMove(const Coordination * coor, int move);
        /**
        * Check of dupliced Coordinate
        * \param coor Pointer to Coordinate
        * \return If Coordinate already exists, returns true
        */
        bool CheckExistingCoor(const Coordination * coor) const;
        /**
        * Check of game is tied
        * \return If game is tied, returns true
        */
        bool IsTie() const;
        /**
        * Check if somebody won
        * \return If somebody won, returns true
        */
        bool IsWinner() const;
        /**
        * Adds Coordinate into game board data
        * \param coor Pointer to Coordinate
        */
        void AddCoor(const Coordination * coor);
        /** Access m_coors
         * \return The current value of m_coors
         */
        const std::vector<const Coordination *> & GetCoors() const { return m_coors; }
        /** Access m_field
         * \return The current value of m_field
         */
        const std::vector< std::vector<int> > & GetField() const { return m_field; }
        /** Set m_field[x][y]
         * \param x column
         * \param y row
         * \param move New value to set
         */
        void SetField(int x, int y, int move) { m_field[x][y]=move; }
        /** Access m_counterCoors
         * \return The current value of m_counterCoors
         */
        int GetCounterCoors() const { return m_counterCoors; }
        /** Set m_counterCoors
         * \param val New value to set
         */
        void SetCounterCoors( int val ) { m_counterCoors= val; }
        /** Access m_maxCoors
         * \return The current value of m_maxCoors
         */
        int GetMaxCoors() const { return m_maxCoors; }
        /** Set m_maxCoors
         * \param val New value to set
         */
        void SetMaxCoors( int val ) { m_maxCoors = val; }
    protected:
    private:
        std::vector<const Coordination *> m_coors; //!< Member variable "m_coors"
        std::vector< std::vector<int> > m_field; //!< Member variable "m_field"
        int m_counterCoors; //!< Member variable "m_counterCoors"
        int m_maxCoors; //!< Member variable "m_maxCoors"

};


#endif // BOARDDATA_H
