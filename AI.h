/**
* \file AI.h
* \brief Header file represents AI functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef AI_H
#define AI_H

#include <cstdlib>
#include "LocalPlayer.h"

/******************************************************************************/

/**
* \brief An artificial intelligence.
*
* Computes turns according to game's board state.
*/
class AI : public LocalPlayer
{
    public:
        /**
        * Creates instance of AI
        * \param name Name for the AI
        * \param userInterface Pointer to grafic UI
        * \param gameLogic Pointer to GameLogic object
        * \param stone Game Pointer to object Stone
        * \param val Integer representation of AI
        * \param networkInterface Pointer to network UI
        */
        AI( const std::string & name,
            IUserInterface * userInterface,
            GameLogic * gameLogic,
            Stone * stone,
            int val,
            INetwork * networkInterface);
        /** Default destructor */
        virtual ~AI();
        /**
         * Compute Coordinate
         * \return Pointer to the computed Coordinate
         */
        virtual const Coordination * ReceiveAndValidInput();
    protected:
    private:
        /**
        * Compute Coordinate
        * \return pointer to Compute Coordinate
        */
        const Coordination * ComputeMove();
};

#endif // AI_H
