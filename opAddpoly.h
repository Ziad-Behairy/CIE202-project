#pragma once
#include "operations/operation.h"

//Add Polygon operation class
class opAddpoly : public operation
{
public:
	opAddpoly(controller* pCont);
	virtual ~opAddpoly();

	//Add Irrpoly to the controller
	virtual void Execute();

};

