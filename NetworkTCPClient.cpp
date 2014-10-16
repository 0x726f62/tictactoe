/**
* \file NetworkTCPClient.cpp
* \brief Source file represents client's network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

/******************************************************************************/

#include "NetworkTCPClient.h"

/******************************************************************************/

NetworkTCPClient::NetworkTCPClient(const std::string & IP, const int port) :
                                    NetworkTCP(IP, port)
{
    //ctor
}

/******************************************************************************/

NetworkTCPClient::~NetworkTCPClient()
{
    //dtor
    if (Getfd() >= 0 ) close( Getfd() );
}

/******************************************************************************/

void NetworkTCPClient::init()
{
    //TODO
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
    /* Zadost o spojeni se serverem (ted se teprve zacne komunikovat).
    * vysledkem je bud otevrene datove spojeni nebo chyba.
    */
    if ( connect ( fd, ai -> ai_addr, ai -> ai_addrlen ) == - 1 )
    {
        close ( fd );
        freeaddrinfo ( ai );
        throw NetworkException("Failed connect\n");
    }

    freeaddrinfo ( ai );
    Setfd(fd);
}
