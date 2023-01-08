#include "opUnhide.h"
#include"controller.h"
opUnhide::opUnhide(controller* pCont) :operation(pCont)
{
}

opUnhide::~opUnhide()
{
}

void opUnhide::Execute()
{
	Point p1;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Click on the shape you want to unhide ");
	pUI->GetPointClicked(p1.x, p1.y);
	pControl->getGraph()->Unhide(&p1);

}
