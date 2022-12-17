
#pragma once

#include "operations/operation.h"

//Add Rectangle operation class
class opAddIrrpoly : public operation
{
public:
	opAddIrrpoly(controller* pCont);
	virtual ~opAddIrrpoly();

	//Add Irrpoly to the controller
	virtual void Execute();

};

