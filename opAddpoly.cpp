#include "opAddpoly.h"
#include "operations/operation.h"
#include"controller.h"
#include"Poly.h"
#include"GUI/GUI.h"
#include<string>
opAddpoly::opAddpoly(controller* pCont) :operation(pCont)
{
}

opAddpoly::~opAddpoly()
{
}

void opAddpoly::Execute()
{
	GUI* pUI = pControl->GetUI();
	//Get data from user to draw 
	int vertices_num;
	pUI->ClearStatusBar();
	pUI->PrintMessage("Add new  polygon --> Please enter number of vertices : ");
	vertices_num = stoi(pUI->GetSrting());
	pUI->ClearStatusBar();
	Point p, center;
	pUI->PrintMessage(" Click at first point ");
	pUI->GetPointClicked(p.x, p.y);
	pUI->ClearStatusBar();
	string msg = "First point is at (" + to_string(p.x) + ", " + to_string(p.y) + " )";
	msg += " ... Click at center";
	pUI->PrintMessage(msg);
	pUI->GetPointClicked(center.x, center.y);
	pUI->ClearStatusBar();
	 msg = "Center point is at (" + to_string(center.x) + ", " + to_string(center.y) + " )";
	 pUI->PrintMessage(msg);
	//set all Irrpoly propertise 
	GfxInfo PolyGfxInfo;
	PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.isFilled = false; // detault isn't filled 
	PolyGfxInfo.isSelected = false; // detault isn't selected 
	// Create  a new Irrpoly with this parameters and properties
	Poly* polygon = new Poly(p, center,vertices_num, PolyGfxInfo);
	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	//Add the Line to the list of shapes
	pGr->Addshape(polygon);
}

void opAddpoly::Undo()
{
}

void opAddpoly::Redo()
{
}