/**
* \file GameField.cpp
* \brief Source file represents grafic object board.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "GameField.h"

/******************************************************************************/

GameField::GameField(IUserInterface * userInterface,
                     Coordination * coor) :
                    GraficObject(userInterface, coor)
{
    //ctor
}

/******************************************************************************/

GameField::~GameField()
{
    //dtor
}

/******************************************************************************/

void GameField::Draw() const
{
    m_userInterface->DrawBoard();
}
