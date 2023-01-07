#pragma once
#include"operations/operation.h"
class opPaste :public operation
{
public:
	opPaste(controller* pcont);
	~opPaste();
	virtual void Execute();
};
