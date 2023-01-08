#pragma once

#include"operations/operation.h"

//Add select operation class
class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();

	//Add select to the controller
	virtual void Execute();
	void Undo() ;
	void Redo() ;


};

