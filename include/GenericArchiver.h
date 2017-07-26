/*
 * GenericArchiver.h
 *
 *  Created on: 2 Jun 2017
 *      Author: pnikiel
 */

#ifndef GENERICARCHIVER_INCLUDE_ARCHIVER_H_
#define GENERICARCHIVER_INCLUDE_ARCHIVER_H_

#include <uastring.h>
#include <uanodeid.h>
#include <statuscode.h>

namespace GenericArchiver
{

class GenericArchiver
{
public:

    virtual ~GenericArchiver ();

    GenericArchiver * instance () { return s_instance; }

	void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, OpcUa_UInt32 value, UaStatus statusCode  );



protected:
    GenericArchiver () {}
	static GenericArchiver * s_instance;

private:

};


}


#endif /* GENERICARCHIVER_INCLUDE_ARCHIVER_H_ */
