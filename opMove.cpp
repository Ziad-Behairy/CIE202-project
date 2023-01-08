#include "opmove.h"
#include"controller.h"

opMove::opMove(controller* pCont) :operation(pCont)
{

}

opMove::~opMove()
{
}

void opMove::Execute()
{
	Point point;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	window* pWind = pUI->getwind();
	while (pWind->GetButtonState(LEFT_BUTTON, point.x, point.y) != BUTTON_DOWN)
	{
		if (pGraph->Getshape(point.x, point.y) != nullptr)
		{
			shape* selectedshape = pGraph->Getshape(point.x, point.y);
			selectedshape->Move(point.x, point.y);
			pUI->ClearDrawArea();
			pControl->UpdateInterface();
			Sleep(50);
		}
	}
}