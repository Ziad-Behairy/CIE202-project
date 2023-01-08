#include "opAddLine.h"
#include "Line.h"
#include "controller.h"
#include "GUI/GUI.h"

opAddLine::opAddLine(controller* pCont) :operation(pCont)
{}
opAddLine::~opAddLine()
{}

//Execute the operation
void opAddLine::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("New Line : Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo LineGfxInfo;

	//get drawing, filling colors and pen width from the interface
	LineGfxInfo.DrawClr = pUI->getCrntDrawColor();
	LineGfxInfo.FillClr = pUI->getCrntFillColor();
	LineGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	LineGfxInfo.isFilled = false;	//default is not filled
	LineGfxInfo.isSelected = false;	//defualt is not selected
	LineGfxInfo.IsHiden = false;

	//Create a Line with the above parameters
	
	Line* R = new Line(P1, P2, LineGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Line to the list of shapes
	pGr->Addshape(R);

}

void opAddLine::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->moveshapetobin(); // move the shape from shape list to bin list 
}

void opAddLine::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->returntoshapelist();// return the shape from bin list  to shape list
}