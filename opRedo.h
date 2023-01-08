#pragma once
#include "operations/operation.h"
class opRedo : public operation
{
public:
	opRedo(controller* pCont);
	virtual ~opRedo();
	virtual void Execute();
	void Undo();
	void Redo();

};

