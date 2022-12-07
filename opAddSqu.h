#pragma once
#include "operations/operation.h"
//Add Square operation class
class opAddSqu :public operation
{
public:
	opAddSqu(controller* pCont);
	virtual ~opAddSqu();

	//Add rectangle to the controller
	virtual void Execute();
};

