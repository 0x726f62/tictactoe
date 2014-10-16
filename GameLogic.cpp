/**
* \file GameLogic.cpp
* \brief Source file represents business layer.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "GameLogic.h"

/******************************************************************************/

GameLogic::GameLogic(int rows, int cols) :
                    m_rows(rows),
                    m_cols(cols),
                    m_boardData(rows, cols)
{
    //ctor

}

/******************************************************************************/

GameLogic::~GameLogic()
{
    //dtor
}

/******************************************************************************/

bool GameLogic::ValidateMove( const Coordination * coor) const
{
    return (! CheckExistingCoor(coor));
}

/******************************************************************************/

void GameLogic::AddMove(const Coordination * coor, int move)
{
    m_boardData.AddCoor(coor);
    m_boardData.SetField( coor->GetX(), coor->GetY(), move);
    m_boardData.SetCounterCoors(m_boardData.GetCounterCoors() + 1);
}

/******************************************************************************/

bool GameLogic::CheckExistingCoor(const Coordination * coor) const
{
    /*
    for(const Coordination * it : m_boardData.GetCoors())
            if ( (x == it->GetX()) && (y == it->GetY()) ) return true;

    return false;
    */

    return CheckExistingXY(coor->GetX(), coor->GetY());
}

/******************************************************************************/

bool GameLogic::CheckExistingXY(int x, int y) const
{
    if ( m_boardData.GetField()[x][y] != 0 ) return true;

    return false;
}

/******************************************************************************/

bool GameLogic::IsTie() const
{
    return (m_boardData.GetCounterCoors() >= m_boardData.GetMaxCoors());
}

/******************************************************************************/

bool GameLogic::IsHorizontalRow( int playerID ) const
{
    int row, col, cnt;

    for(row=0; row<Getrows(); ++row)
    {
        cnt=0;
        for(col=0; col<Getcols(); ++col)
        {
            if( m_boardData.GetField()[col][row] == playerID)
            {
                ++cnt;
                if( cnt >= NINROW ) return true;
            } else
            {
                cnt=0;
                if ( col+NINROW >= Getcols()) break;
            }
        }
    }

    return false;
}

/******************************************************************************/

bool GameLogic::IsDiagRightRow(int playerID) const
{

    int row, col, cnt;

    for(col=0;col<Getcols();++col)
    {
        if(col> Getcols() - NINROW) break;
        cnt=0;
        for(row=0;row<Getrows()-col;++row)
        {
            if(m_boardData.GetField()[col+row][row] == playerID)
            {
                if(++cnt >= NINROW) return true;
            } else
            {
                cnt = 0;
                if(row>(Getrows()-col-NINROW)){ break;}
            }
        }
    }

    //druha pul
    for(row=1;row<Getrows(); ++row)
    {
        if(row> Getrows() - NINROW) break;
        cnt=0;
        for(col=0;col<Getcols()-row; ++col )
        {
            if(m_boardData.GetField()[col][row+col] == playerID)
            {
                if(++cnt >= NINROW) return true;
            } else
            {
                cnt = 0;
                if(col>(Getcols()-row-NINROW)) break;
            }
        }
    }

    return false;
}

/******************************************************************************/

bool GameLogic::IsDiagLeftRow(int playerID) const
{
    //TODO
    int row, col, cnt;

    for(col=Getcols()-1;col>=0;--col)
    {
        //     4 < (5 - 1)
        if(col < ( NINROW-1) ) break;

        cnt=0;
                            //pro 1. pruchod musi by podminka row < getRows()
        for(row=0;row < Getrows() - (Getcols()-(col+1));++row)
        {
            if(m_boardData.GetField()[col - row][row] == playerID)
            {
                if(++cnt >= NINROW) return true;
            } else
            {
                cnt = 0;
                if(row>( Getrows() - (Getcols()-(col+1)) - NINROW ) ){ break;}
            }
        }
    }

    //TODO CHECK

    for(col=Getcols()-1;col>=0;--col)
    {
        //     4 < (5 - 1)
        if(col < ( NINROW-1) ) break;

        cnt=0;
                            //pro 1. pruchod musi by podminka row < getRows()
        for(row=0;row < Getrows() - col;++row)
        {
            if(m_boardData.GetField()[Getcols()- (row+1)][ col + row] == playerID)
            {
                if(++cnt >= NINROW) return true;
            } else
            {
                cnt = 0;
                //if(row>( Getcols() - (Getrows()-(col+1)) - NINROW ) ){ break;}
            }
        }
    }
   /*
    for(col=Getcols()-1;col>=0;--col)
    {
        // 4 < (5 - 1)
        if(col < ( NINROW-1) ) break;

        cnt=0;
        //pro 1. pruchod musi by podminka row < getRows()
        for(row=0;row < Getrows() - (Getcols() - (col+1));++row)
        {

            if(m_boardData.GetFied()[Getcols()- (row+1)][ col + row] == playerID)
            {
                if(++cnt >= NINROW) return true;
            } else
            {
                cnt = 0;
                if( (row> Getrows() - NINROW) ) {break;}
            }
        }
    }
    */

    return false;
}

/******************************************************************************/

bool GameLogic::IsVerticalRow( int playerID ) const
{

    int row, col, cnt;

    for(col=0; col<Getcols(); ++col)
    {
        cnt=0;
        for(row=0; row<Getrows(); ++row)
        {
            if( m_boardData.GetField()[col][row] == playerID)
            {
                ++cnt;
                if( cnt >= NINROW ) return true;
            } else
            {
                cnt=0;
                if ( row+NINROW >= Getrows()) break;
            }
        }
    }

    return false;
}

/******************************************************************************/

bool GameLogic::IsWinner( int playerID ) const
{

    if (IsVerticalRow(playerID)) return true;
    if (IsHorizontalRow(playerID)) return true;
    if (IsDiagLeftRow(playerID)) return true;
    if (IsDiagRightRow(playerID)) return true;

    return false;
}

