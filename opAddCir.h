#pragma once
#include "operations/operation.h"

//Add Circle operation class
class opAddCir:public operation
{
public:
	opAddCir(controller* pCont);
	virtual ~opAddCir();

	//Add Circle to the controller
	virtual void Execute();

};