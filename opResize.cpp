#include "opResize.h"
#include"controller.h"
#include"GUI/GUI.h"
#include<string>

opResize::opResize(controller* pcont):operation(pcont)
{
}

opResize::~opResize()
{
}

void opResize::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();

	shape* s = pGraph->GetSelected();
	if (s) {
		pUI->PrintMessage("enter scale you want:choose 0.5::0.25::2::4 ");
		string scalee = pUI->GetSrting();
		double scale = 0;
		if (scalee == "0.5") {
			scale = 0.5;
		}
		else if (scalee == "0.25") {
			scale = 0.25;
		}
		else if (scalee == "2") {
			scale = 2;
		}
		else if (scalee == "4") {
			scale = 4;
		}
		else {
			pUI->PrintMessage("error: choose from list ");
		}

		s->Resize(scale);
	}

}

void opResize::Undo()
{
}
void opResize::Redo()
{
}
