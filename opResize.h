#pragma once
#include"operations/operation.h"
class opResize :public operation
{
public:
	opResize(controller* pcont);
	~opResize();
	virtual void Execute();
};
