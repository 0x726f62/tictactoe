/**
* \file GraficObject.cpp
* \brief Source file represents abstract grafic object.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "GraficObject.h"

/******************************************************************************/

GraficObject::GraficObject(IUserInterface * userInterface,
                           const Coordination * coor) :
                            m_userInterface(userInterface),
                            m_coor(coor)
{
    //ctor
    Setcolour("NotSet");
}

/******************************************************************************/

GraficObject::~GraficObject()
{
    //dtor
}
