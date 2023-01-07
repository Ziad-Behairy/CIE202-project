#pragma once
#include"operations/operation.h"
class opmultiselection : public operation
{
public:
	opmultiselection(controller* pCont);
	virtual ~opmultiselection();
	virtual void Execute();
};

