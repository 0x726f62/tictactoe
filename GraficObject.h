/**
* \file GraficObject.h
* \brief Header file represents abstract grafic object.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef GRAFICOBJECT_H
#define GRAFICOBJECT_H

#include <string>
#include "IUserInterface.h"
#include "Coordination.h"

/******************************************************************************/

/**
* \brief Abstract grafic object
*
*/
class GraficObject
{
    public:
        /** Destructor */
        virtual ~GraficObject();
        /** Access m_colour
         * \return The current value of m_colour
         */
        std::string Getcolour() { return m_colour; }
        /** Set m_colour
         * \param val New value to set
         */
        void Setcolour(const std::string & val) { m_colour = val; }
        /**
         * Draw the grafic object
         */
        virtual void Draw() const = 0;
        /** Set m_coor
         * \param coor New value to set
         */
        void SetCoor( const Coordination * coor ) { m_coor = coor; }
        /** Access m_coor
         * \return The current value of m_coor
         */
        const Coordination * GetCoor() const { return m_coor;}


    protected:
        /**
        * Creates instance of GraficObject
        * \param userInterface Pointer to grafic UI
        * \param coor Pointer to the Coordinate
        */
        GraficObject(IUserInterface * userInterface, const Coordination * coor);

        IUserInterface * m_userInterface; //!< Member variable "m_userInterface"
    private:
        const Coordination * m_coor; //!< Member variable "m_coor"
        std::string m_colour; //!< Member variable "m_colour"
};
#endif // GRAFICOBJECT_H
