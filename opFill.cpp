#include "opFill.h"
#include"CMUgraphicsLib/CMUgraphics.h"
#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"

opFill::opFill(controller* pcont):operation(pcont)
{
}

void opFill::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Point p1;
	pUI->getwind()->SetPen(BLACK);
	pUI->getwind()->DrawImage("images\\MEnuIcons\\palette.jpg", 1000,100,300, 100);
	pUI->PrintMessage("select color you want");
	pUI->GetPointClicked(p1.x, p1.y);
	color c2 = pUI->getwind()->GetColor(p1.x, p1.y);
	pGraph->changefillcolor(pGraph->GetSelected(), c2);

}

