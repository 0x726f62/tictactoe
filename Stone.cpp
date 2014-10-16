/**
* \file Stone.cpp
* \brief Source file represents abstract grafical object stone.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "Stone.h"

/******************************************************************************/

Stone::Stone(IUserInterface * userInterface, const Coordination * coor, const std::string & name) :
                GraficObject(userInterface, coor),
                m_name(name)
{
    //ctor
}

/******************************************************************************/

Stone::~Stone()
{
    //dtor
}

/******************************************************************************/

const std::string & Stone::ToString() const
{
    return m_name;
}
