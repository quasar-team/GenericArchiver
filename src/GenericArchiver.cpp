/*
 * GenericArchiver.cpp
 *
 *  Created on: 26 Jul 2017
 *      Author: pnikiel
 */

#include <GenericArchiver.h>


namespace GenericArchiver
{

    GenericArchiver* GenericArchiver::s_instance = 0;

    GenericArchiver* GenericArchiver::instance()
    {
        if (s_instance == 0)
        {
            throw std::logic_error("You enabled archiving in your Design, but haven't created an object of archiver implementation (like InfluxDbArchiver, or another...). It's a logic error in your software. Can't continue. ");
            return 0; // we'll never reach here, but we avoid the warning
        }
        else
            return s_instance;
    }
}


