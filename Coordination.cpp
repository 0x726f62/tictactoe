/**
* \file Coordination.cpp
* \brief Source file represents coordinates on the board.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "Coordination.h"

/******************************************************************************/

Coordination::Coordination() : m_X(0), m_Y(0)
{
    //ctor
}

/******************************************************************************/

Coordination::Coordination(int x, int y) : m_X(x), m_Y(y)
{

}

/******************************************************************************/

Coordination::~Coordination()
{
    //dtor
}

/******************************************************************************/

Coordination & Coordination::operator=(const Coordination & rhs)
{
    if ( this != &rhs)
    {
        SetX( rhs.GetX() );
        SetY( rhs.GetY() );
    }

    return *this;
}

