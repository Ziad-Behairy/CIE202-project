#pragma once
#include"operations/operation.h"
class opMove :public operation
{
public:
	opMove(controller* pCont);
	virtual ~opMove();
	void Execute();
	void Undo();
	void Redo();
};