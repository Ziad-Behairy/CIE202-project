#pragma once
#include"operations/operation.h"
class opZoomOut : public operation
{
public:
	opZoomOut(controller* pCont);
	virtual ~opZoomOut();

	virtual void Execute();
	void Undo() ;
	void Redo() ;
};

