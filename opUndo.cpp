#include "opUndo.h"
#include"operations/operation.h"
#include"controller.h"
#include"GUI/GUI.h"
#include<iostream>
opUndo::opUndo(controller* pCont):operation(pCont)
{
}
opUndo::~opUndo()
{
}

void opUndo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	cout << "\n enter undo extcute \n";
	if (pControl->GetLastOp())
	{pControl->GetLastOp()->Undo();
		cout << "\n call circl undo";
		pControl->Undo();

	}
	else
	{
		pUI->PrintMessage("Undo Stack is Empty");
		cout << "enter excute";
	}
}

void opUndo::Undo()
{
}

void opUndo::Redo()
{
}
