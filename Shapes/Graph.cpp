#include "Graph.h"
#include "../GUI/GUI.h"
#include"../controller.h"
#include<fstream>
#include<iostream>
#include"..\Shapes\Shape.h"
#include"..\Line.h"
#include"..\Circle.h"
#include"..\Triangle.h"
#include"..\Square.h"
#include"..\Poly.h"
#include "..\Irrpoly.h"
#include"..\Shapes\Rect.h"
#include<time.h>

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
void Graph::Scrambel()
{
	srand(time(0));
int x, y;
for (unsigned i =0 ;i< shapesList.size();i++)
{
	
	x = rand() % (1100)+100;
	y = rand() % (501)+95;
	shapesList[i]->Move(x, y);
}

}
void Graph::Save(ofstream& SaveFile)
{
	SaveFile << shapesList.size() << "\n";  //and Current Fill Color and in the second line write the number of figures 
	for (int i = 0; i < shapesList.size(); i++) {
		shapesList[i]->SaveDataForShapes(SaveFile, (i + 1));
	}
}


vector<shape*> Graph::getshapesList()
{
	vector<shape*>newshapelist;
	for (int i = 0; i < shapesList.size(); i++)
	{
		newshapelist[i] = shapesList[i];
	}
	return newshapelist;

}




//void Graph::Delete(shape* psh)
//{
//	shapesList.erase(find(shapesList.begin(), shapesList.end(), psh));
//}

void Graph::drawstickimage(GUI*pUI)
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		int x = shapesList[i]->getshapeparamters()[0];
		int y = shapesList[i]->getshapeparamters()[1];
		int width = shapesList[i]->getshapeparamters()[2];
		int height = shapesList[i]->getshapeparamters()[3];
		pUI->StickImage("images\\MenuIcons\\TEAM.jpg", x, y, width, height);
		//pUI->StickImage("images\\MenuIcons\\TEAM.jpg", i*5, i*10, 20,20);
	}
}

