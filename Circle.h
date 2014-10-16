/**
* \file Circle.h
* \brief Header file represents stone cirle.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Stone.h"

/******************************************************************************/

/**
* \brief Grafic object Circle
*
*/
class Circle : public Stone
{
    public:
        /**
        * Creates instance of Circle
        * \param userInterface Pointer to grafic UI
        * \param coor Pointer to the Coordinate
        * \param name String representation
        */
        Circle(IUserInterface * userInterface, Coordination * coor, const std::string & name);
        /** Destructor */
        virtual ~Circle();
        /**
         * Draw the grafic object Circle
         */
        virtual void Draw() const;
    protected:
    private:
};

#endif // CIRCLE_H
