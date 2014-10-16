/**
* \file GameField.h
* \brief Header file represents grafic object board.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "GraficObject.h"

/******************************************************************************/

/**
* \brief Grafic object GameField
*
* Represents painted grid on the screen
*/
class GameField : public GraficObject
{
    public:
        /** Default constructor */
        GameField(IUserInterface * userInterface, Coordination * coor);
        /** Default destructor */
        virtual ~GameField();
        virtual void Draw() const;
    protected:
    private:
};
#endif // GAMEFIELD_H
