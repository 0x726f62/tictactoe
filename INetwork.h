/**
* \file INetwork.h
* \brief Header file represents network interface.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef INETWORK_H
#define INETWORK_H

#include "Coordination.h"

/******************************************************************************/

/**
* \brief Network interface
*
*/
class INetwork
{
    public:
        /** Destructor */
        virtual ~INetwork();
        /**
        * Initialize network connection
        */
        virtual void init()=0;
        /**
        * Send Coordinate over network
        * \param coop Pointer to Coordinate
        */
        virtual void send( const Coordination * coop )=0;
        /**
        * Receive Coordinate from network
        * \return Pointer to the newly created Coordinate
        */
        virtual const Coordination * receive()=0;
        /**
        * Adds pointer to coordinate to the grafic and network buffer
        * \param coop Pointer to Coordinate
        */
        virtual void AddCoorToBuffer(const Coordination * coop)=0;
        /**
        * Flush all pointers in the buffer
        */
        virtual void FlushBuffer()=0;
    protected:
        /** Default constructor */
        INetwork();
    private:

};

#endif // INETWORK_H
