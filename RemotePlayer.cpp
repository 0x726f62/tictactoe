/**
* \file RemotePlayer.cpp
* \brief Source file represents remote player functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "RemotePlayer.h"

/******************************************************************************/

RemotePlayer::RemotePlayer(const std::string & name,
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

RemotePlayer::~RemotePlayer()
{
    //dtor
}

/******************************************************************************/

const Coordination * RemotePlayer::ReceiveAndValidInput()
{
    m_userInterface->DrawInMsgList(std::string("Remote player ") + m_name + " moving " + "with stone " + m_stone->ToString());
    return m_networkInterface->receive();
}

/******************************************************************************/

void RemotePlayer::PrepareStone(const Coordination * coor)
{
    m_stone->SetCoor(coor);
    m_userInterface->AddGrafObjToBuffer(m_stone);
}

/******************************************************************************/

void RemotePlayer::Update()
{
    m_userInterface->DrawBuffer();
    m_networkInterface->FlushBuffer();
}
