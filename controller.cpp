#include "controller.h"
#include"opFill.h"
#include "opborder.h"
#include "operations\opAddRect.h"
#include  "opAddLine.h"
#include"opAddcir.h"
#include"opAddTri.h"
#include "opAddSqu.h"

#include "opAddPlay_Mode.h"
#include "opSelect.h"
#include"Shapes/Graph.h"
#include"opDelete.h"
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
		case CHNG_FILL_CLR:
			pOp = new opFill(this);
			break;
		case CHNG_DRAW_CLR:
			pOp = new opborder(this);
			break;

		case EXIT:
			///create Exitoperation here
			
			break;
		case TO_PLAY:
			pOp = new opAddPlay_Mode(this);
			
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
		case SELECT:
			pOp = new opSelect(this);

			break;
		case DEL:
			pOp = new opDelete(this);
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
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