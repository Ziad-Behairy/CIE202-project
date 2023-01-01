#pragma once
#include"operations/operation.h"
class opmove:public operation
{
public:
	opmove(controller* pcont);
	virtual ~ opmove();
	virtual void Execute();
};

