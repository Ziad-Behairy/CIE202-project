#pragma once

#include"operations/operation.h"
class opborder: public operation
{
public:
	opborder(controller* pCont);
	virtual void Execute();
};

