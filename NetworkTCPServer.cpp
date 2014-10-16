/**
* \file NetworkTCPServer.cpp
* \brief Source file represents server's network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#include "NetworkTCPServer.h"

NetworkTCPServer::NetworkTCPServer(const std::string & IP, const int port) :
                                    NetworkTCP(IP, port),
                                    m_serverFd(-1)
{
    //ctor
}

NetworkTCPServer::~NetworkTCPServer()
{
    //dtor
    if (GetserverFd() >= 0 ) close( GetserverFd() );
    if (Getfd() >= 0 ) close( Getfd() );
}

void NetworkTCPServer::init()
{
    struct sockaddr remote;
    socklen_t remoteLen = sizeof ( remote );
    struct addrinfo * ai;
    char portStr[10];

    /* Adresa, kde server posloucha. Podle name se urci typ adresy
    * (IPv4/6) a jeji binarni podoba
    */
    snprintf ( portStr, sizeof ( portStr ), "%d", Getport() );
    if ( getaddrinfo ( GetIP().c_str() , portStr, NULL, &ai ) )
    {
        throw NetworkException("Failed addrinfo\n");
    }

    /* Otevreni soketu, typ soketu (family) podle navratove hodnoty getaddrinfo,
    * stream = TCP
    */
    int fd = socket ( ai -> ai_family, SOCK_STREAM, 0 );
    if ( fd == -1 )
    {
        freeaddrinfo ( ai );
        throw NetworkException("Failed socket\n");
    }

    /* napojeni soketu na zadane sitove rozhrani
    */
    if ( bind ( fd, ai -> ai_addr, ai -> ai_addrlen ) == -1 )
    {
        close ( fd );
        freeaddrinfo ( ai );
        throw NetworkException("Failed bind\n");
    }

    freeaddrinfo ( ai );
    /* prepnuti soketu na rezim naslouchani (tedy tento soket nebude vyrizovat
    * datovou komunikaci, budou po nem pouze chodit pozadavky na pripojeni.
    * 10 je max velikost fronty cekajicich pozadavku na pripojeni.
    */

    if ( listen ( fd, 10 ) == -1 )
    {
        close ( fd );
        throw NetworkException("Failed listen\n");
    }

    SetserverFd(fd);
    //TODO Display wating on host!

    Setfd( accept ( GetserverFd(), &remote, &remoteLen ) );
    //New connection
}
