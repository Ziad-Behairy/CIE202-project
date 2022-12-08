#include "opAddSqu.h"
#include "Square.h"
#include "controller.h"
#include "GUI/GUI.h"
opAddSqu::opAddSqu(controller* pCont) :operation(pCont)
{}
opAddSqu::~opAddSqu()
{}

//Execute the operation
void opAddSqu::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo SquGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquGfxInfo.FillClr = pUI->getCrntFillColor();
	SquGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	SquGfxInfo.isFilled = false;	//default is not filled
	SquGfxInfo.isSelected = false;	//defualt is not selected


	//Create a square with the above parameters
	Square* R = new Square(P1, P2, SquGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}
