#pragma once
#include "operations/operation.h"
class opduplicate:public operation
{
public:
	opduplicate(controller* pcont);
	virtual ~opduplicate();
	virtual void Execute();
};

