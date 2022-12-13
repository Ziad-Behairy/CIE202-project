#pragma once
#include"operations/operation.h"
class opExit:public operation
{
public:
	opExit(controller* pCont);
	virtual ~opExit(void);
	virtual void Execute();
};

