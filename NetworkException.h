/**
* \file NetworkException.h
* \brief Header file represents network exception.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#ifndef NETWORKEXCEPTION_H
#define NETWORKEXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

/******************************************************************************/

/**
* \brief Network exception
*
*/
class NetworkException : public std::exception
{
    public:
        /**
        * Creates instance of NetworkException
        * \param text Value for m_text
        */
        NetworkException(const std::string & text);
        /** Destructor */
        virtual ~NetworkException() throw();
        /**
        * writes details about exception
        * \return returns m_text
        */
        virtual const char* what() const throw();

    protected:
    private:
        const std::string m_text; //!< Member variable "m_text"
};

#endif // NETWORKEXCEPTION_H
