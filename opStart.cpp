#include "opStart.h"
#include"controller.h"
opStart::opStart(controller* pCont):operation(pCont)
{

}

opStart::~opStart()
{
}

void opStart::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("the game will start now ");
	pControl->getGraph()->start(pUI);

}

void opStart::Undo()
{
}

void opStart::Redo()
{
}




