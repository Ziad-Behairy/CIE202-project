#pragma once
#include "operations/operation.h"
class opScrambel : public operation
{


public:
	opScrambel(controller* pCont);
	virtual ~opScrambel();

	virtual void Execute();

};




