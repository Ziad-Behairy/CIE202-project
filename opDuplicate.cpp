#include "opDuplicate.h"
#include"controller.h"

opDuplicate::opDuplicate(controller* pCont):operation(pCont)
{
}

opDuplicate::~opDuplicate()
{
}

void opDuplicate::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Duplicate all shapes");
	pGr->Duplicate();
}

void opDuplicate::Undo()
{
}

void opDuplicate::Redo()
{
}
