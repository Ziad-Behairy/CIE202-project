#pragma once
#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include"operations/operation.h"
#include"controller.h"
class opDelete:public operation
{
public:
    opDelete(controller* pcont);
	
	 virtual void Execute();
	 void Undo() ;
	 void Redo() ;
};

