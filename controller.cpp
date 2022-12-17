#include"controller.h"
#include "operations\opAddRect.h"
#include  "opAddLine.h"
#include"opAddcir.h"
#include"opAddTri.h"
#include "opAddSqu.h"
#include "opAddIrrpoly.h"
#include "OperationSave.h"
#include"opExit.h"
#include"GUI/GUI.h"
#include "opAddPlay_Mode.h"





//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;

	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
	case DRAW_RECT:
		pOp = new opAddRect(this);
		break;
	case DRAW_SQU:
		pOp = new opAddSqu(this);
		break;
	case DRAW_LINE:
		pOp = new opAddLine(this);
		break;
	case DRAW_CIRC:
		pOp = new opAddCir(this);
		break;
	case DRAW_TRI:
		pOp = new opAddTri(this);
		break;
	case DRAW_IRREGPOL:
		pOp = new opAddIrrpoly(this);
		break;
	case SAVE:
		pOp = new OperationSave(this, NumOfDrawnShapes);
		break;

	case EXIT:
		//GUI* pUI =pControl->GetUI()
			//GUI* pUI = pControl->GetUI();
		if (savethis == true)
		{
			pGUI->PrintMessage("the drawing is saved ");
			pOp = new opExit(this);
		
			//need here to do operation save 
		}
		else
		{
			string userreply;
			pGUI->PrintMessage("do you want to save the drwaings? y or n ");
			userreply = pGUI->GetSrting();
			if (userreply == "y" || "Y")
			{
				pGUI->PrintMessage("new operation save ");
				pOp = new OperationSave(this, NumOfDrawnShapes);
				//pOp = new opExit(this);
			}
			

		}

			break;
		case TO_PLAY:
			pOp = new opAddPlay_Mode(this);
			
			break;

		
		break;

	case STATUS:	//a click on the status bar ==> no operation
		break;
	}

	return pOp;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
bool operator==(color c1, color c2)
{

	if (c1.ucBlue == c2.ucBlue &&
		c1.ucGreen == c2.ucGreen &&
		c1.ucRed == c2.ucRed)
		return true;

	else return false;

}
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
string controller::ConvertCoulourToString(color anycolour)
{
	if (anycolour == BLACK) return "BLACK";
	else if (anycolour == WHITE) return "WHITE";
	else if (anycolour == BLUE) return "BLUE";
	else if (anycolour == RED) return "RED";
	else if (anycolour == YELLOW) return "YELLOW";
	else if (anycolour == GREEN) return "GREEN";
	else if (anycolour == GREY) return "GREY";
	else if (anycolour == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "COLOR";
}
void controller::CreateTempData()
{
	Temp_NumOfDrawnShapes = NumOfDrawnShapes;
	GetDrawnShapelist(Temp_DrawnShapelist);
}
void controller::AddAnotherShape(shape* pdraw)
{
	DrawnShapelist[NumOfDrawnShapes++] = pdraw;
}
void controller::GetDrawnShapelist(shape* shapeListNew[])
{
	for (int i = 0; i < MaxDrawnShapes; i++) {
		shapeListNew[i] = DrawnShapelist[i];
	}
}
void controller::GetTempDrawnShapelist(shape* newshapeListNew[])
{
	for (int i = 0; i < MaxDrawnShapes; i++) {
		newshapeListNew[i] = Temp_DrawnShapelist[i];
	}
}
int controller::GetNumOfDrawnShapesCount()
{
	return NumOfDrawnShapes;
}

	

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		
		
		if(!(pGUI->Get_Mode())) //check if in play mode then it will not update the interface 
		UpdateInterface(); 

	} while (OpType != EXIT);

}