#include "opAddTri.h"
#include "Triangle.h"

#include"controller.h"

#include "GUI/GUI.h"

opAddTri::opAddTri(controller* pCont) :operation(pCont)
{}
opAddTri::~opAddTri()
{}

//Execute the operation
void opAddTri::Execute()
{
	Point P1, P2,P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	//
	string msg1 = "secind corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg1 += " ... Click at Third corner";
	pUI->PrintMessage(msg1);
	//Read 3nd corner and store in point P3
	pUI->GetPointClicked(P3.x, P3.y);

	
	pUI->ClearStatusBar();

	//Preapre all rectangle parameters
	GfxInfo RectGfxInfo;

	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pUI->getCrntDrawColor();
	RectGfxInfo.FillClr = pUI->getCrntFillColor();
	RectGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	RectGfxInfo.isFilled = false;	//default is not filled
	RectGfxInfo.isSelected = false;	//defualt is not selected
	RectGfxInfo.IsHiden = false;

	//Create a rectangle with the above parameters
	Triangle* R = new Triangle(P1, P2,P3, RectGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the rectangle to the list of shapes
	pGr->Addshape(R);

}

void opAddTri::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->moveshapetobin(); // move the shape from shape list to bin list 
}

void opAddTri::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->returntoshapelist();// return the shape from bin list  to shape list
}