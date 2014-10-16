/**
* \file NetworkTCPServer.h
* \brief Header file represents server's network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef NETWORKTCPSERVER_H
#define NETWORKTCPSERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdio.h>

#include "NetworkTCP.h"
#include "NetworkException.h"

/******************************************************************************/

/**
* \brief Network TCP functionality for server
*
*/
class NetworkTCPServer : public NetworkTCP
{
    public:
        /**
        * Creates instance of NetworkTCPServer
        * \param IP IP address
        * \param port port number
        */
        NetworkTCPServer(const std::string & IP, const int port);
        /** Default destructor */
        virtual ~NetworkTCPServer();
        /** Access m_serverFd
         * \return The current value of m_serverFd
         */
        int GetserverFd() { return m_serverFd; }
        /** Set m_serverFd
         * \param val New value to set
         */
        void SetserverFd(int val) { m_serverFd = val; }
        /**
        * Initialize network connection for server
        */
        virtual void init();
    protected:
    private:
        int m_serverFd; //!< Member variable "m_serverFd"
};

#endif // NETWORKTCPSERVER_H
