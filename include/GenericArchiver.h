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

class UaVariant;

// forward-decls
namespace OpcUa { class BaseVariableType; }

namespace GenericArchiver
{

class GenericArchiver
{
public:

    virtual ~GenericArchiver () {}

    static GenericArchiver * instance ();

    virtual void archiveAssignment ( const UaNodeId& objectAddress, const UaNodeId& variableAddress, const std::string& variableName, const UaVariant& value, UaStatus statusCode  ) = 0;

    virtual UaStatus retrieveAssignment (
            OpcUa::BaseVariableType*  variable,
            OpcUa_DateTime            timeFrom,
            OpcUa_DateTime            timeTo,
            unsigned int              maxValues,
            UaDataValues&             output ) = 0;


	virtual void kill () = 0;





protected:
    GenericArchiver () {}
	static GenericArchiver * s_instance;

private:

};


}


#endif /* GENERICARCHIVER_INCLUDE_ARCHIVER_H_ */
