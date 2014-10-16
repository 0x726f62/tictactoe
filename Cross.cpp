/**
* \file Cross.cpp
* \brief Source file represents stone cross.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "Cross.h"

/******************************************************************************/

Cross::Cross(IUserInterface * userInterface,
             const Coordination * coor,
             const std::string & name) :
            Stone(userInterface, coor, name)
{
    //ctor
}

/******************************************************************************/

Cross::~Cross()
{
    //dtor
}

/******************************************************************************/

void Cross::Draw() const
{
    m_userInterface->DrawCross( GetCoor() );
}
