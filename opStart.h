#pragma once
#include"operations/operation.h"
class opStart:public operation
{
public:
	opStart(controller* pCont);
	virtual ~opStart();
	void Execute();
	void Undo();
	void Redo();
};

