#include "opborder.h"
#include"Shapes/Graph.h"
#include"controller.h"
#include"GUI/GUI.h"

opborder::opborder(controller* pCont): operation(pCont)
{
}

void opborder::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	Point p1;
	shape* s = pGraph->GetSelected();
	if (s) {
		pUI->getwind()->SetPen(BLACK);
		pUI->getwind()->DrawImage("images\\MEnuIcons\\palette.jpg", 1230, 70, 300, 200);
		pUI->PrintMessage("select color you want");
		pUI->GetPointClicked(p1.x, p1.y);
		color c2 = pUI->getwind()->GetColor(p1.x, p1.y);
		pGraph->bordercolor(pGraph->GetSelected(), c2);
	}
	else
	{
		pUI->PrintMessage("draw shape firs...oR...select shape ");
	}
}
