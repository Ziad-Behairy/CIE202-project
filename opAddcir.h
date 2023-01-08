#pragma once
#include "operations/operation.h"
#include "Circle.h"

//Add Circle operation class
class opAddCir :public operation
{
protected:
	Circle* CirclePointer;
public:
	opAddCir(controller* pCont);
	virtual ~opAddCir();

	//Add Circle to the controller
	virtual void Execute();
	void Undo() ;
	void Redo() ;

};