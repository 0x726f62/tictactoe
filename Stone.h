/**
* \file Stone.h
* \brief Header file represents abstract grafical object stone.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef STONE_H
#define STONE_H

#include "GraficObject.h"

/******************************************************************************/

/**
* \brief Abstract grafic object stone
*
*/
class Stone : public GraficObject
{
    public:
        /** Destructor */
        virtual ~Stone();
        /**
        * Access m_name
        * \return value of m_name
        */
        virtual const std::string & ToString() const;
    protected:
        /**
        * Creates instance of Stone
        * \param userInterface Pointer to grafic UI
        * \param coor Pointer to the Coordinate
        * \param name String representation
        */
        Stone(IUserInterface * userInterface, const Coordination * coor, const std::string & name);
    private:
        const std::string m_name; //!< Member variable "m_name"
};

#endif // STONE_H
