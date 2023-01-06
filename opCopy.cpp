#include "opCopy.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
#include"controller.h"
#include <iostream>
opCopy::opCopy(controller* pcont):operation(pcont)
{
}

opCopy::~opCopy()
{
}

void opCopy::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	shape* c = pGraph->GetSelected();
	if (c) {
		pGraph->setCopied(c);
		pUI->PrintMessage("shape is Copied");
		std::cout << "ff";
	}
	else {
		pUI->PrintMessage("Please Select A shape First");
	}

}
