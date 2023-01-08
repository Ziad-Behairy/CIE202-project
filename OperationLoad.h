#pragma once
#include"operations/operation.h"
#include"controller.h"
class OperationLoad:public operation
{
public:
	OperationLoad(controller* pcont);
	virtual ~OperationLoad();
	void Execute();
	void Undo() ;
	void Redo() ;
};

