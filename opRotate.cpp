#include"opRotate.h"
#include"controller.h"
#include"GUI/GUI.h"
//#include<string>
#include<iostream>
using namespace std;
opRotate::opRotate(controller* pcont):operation(pcont)
{

}

opRotate::~opRotate()
{
}

void opRotate::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->ClearStatusBar();
	pUI->PrintMessage("Rotate");
	shape* s = pGraph->GetSelected();
	if (s) {
		//pUI->PrintMessage("enter scale you want:choose 0.5::0.25::2::4 ");
		//string scalee = pUI->GetSrting();
		s->Rotate();
	}
}
