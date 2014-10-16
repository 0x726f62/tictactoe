/**
* \file LocalPlayer.cpp
* \brief Source file represents abstract local player.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "LocalPlayer.h"

/******************************************************************************/

LocalPlayer::LocalPlayer(const std::string & name,
                         IUserInterface * userInterface,
                         GameLogic * gameLogic,
                         Stone * stone,
                         int val,
                         INetwork * networkInterface) :
                         Player(name, userInterface, gameLogic, stone, val, networkInterface)
{
    //ctor
}

/******************************************************************************/

LocalPlayer::~LocalPlayer()
{
    //dtor
}

/******************************************************************************/

void LocalPlayer::PrepareStone(const Coordination * coor)
{
    m_stone->SetCoor(coor);
    m_userInterface->AddGrafObjToBuffer(m_stone);
    if (m_networkInterface) m_networkInterface->AddCoorToBuffer(coor);
}

/******************************************************************************/

void LocalPlayer::Update()
{
    m_userInterface->DrawBuffer();
}
