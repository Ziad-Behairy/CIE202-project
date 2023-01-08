#pragma once
#include "operations/operation.h"

class opAddPlay_Mode : public operation
{ private: 
	window* pWind;	//Window starting coordinates
public:
	opAddPlay_Mode(controller* pCont);
	virtual ~opAddPlay_Mode();
	virtual void Execute();
	void Undo() ;
	void Redo() ;

};

