#include "opAddIrrpoly.h"
#include "operations/operation.h"
#include"controller.h"
#include"Irrpoly.h"
#include"GUI/GUI.h"
#include<string>
opAddIrrpoly::opAddIrrpoly(controller* pCont):operation(pCont)
{
}

opAddIrrpoly::~opAddIrrpoly()
{
}

void opAddIrrpoly::Execute()
{
	GUI* pUI = pControl->GetUI();
	//Get data from user to draw 
	int vertices_num;
	pUI->PrintMessage("Add new irregular polygon --> Please enter number of vertices : ");
	vertices_num = stoi(pUI->GetSrting());
	pUI->ClearStatusBar();
	pUI->PrintMessage("Enter " + to_string(vertices_num) + " points to draw irregular polygon ");

	Point* p = new Point[vertices_num];
	for (int i = 0; i < vertices_num; i++) {
		pUI->GetPointClicked(p[i].x, p[i].y); // store point in the arr to draw 
	}
	pUI->ClearStatusBar();
	//set all Irrpoly propertise 
	GfxInfo IrrpolyGfxInfo;
	IrrpolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	IrrpolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	IrrpolyGfxInfo.FillClr = pUI->getCrntFillColor();
	IrrpolyGfxInfo.isFilled = false; // detault isn't filled 
	IrrpolyGfxInfo.isSelected = false; // detault isn't selected 
	// Create  a new Irrpoly with this parameters and properties
	Irrpoly* Irrpolygon = new Irrpoly(p,vertices_num, IrrpolyGfxInfo);
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	//Add the Line to the list of shapes
	pGr->Addshape(Irrpolygon);
}