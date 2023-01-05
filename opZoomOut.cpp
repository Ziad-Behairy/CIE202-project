#include "opZoomOut.h"
#include"operations/operation.h"
#include"controller.h"
#include"GUI/GUI.h"

opZoomOut::opZoomOut(controller* pCont) : operation(pCont)
{

}
opZoomOut::~opZoomOut()
{
}

void opZoomOut::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	//pUI->ClearStatusBar();
	pUI->PrintMessage("Zooming out");
	pGr->Zoom_Out();
}
