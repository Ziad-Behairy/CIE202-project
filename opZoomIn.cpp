#include "opZoomIn.h"
#include"operations/operation.h"
#include"controller.h"
#include"GUI/GUI.h"
opZoomIn::opZoomIn(controller* pCont) :operation(pCont)
{
}
opZoomIn::~opZoomIn()
{
}

void opZoomIn::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Zooming in");
	pGr->Zoom_In();
}
