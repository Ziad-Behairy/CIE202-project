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

void Graph::changefillcolor(shape* psh, color newcolor) {
	psh->ChngFillClr(newcolor);
	psh->setisfilled();
}
void Graph::bordercolor(shape* psh, color newcolor) {
	psh->ChngDrawClr(newcolor);
}

shape* Graph::Getshape(int x, int y) const
{
	
	for (auto& shapePointer:shapesList)
		if (shapePointer->isinshape(x, y)) {
			return shapePointer;
		}

	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}

shape* Graph::GetSelected()
{
	return selectedShape;
}

void Graph::setselected(shape* s)
{ 
	if (!selectedShape)
		selectedShape = s;
	else {
		selectedShape->SetSelected(0);
		selectedShape = s;
	}
}

void Graph::setDelete()
{
	int c = -1;
	for (auto shapepointer : shapesList)
	{
		c++;
		if (shapepointer->IsSelected())
		{
			shapesList.erase(shapesList.begin() + c);
				c--;
		}
	}
}




//void Graph::Delete(shape* psh)
//{
//	shapesList.erase(find(shapesList.begin(), shapesList.end(), psh));
//}