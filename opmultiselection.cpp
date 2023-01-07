#include "opmultiselection.h"
#include "opSelect.h"
#include"controller.h"
#include "GUI/GUI.h"

opmultiselection::opmultiselection(controller* pCont):operation(pCont)
{
}

opmultiselection::~opmultiselection()
{
}

void opmultiselection::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Click At The Shapes You want to select");
	string userreply = "y";
	while (userreply == "y")
	{
		pUI->GetPointClicked(P1.x, P1.y);
		pUI->ClearStatusBar();
		shape* select = pGraph->Getshape(P1.x, P1.y);
		if (select) {
				select->SetSelected(true); // setselect in shape class
				pUI->PrintMessage("Shape Is Selected ");
				pGraph->setselected(select); // setselect in graph class
				//pUI->PrintMessage(select->printdata());
			
		}
		pUI->PrintMessage("do you want to select another shape ,y or n");
		userreply=pUI->GetSrting();
	}
	
}
