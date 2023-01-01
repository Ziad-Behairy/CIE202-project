#include "opResize.h"
#include"controller.h"
#include"GUI/GUI.h"
#include<string>

opResize::opResize(controller* pcont):operation(pcont)
{
}

void opResize::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	shape* s = pGraph->GetSelected();
	if (s) {
		pUI->PrintMessage("enter scale you want ");
		int numresize = stoi(pUI->GetSrting());


		s->Resize(numresize);

	}
	else
		pUI->PrintMessage("select shape first");



}
