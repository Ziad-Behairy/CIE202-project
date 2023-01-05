#include "opHide.h"
#include"controller.h"
#include"Shapes/Shape.h"
#include"GUI/GUI.h"

opHide::opHide(controller* pCont) : operation(pCont)
{
}

opHide::~opHide()
{
}

void opHide::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage(" Hide Shapes ");
	Graph* pGraph = pControl->getGraph();
	pGraph->Hide(pUI);

}
