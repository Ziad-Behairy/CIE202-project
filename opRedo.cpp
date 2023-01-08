#include "opRedo.h"
#include"controller.h"
#include"GUI/GUI.h"
opRedo::opRedo(controller* pCont) : operation(pCont)
{
}

opRedo::~opRedo()
{
}

void opRedo::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	if (pControl->GetLastBinedOp())
	{
		pControl->GetLastBinedOp()->Redo();
		pControl->Redo();
	}
	else {
		pUI->PrintMessage("Redo Stack is Empty");
	}
}


void opRedo::Undo()
{
	
}

void opRedo::Redo()
{

}