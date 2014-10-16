/**
* \file PlayerRotator.cpp
* \brief Source file represents functionality for changing turns.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "PlayerRotator.h"

/******************************************************************************/

PlayerRotator::PlayerRotator() : m_curPlayer(0)
{
    //ctor
}

/******************************************************************************/

PlayerRotator::~PlayerRotator()
{
    //dtor
    for ( Player * player :  m_players )
        delete player;

}

/******************************************************************************/

void PlayerRotator::Add(Player * player)
{
    m_players.push_back(player);
}

/******************************************************************************/

Player * PlayerRotator::Next()
{
    if (m_players.size()==0) return NULL;
    m_curPlayer = ( m_curPlayer + 1 ) % m_players.size();
    return m_players[m_curPlayer];
}

/******************************************************************************/

Player * PlayerRotator::PeakNext()
{
    if (m_players.size()==0) return NULL;
    return m_players[( m_curPlayer + 1 ) % m_players.size()];
}
