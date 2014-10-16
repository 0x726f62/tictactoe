/**
* \file UserInterfaceNcurse.h
* \brief Header file represents functionality of grafical library ncurse.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef USERINTERFACENCURSE_H
#define USERINTERFACENCURSE_H

#include <stdlib.h>
#include <vector>
#include <ncurses.h>
#include "IUserInterface.h"
#include "Coordination.h"
#include "GraficObject.h"

/******************************************************************************/

/**
* Grid's left upper corner y coordinate
*/
#define GRIDSTARTY 0

/**
* Grid's left upper corner x coordinate
*/
#define GRIDSTARTX 0

/**
* Number of grid's rows
*/
#define NLINES 10

/**
* Number of grid's columns
*/
#define NCOLS 10

/**
* Width of the single cell
*/
#define TWIDTH 4

/**
* Height of the single cell
*/
#define THEIGHT 2

/**
* Coordinate y shift
*/
#define COORSHIFTY 1

/**
* Coordinate x shift
*/
#define COORSHIFTX 2

/**
* Grid's right lower corner y coordinate
*/
#define GRIDENDY GRIDSTARTY + ( NLINES * THEIGHT )

/**
* Grid's right lower corner x coordinate
*/
#define GRIDENDX GRIDSTARTX + ( NCOLS * TWIDTH )

/**
* Number of messages displayed in the terminal
*/
#define NMSGS 5

/******************************************************************************/

/**
* \brief Use if grafical library ncurse
*
* Implements grafic interface IUserInterface
* Painting grafic objects/ASCII text on terminal
*/
class UserInterfaceNcurse : public IUserInterface
{
    public:
        /** Default constructor */
        UserInterfaceNcurse();
        /** Destructor */
        virtual ~UserInterfaceNcurse();
        /**
        * Receive Coordinate from keybord
        * \return Pointer to the newly created Coordinate
        */
        virtual const Coordination * GetDrawInput();
        /**
        * Adds pointer to grafic object to the grafic or network buffer
        * \param graficObj Pointer to GraficObject
        */
        virtual void AddGrafObjToBuffer(const GraficObject * graficObj);
        /**
        * Draw all items in the buffer
        */
        virtual void DrawBuffer();
        /**
        * Draw game grid
        */
        virtual void DrawBoard();
        /**
        * Draw grafic stone Cross
        * \param coor Pointer to Coordinate
        */
        virtual void DrawCross(const Coordination * coor);
        /**
        * Draw grafic stone Circle
        * \param coor Pointer to Coordinate
        */
        virtual void DrawCircle(const Coordination * coor);
        /**
        * Draw message under the grid
        */
        virtual void DrawMsg( const std::string & msg );
        /**
        * Draw message on coordinate x,y
        * \param x Coordinate x
        * \param y Coordinate y
        * \param msg Text of the message
        */
        virtual void DrawMsg( int x, int y, const std::string & msg );
        /**
        * Draw message on the list under grid
        * \param msg Text of the message
        */
        virtual void DrawInMsgList( const std::string & msg );
    protected:
    private:
        /**
        * Recalculate coordinate x,y from grafic
        * \param x Coordinate x
        * \param y Coordinate y
        */
        void recalcCoorFromGrafic(int & x, int & y);
        /**
        * Recalculate coordinate x,y to Grafic
        * \param x Coordinate x
        * \param y Coordinate y
        */
        void recalcCoor2Grafic(int & x, int & y);

        std::vector<const GraficObject *> m_buffer; //!< Member variable "m_graficObjects"
        std::vector<std::string> m_msgs; //!< Member variable "m_msgs"
        int m_numItemsMsgList; //!< Member variable "m_numItemsMsgList"
        WINDOW * main_win; //!< Member variable "main_win"
};
#endif // USERINTERFACENCURSE_H
