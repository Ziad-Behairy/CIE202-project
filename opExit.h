#pragma once
#include"operations/operation.h"
class opExit:public operation
{
public:
	opExit(controller* pcont);
	virtual ~ opExit();
	virtual void Execute();
;
};
