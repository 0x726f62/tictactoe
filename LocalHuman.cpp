/**
* \file LocalHuman.cpp
* \brief Source file represents local player functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "LocalHuman.h"

/******************************************************************************/

LocalHuman::LocalHuman( const std::string & name,
                        IUserInterface * userInterface,
                        GameLogic * gameLogic,
                        Stone * stone,
                        int val,
                        INetwork * networkInterface) :
                        LocalPlayer(name, userInterface, gameLogic, stone, val, networkInterface)
{
    //ctor
}

/******************************************************************************/

LocalHuman::~LocalHuman()
{
    //dtor
}

/******************************************************************************/

const Coordination * LocalHuman::ReceiveAndValidInput()
{
     const Coordination * coop;

     m_userInterface->DrawInMsgList(std::string("Local player ") + m_name + " moving " + "with stone " + m_stone->ToString());
     while (1)
     {
        coop = m_userInterface->GetDrawInput();
        if ( m_gameLogic->ValidateMove(coop) ) return coop;

        if (coop) delete coop;
        coop = NULL;
     }

     return NULL;
}
