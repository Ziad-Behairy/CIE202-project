#pragma once
#include"operations/operation.h"
class opRotate :public operation
{
public:
	opRotate(controller* pcont);
	~opRotate();
	virtual void Execute();
	void Undo() ;
	void Redo() ;
};
