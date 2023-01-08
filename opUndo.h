#pragma once
#include "operations/operation.h"
class opUndo : public operation
{
public:
	opUndo(controller* pCont);
	virtual ~opUndo();
	virtual void Execute();
	void Undo();
	void Redo();

};