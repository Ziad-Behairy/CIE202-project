#pragma once
#include"operations\operation.h"
#include "DEFS.h"
#include "Shapes\Graph.h"
#include "GUI\GUI.h"
#include <stack>

class operation; //forward declaration
//Main class that manages everything in the application.
class controller
{
public:
	Graph* pGraph;	//pointe to the grapg
	GUI* pGUI;		//Pointer to UI class
	int NumOfDrawnShapes;//Actual number of drawing shapes
	shape* DrawnShapelist[MaxDrawnShapes];
	shape* Temp_DrawnShapelist[MaxDrawnShapes];
	int Temp_NumOfDrawnShapes;
	stack<operation*> UndoStack;
	stack<operation*> RedoStack;
	controller();
	~controller();

	// -- operation-Related Functions
	//Reads the input command from the user and returns the corresponding operation type
	operationType GetUseroperation() const;
	operation* createOperation(operationType); //Creates an operation
	void Run();

	Graph* getGraph() const;

	// -- Interface Management Functions
	GUI* GetUI() const; //Return pointer to the UI
	void UpdateInterface() ;	//Redraws all the drawing window	
	string ConvertCoulourToString(color anycolour);
	void CreateTempData(); // create temp data of current app 
	void AddAnotherShape(shape* pdraw);
	void GetDrawnShapelist(shape* shapeListNew[]);
	void GetTempDrawnShapelist(shape* newshapeListNew[]);
	int GetNumOfDrawnShapesCount();
	color ConvertStringToCoulour(string colorstring);
	bool savethis;
	
	//UNDO & REDO FUNCTIONS
	operation* GetLastOp();
	operation* GetLastBinedOp();
	void Undo();
	void Redo();
	void SaveOpToStack(operation* op );
	//void MakeShapeNull(shape* s);

};

