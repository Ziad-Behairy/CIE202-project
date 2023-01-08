#include "opDelete.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"
#include"operations/opAddRect.h"
#include"controller.h"
opDelete::opDelete(controller* pcont) :operation(pcont) {};
void opDelete::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	//delete pGr->GetSelected();
	//pGr->Delete(pGr->GetSelected());
	pGr->setDelete();



}

void opDelete::Undo()
{
}

void opDelete::Redo()
{
}
