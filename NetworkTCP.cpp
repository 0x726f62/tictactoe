/**
* \file NetworkTCP.cpp
* \brief Source file represents abstract network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "NetworkTCP.h"

/******************************************************************************/

NetworkTCP::NetworkTCP(const std::string & IP, const int port) :
                        m_IP(IP), m_port(port),
                        m_fd(-1)
{
    //ctor
}

/******************************************************************************/

NetworkTCP::~NetworkTCP()
{
    //dtor
}

/******************************************************************************/

void NetworkTCP::send( const Coordination * coop )
{
    char buffer[200];

    int l = snprintf ( buffer, sizeof ( buffer ), "%d;%d", coop->GetX(), coop->GetY() );

    write ( Getfd(), buffer, l );
}

/******************************************************************************/

const Coordination * NetworkTCP::receive()
{
    char buffer[200];
    int x, y;

    x = y = 0;
    memset (buffer,0,sizeof(buffer));
    int l = read ( Getfd(), buffer, sizeof ( buffer ));

    // nulova delka -> uzavreni spojeni klientem
    if ( ! l ) return NULL;

    sscanf (buffer,"%d;%d", &x, &y);
    return new Coordination(x, y);
}

/******************************************************************************/

void NetworkTCP::AddCoorToBuffer(const Coordination * coop)
{
    m_buffer.push_back(coop);
}

/******************************************************************************/

void NetworkTCP::FlushBuffer()
{
    for(const Coordination * it : m_buffer)
        send(it);

    m_buffer.clear();
}
