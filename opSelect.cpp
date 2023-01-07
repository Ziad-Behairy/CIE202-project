#include "opSelect.h"

#include"controller.h"
#include "GUI/GUI.h"
opSelect::opSelect(controller* pCont) :operation(pCont)
{}
opSelect::~opSelect()
{}

//Execute the operation

void opSelect::Execute()
{
	Point P1;
	Graph* pGraph = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Click At The Shape You want to select");
	pUI->GetPointClicked(P1.x, P1.y);
	pUI->ClearStatusBar();
	shape* select = pGraph->Getshape(P1.x, P1.y);
	pGraph->setselected(false);
	if (select) {
		if (!(select->IsSelected())) {
			select->SetSelected(true); // setselect in shape class
			pUI->PrintMessage("Shape Is Selected ");
			pGraph->setselected(select); // setselect in graph class
			//pUI->PrintMessage(select->printdata());
		}
		else {
			select->SetSelected(false);
			
			pUI->PrintMessage("Shape Is Unselected ");
			pGraph->setselected(nullptr);

		}
		
	}

}



















































//void opSelect::Execute()
//{
//	Point P1;
//	Graph* pGraph = pControl->getGraph();
//	GUI* pUI = pControl->GetUI();
//	pUI->PrintMessage("Click At The Figure You want to select");
//	pUI->GetPointClicked(P1.x, P1.y);
//	shape* select = pGraph->Getshape(P1.x, P1.y);
//	if (select) {
//		if (pGraph->GetSelected()) {
//			select->SetSelected(true);
//			pUI->PrintMessage(msg);
//	
//			pGraph->SetSelected(select);
//		}
//		else {
//			select->SetSelected(true);
//			pGraph->SetSelected(sel);
//		}
//	}
//
//
// }
