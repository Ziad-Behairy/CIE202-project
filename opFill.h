#pragma once
#include"operations/operation.h"
class opFill:public operation
{
public:
	opFill(controller* pcont);
	virtual void Execute();
	void Undo() ;
	void Redo() ;
};

