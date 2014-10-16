/**
* \file NetworkTCP.h
* \brief Header file represents abstract network TCP functionality.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef NETWORKTCP_H
#define NETWORKTCP_H

#include "INetwork.h"
#include <string>
#include <unistd.h>
#include <vector>

#include <stdio.h>
#include <string.h>

/******************************************************************************/

/**
* \brief Abstract network TCP functionality
*
* Contains implementation of basic input/output on OSI trasportation layer
*/
class NetworkTCP : public INetwork
{
    public:
        /** Destructor */
        virtual ~NetworkTCP();
        /** Access m_IP
         * \return The current value of m_IP
         */
        const std::string & GetIP() { return m_IP; }
        /** Access m_port
         * \return The current value of m_port
         */
        int Getport() { return m_port; }
        /** Access m_fd
         * \return The current value of m_fd
         */
        int Getfd() { return m_fd; }
        /** Set m_name
         * \param val New value to set
         */
        void Setfd(int val) { m_fd = val; }
        /**
        * Send Coordinate over network
        * \param coop Pointer to Coordinate
        */
        virtual void send( const Coordination * coop );
        /**
        * Receive Coordinate from network
        * \return Pointer to the newly created Coordinate
        */
        virtual const Coordination * receive();
        /**
        * Adds pointer to coordinate to the grafic and network buffer
        * \param coop Pointer to Coordinate
        */
        virtual void AddCoorToBuffer(const Coordination * coop);
        /**
        * Flush all pointers in the buffer
        */
        virtual void FlushBuffer();
    protected:
        /**
        * Creates instance of NetworkTCP
        * \param IP IP address
        * \param port port number
        */
        NetworkTCP(const std::string & IP, const int port);
    private:
        const std::string m_IP; //!< Member variable "m_IP"
        const int m_port; //!< Member variable "m_port"
        int m_fd; //!< Member variable "m_fd"
        std::vector<const Coordination *> m_buffer; //!< Member variable "m_buffer"
};

#endif // NETWORKTCP_H
