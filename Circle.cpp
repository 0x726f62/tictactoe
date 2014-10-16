/**
* \file Circle.cpp
* \brief Source file represents stone cirle.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "Circle.h"

/******************************************************************************/

Circle::Circle( IUserInterface * userInterface,
               Coordination * coor,
               const std::string & name) :
                Stone(userInterface, coor, name)
{
    //ctor
}

/******************************************************************************/

Circle::~Circle()
{
    //dtor
}

/******************************************************************************/

void Circle::Draw() const
{
    m_userInterface->DrawCircle( GetCoor() );
}
