#pragma once
#include "operations/operation.h"

//Add Rectangle operation class
class opUnhide: public operation
{
public:
	opUnhide(controller* pCont);
	virtual ~opUnhide();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo();
	void Redo();

};

