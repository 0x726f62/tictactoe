/**
* \file Player.cpp
* \brief Source file represents abstract player.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "Player.h"

/******************************************************************************/

Player::Player( const std::string & name,
                IUserInterface * userInterface,
                GameLogic * gameLogic,
                Stone * stone,
                int val,
                INetwork * networkInterface) :
                m_name(name),
                m_userInterface(userInterface),
                m_gameLogic(gameLogic),
                m_stone(stone),
                m_intRep(val),
                m_networkInterface(networkInterface)
{
    //ctor
}

/******************************************************************************/

Player::~Player()
{
    //dtor
}

/******************************************************************************/

void Player::StoreMove( const Coordination * coor )
{
    m_gameLogic->AddMove(coor, m_intRep);
}

/******************************************************************************/

bool Player::HasWon()
{
    if ( ! m_gameLogic->IsWinner( m_intRep ) ) return false;
    m_userInterface->DrawInMsgList(std::string("Player ") + m_name + " with stone " + m_stone->ToString() + " HAS WON!");
    return true;
}

/******************************************************************************/

bool Player::HasTied()
{
    if (! m_gameLogic->IsTie()) return false;
    m_userInterface->DrawInMsgList(std::string("Game is tied ... ") );
    return true;
}
