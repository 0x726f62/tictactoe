/**
* \file Coordination.h
* \brief Header file represents coordinates on the board.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef COORDINATION_H
#define COORDINATION_H

/******************************************************************************/

/**
* \brief Coordinate on the grafic board
*
*/
class Coordination
{
    public:
        /** Default constructor */
        Coordination();
        /** parametric constructor */
        Coordination(int x, int y);
        /** Default destructor */
        virtual ~Coordination();
        /** Assignment operator */
        Coordination & operator=(const Coordination & rhs);
        /** Access m_X
         * \return The current value of m_X
         */
        int GetX() const { return m_X; }
        /** Set m_X
         * \param val New value to set
         */
        void SetX(int val) { m_X = val; }
        /** Access m_Y
         * \return The current value of m_Y
         */
        int GetY() const { return m_Y; }
        /** Set m_Y
         * \param val New value to set
         */
        void SetY(int val) { m_Y = val; }
    protected:
    private:
        int m_X; //!< Member variable "m_X"
        int m_Y; //!< Member variable "m_Y"
};
#endif // COORDINATION_H
