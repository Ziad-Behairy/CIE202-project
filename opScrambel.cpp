#include "opScrambel.h"
#include"operations/operation.h"
#include"controller.h"
#include"GUI/GUI.h"
opScrambel::opScrambel(controller* pCont) :operation(pCont)
{
}

opScrambel::~opScrambel()
{
}

void opScrambel::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	Graph* pGr= pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Scrambeling shapes");
	pGr->Scrambel();

}
void opScrambel::Undo()
{
}
void opScrambel::Redo()
{
}
