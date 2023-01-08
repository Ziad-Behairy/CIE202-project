#pragma once
#include"operations/operation.h"
class opZoomIn : public operation
{
public:
	opZoomIn(controller* pCont);
	virtual ~opZoomIn();

	virtual void Execute();
	void Undo() ;
	void Redo() ;
};

