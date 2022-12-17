#include "opStickImage.h"
#include"controller.h"
#include"Shapes/Shape.h"
#include"GUI/GUI.h"

opStickImage::opStickImage(controller* pCont):operation(pCont)
{
}

opStickImage::~opStickImage()
{
}

void opStickImage::Execute()
{
	GUI* pUI = pControl->GetUI();
	//pUI->PrintMessage("stick image now");
	Graph* pGraph = pControl->getGraph();
	pGraph->drawstickimage(pUI);
}
