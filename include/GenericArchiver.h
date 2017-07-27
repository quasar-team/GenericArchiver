/*
 * GenericArchiver.h
 *
 *  Created on: 2 Jun 2017
 *      Author: pnikiel
 */

#ifndef GENERICARCHIVER_INCLUDE_ARCHIVER_H_
#define GENERICARCHIVER_INCLUDE_ARCHIVER_H_

#include <uabase.h>
#include <uanodeid.h>
#include <statuscode.h>

namespace GenericArchiver
{

class GenericArchiver
{
public:

    virtual ~GenericArchiver () {}

    static GenericArchiver * instance ();

	virtual void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, OpcUa_UInt32 value, UaStatus statusCode  ) = 0;
    virtual void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, const UaString& value, UaStatus statusCode  ) = 0;
    virtual void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, OpcUa_Float, UaStatus statusCode  ) = 0;
    virtual void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, OpcUa_Double, UaStatus statusCode  ) = 0;
	virtual void kill () = 0;



protected:
    GenericArchiver () {}
	static GenericArchiver * s_instance;

private:

};


}


#endif /* GENERICARCHIVER_INCLUDE_ARCHIVER_H_ */
