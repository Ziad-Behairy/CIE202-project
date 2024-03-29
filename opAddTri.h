#pragma once

#include "operations/operation.h"

//Add Triangle operation class
class opAddTri : public operation
{
public:
	opAddTri(controller* pCont);
	virtual ~opAddTri();

	//Add rectangle to the controller
	virtual void Execute();
	void Undo() ;
	void Redo() ;

};
