/**
* \file Cross.h
* \brief Header file represents stone cross.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef CROSS_H
#define CROSS_H

#include "Stone.h"

/******************************************************************************/

/**
* \brief Grafic object Cross
*
*/
class Cross : public Stone
{
    public:
        /**
        * Creates instance of Cross
        * \param userInterface Pointer to grafic UI
        * \param coor Pointer to the Coordinate
        * \param name String representation
        */
        Cross(IUserInterface * userInterface, const Coordination * coor, const std::string & name);
        /** Destructor */
        virtual ~Cross();
        /**
         * Draw the grafic object Cross
         */
        virtual void Draw() const;
    protected:
    private:
};

#endif // CROSS_H
