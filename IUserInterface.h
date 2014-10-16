/**
* \file IUserInterface.h
* \brief Header file represents grafic interface.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

#include <string>
#include "Coordination.h"

class GraficObject;

/******************************************************************************/

/**
* \brief Grafic interface
*
*/
class IUserInterface
{
    public:
        /** Destructor */
        virtual ~IUserInterface();
        /**
        * Receive Coordinate from keybord
        * \return Pointer to the newly created Coordinate
        */
        virtual const Coordination * GetDrawInput() = 0;
        /**
        * Adds pointer to grafic object to the grafic or network buffer
        * \param graficObj Pointer to GraficObject
        */
        virtual void AddGrafObjToBuffer( const GraficObject * graficObj ) = 0;
        /**
        * Draw all items in the buffer
        */
        virtual void DrawBuffer() = 0;
        /**
        * Draw game grid
        */
        virtual void DrawBoard() = 0;
        /**
        * Draw grafic stone Cross
        * \param coor Pointer to Coordinate
        */
        virtual void DrawCross( const Coordination * coor ) = 0;
        /**
        * Draw grafic stone Circle
        * \param coor Pointer to Coordinate
        */
        virtual void DrawCircle( const Coordination * coor ) = 0;
        /**
        * Draw message under the grid
        */
        virtual void DrawMsg( const std::string & msg ) = 0;
        /**
        * Draw message on coordinate x,y
        * \param x Coordinate x
        * \param y Coordinate y
        * \param msg Text of the message
        */
        virtual void DrawMsg( int x, int y, const std::string & msg ) = 0;
        /**
        * Draw message on the list under grid
        * \param msg Text of the message
        */
        virtual void DrawInMsgList( const std::string & msg ) = 0;

    protected:
        /** Default constructor */
        IUserInterface();
    private:

};
#endif // IUSERINTERFACE_H
