/**
* \file NetworkTCPClient.h
* \brief Header file represents client's network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef NETWORKTCPCLIENT_H
#define NETWORKTCPCLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>

#include "NetworkTCP.h"
#include "NetworkException.h"

/******************************************************************************/

/**
* \brief Network TCP functionality for client
*
*/
class NetworkTCPClient : public NetworkTCP
{
    public:
        /**
        * Creates instance of NetworkTCPClient
        * \param IP IP address
        * \param port port number
        */
        NetworkTCPClient(const std::string & IP, const int port);
        /** Destructor */
        virtual ~NetworkTCPClient();
        /**
        * Initialize network connection for client
        */
        virtual void init();
    protected:
    private:
};

#endif // NETWORKTCPCLIENT_H
