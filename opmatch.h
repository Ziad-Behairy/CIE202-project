#pragma once
#include"operations/operation.h"
class opmatch:public operation
{
public:
	opmatch(controller* pcont);
	virtual ~opmatch();
	void Execute();
};

