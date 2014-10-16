/**
* \file NetworkException.cpp
* \brief Source file represents network exception.
*
* \author Robert Jakes <jakesrob@fit.cvut.cz>
* \version 1.0
*/

#include "NetworkException.h"

NetworkException::NetworkException(const std::string & text) :
                                    m_text(text)
{
    //ctor
}

NetworkException::~NetworkException() throw()
{
    //dtor
}

const char * NetworkException::what() const throw()
{
    return m_text.c_str();
}
