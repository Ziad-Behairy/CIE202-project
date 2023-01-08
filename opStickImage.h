#pragma once
#include"operations/operation.h"
class opStickImage:public operation
{
public:
	opStickImage(controller* pCont);
	virtual ~opStickImage();
	void Execute();
	void Undo() ;
	void Redo() ;

};

