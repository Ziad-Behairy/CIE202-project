#include "opAddCir.h"
#include "Circle.h"
#include "controller.h"
#include "Gui/GUI.h"

opAddCir::opAddCir(controller* pCont) :operation(pCont)
{}
opAddCir::~opAddCir()
{}

//Execute the operation
void opAddCir::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	pUI->PrintMessage("New Circel : Click at the Center");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click to chose the Radius";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);
	pUI->ClearStatusBar();

	//Preapre all Line parameters
	GfxInfo CircleGfxInfo;

	//get drawing, filling colors and pen width from the interface
	CircleGfxInfo.DrawClr = pUI->getCrntDrawColor();
	CircleGfxInfo.FillClr = pUI->getCrntFillColor();
	CircleGfxInfo.BorderWdth = pUI->getCrntPenWidth();


	CircleGfxInfo.IsHiden = false;
	CircleGfxInfo.isFilled = false;	//default is not filled
	CircleGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Line with the above parameters
	Circle* R = new Circle(P1, P2, CircleGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();
	CirclePointer = R;
	//Add the Line to the list of shapes
	pGr->Addshape(R);
	

}


void opAddCir::Undo()
{
	cout << "undo cir";
	Graph* pGr = pControl->getGraph();
	pGr->moveshapetobin(); // move the shape from shape list to bin list 
}

void opAddCir::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->returntoshapelist();// return the shape from bin list  to shape list
}
