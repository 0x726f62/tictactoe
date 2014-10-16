/**
* \file UserInterfaceNcurse.cpp
* \brief Source file represents functionality of grafical library ncurse.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "UserInterfaceNcurse.h"

/******************************************************************************/

UserInterfaceNcurse::UserInterfaceNcurse() :
                    m_numItemsMsgList(0)
{
    //ctor
    //system("resize -s 50 80");
    main_win = initscr();
    cbreak();
    noecho();
}

/******************************************************************************/

UserInterfaceNcurse::~UserInterfaceNcurse()
{
    //dtor
    endwin();
}

/******************************************************************************/

void UserInterfaceNcurse::AddGrafObjToBuffer(const GraficObject * graficObj)
{
    m_buffer.push_back(graficObj);
}

/******************************************************************************/

const Coordination * UserInterfaceNcurse::GetDrawInput()
{
    int ch, x, y;
    const Coordination * coop;
    keypad(main_win, TRUE);

    getyx(main_win, y, x);

    while(1)
    {
        ch = getch();

        switch (ch)
        {
            case ' ':
                getyx(main_win, y, x);
                recalcCoorFromGrafic(x, y);
                coop = new Coordination(x, y);
                keypad(main_win, FALSE);
                return coop;
                break;
            case KEY_UP:
                if ( (y - THEIGHT) >= GRIDSTARTY + COORSHIFTY)
                {
                    y -= THEIGHT;
                    move(y,x);
                }
                break;
            case KEY_DOWN:
                if ( (y + THEIGHT) <= GRIDENDY - COORSHIFTY)
                {
                    y += THEIGHT;
                    move(y,x);
                }

            break;
            case KEY_LEFT:
                if ( (x - TWIDTH) >= GRIDSTARTX + COORSHIFTX)
                {
                    x-= TWIDTH;
                    move(y,x);
                }
                break;
            case KEY_RIGHT:
                if ( (x + TWIDTH) <= GRIDENDX - COORSHIFTX)
                {
                    x+= TWIDTH;
                    move(y,x);
                }
                break;
            default:
                break;

        }
        //refresh();
    }

    keypad(main_win, FALSE);

    return NULL;
}

/******************************************************************************/

void UserInterfaceNcurse::DrawBuffer()
{
    for(const GraficObject * it : m_buffer)
        it->Draw();

    m_buffer.clear();
}

/******************************************************************************/

void UserInterfaceNcurse::DrawBoard()
{
    int i, j;

    //clear();

    for(j = GRIDSTARTY; j <= GRIDENDY; j += THEIGHT)
            for(i = GRIDSTARTX; i <= GRIDENDX; ++i)
                    mvaddch(j, i, ACS_HLINE);

    for(i = GRIDSTARTX; i <= GRIDENDX; i += TWIDTH)
            for(j = GRIDSTARTY; j <= GRIDENDY; ++j)
                    mvaddch(j, i, ACS_VLINE);


    mvaddch(GRIDSTARTY, GRIDSTARTX, ACS_ULCORNER);
    mvaddch(GRIDENDY, GRIDSTARTX, ACS_LLCORNER);
    mvaddch(GRIDSTARTY, GRIDENDX, ACS_URCORNER);
    mvaddch(GRIDENDY, GRIDENDX, ACS_LRCORNER);

    for(j = GRIDSTARTY + THEIGHT; j <= GRIDENDY - THEIGHT; j += THEIGHT)
    {       mvaddch(j, GRIDSTARTX, ACS_LTEE);
            mvaddch(j, GRIDENDX, ACS_RTEE);
            for(i = GRIDSTARTX + TWIDTH; i <= GRIDENDX - TWIDTH; i += TWIDTH)
                    mvaddch(j, i, ACS_PLUS);
    }

    for(i = GRIDSTARTX + TWIDTH; i <= GRIDENDX - TWIDTH; i += TWIDTH)
    {       mvaddch(GRIDSTARTY, i, ACS_TTEE);
            mvaddch(GRIDENDY, i, ACS_BTEE);
    }

    move( GRIDSTARTY + COORSHIFTY,GRIDSTARTX + COORSHIFTX);

    refresh();

}

/******************************************************************************/

void UserInterfaceNcurse::DrawCross(const Coordination * coor)
{
    int y, coorY, x, coorX;

    coorX = coor->GetX();
    coorY = coor->GetY();
    getyx(main_win, y, x);
    recalcCoor2Grafic(coorX, coorY);
    mvaddch(coorY, coorX, 'X');
    move(y, x);
    refresh();
}

/******************************************************************************/

void UserInterfaceNcurse::DrawCircle(const Coordination * coor)
{
    int y, coorY, x, coorX;

    coorX = coor->GetX();
    coorY = coor->GetY();
    getyx(main_win, y, x);
    recalcCoor2Grafic(coorX, coorY);
    mvaddch(coorY, coorX, 'O');
    move(y, x);
    refresh();
}

/******************************************************************************/

void UserInterfaceNcurse::DrawMsg( const std::string & msg )
{
    int y, x;
    getyx(main_win, y, x);

    move(GRIDENDY + 2, 0);
    clrtoeol();
    mvaddstr(GRIDENDY + 2, 0, msg.c_str() );
    move(y, x);
    refresh();
}

/******************************************************************************/

void UserInterfaceNcurse::DrawMsg( int x, int y, const std::string & msg )
{
    int prevY, prevX;
    getyx(main_win, prevY, prevX);

    move(y, x);
    clrtoeol();
    mvaddstr(y, x, msg.c_str() );
    move(prevY, prevX);
    refresh();
}

/******************************************************************************/

void UserInterfaceNcurse::DrawInMsgList( const std::string & msg )
{
    int y, x, cnt;
    getyx(main_win, y, x);
    cnt = 0;

    if ( ++m_numItemsMsgList > NMSGS )
    {
        m_numItemsMsgList=NMSGS;
        m_msgs.pop_back();
    }

    m_msgs.insert( m_msgs.begin(), msg);

    for ( auto it : m_msgs )
    {
        cnt+=1;
        move(GRIDENDY + cnt, 3);
        clrtoeol();
        mvaddstr(GRIDENDY + cnt, 3, it.c_str() );

    }

    move(y, x);
    refresh();
}

/******************************************************************************/

void UserInterfaceNcurse::recalcCoorFromGrafic(int & x, int & y)
{
    x = ( GRIDSTARTX + x - COORSHIFTX ) / TWIDTH ;
    y = ( GRIDSTARTY + y - COORSHIFTY ) / THEIGHT ;
}

/******************************************************************************/



void UserInterfaceNcurse::recalcCoor2Grafic(int & x, int & y)
{
    x = ( x * TWIDTH ) - GRIDSTARTX + COORSHIFTX;
    y = ( y * THEIGHT ) - GRIDSTARTY + COORSHIFTY;
}
