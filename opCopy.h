#pragma once
#include"operations/operation.h"
class opCopy :public operation
{
public:
	opCopy(controller* pcont);
	~opCopy();
	virtual void Execute();
	void Undo() ;
	void Redo() ;
};
