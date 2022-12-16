#include "Graph.h"
#include "../GUI/GUI.h"


Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}


shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}

void Graph::Save(ofstream& SaveFile)
{
	SaveFile << shapesList.size() << "\n";  //and Current Fill Color and in the second line write the number of figures 
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->SaveDataForShapes(SaveFile, (i + 1));
	}
}
