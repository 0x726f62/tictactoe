/**
* \file BoardData.cpp
* \brief Source file represents data layer for board coordinates.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "BoardData.h"

/******************************************************************************/

BoardData::BoardData(int rows, int cols) :
            m_field(cols, std::vector<int>(rows,0))
{
    //ctor
    m_counterCoors = 0;
    m_maxCoors = rows * cols;
}

/******************************************************************************/

BoardData::~BoardData()
{
    //dtor
    for(const Coordination * it : m_coors)
        delete it;
}

void BoardData::AddCoor(const Coordination * coor)
{
    m_coors.push_back(coor);
}
