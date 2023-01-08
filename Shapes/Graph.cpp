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
#include "..\opHide.h"

Graph::Graph()
{
	selectedShape = nullptr;
	copiedShape = nullptr;
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
void Graph::Draw(GUI* pUI) 
{
	
	pUI->ClearDrawArea();
		for (int i = 0; i < shapesList.size(); i++) {
			shapesList[i]->Draw(pUI);
			if (shapesList[i]->IsHiden()) {
				shapesList[i]->HideShape(pUI);
			}
		}
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

	for (auto& shapePointer : shapesList)
		if (shapePointer->isinshape(x, y)) {
			return shapePointer;
		}

	///Add your code here to search for a shape given a point x,y	

	return nullptr;
}

void Graph::Duplicate()
{
	shape* deplicate;
	int num = shapesList.size();
	for (int i = 0; i < num; i++)
	{
		if (dynamic_cast<Rect*>(shapesList[i]))
		{
			Rect* copy = dynamic_cast<Rect*>(shapesList[i]);
			deplicate = new Rect(copy);
			Addshape(deplicate);
			cout << "rect";
		}
		if (dynamic_cast<Circle*>(shapesList[i]))
		{
			Circle* copy = dynamic_cast<Circle*>(shapesList[i]);
			deplicate = new Circle(copy);
			Addshape(deplicate);
		}
		if (dynamic_cast<Irrpoly*>(shapesList[i]))
		{
			Irrpoly* copy = dynamic_cast<Irrpoly*>(shapesList[i]);
			deplicate = new Irrpoly(copy);
			Addshape(deplicate);
		}
		if (dynamic_cast<Line*>(shapesList[i]))
		{
			Line* copy = dynamic_cast<Line*>(shapesList[i]);
			deplicate = new Line(copy);
			Addshape(deplicate);
		}
		if (dynamic_cast<Poly*>(shapesList[i]))
		{
			Poly* copy = dynamic_cast<Poly*>(shapesList[i]);
			deplicate = new Poly(copy);
			Addshape(deplicate);
		}
		if (dynamic_cast<Square*>(shapesList[i]))
		{
			Square* copy = dynamic_cast<Square*>(shapesList[i]);
			deplicate = new Square(copy);
			Addshape(deplicate);
		}
		if (dynamic_cast<Triangle*>(shapesList[i]))
		{
			Triangle* copy = dynamic_cast<Triangle*>(shapesList[i]);
			deplicate = new Triangle(copy);
			Addshape(deplicate);
		}

	}
}


shape* Graph::GetSelected()
{
	return selectedShape;
}


shape* Graph::getCopied() {
	return copiedShape;
}

void Graph::setCopied(shape* copied) {
	copiedShape = copied;
}

void Graph::setselected(shape* s)
{
	if (!selectedShape)
		selectedShape = s;
	/*else {
		selectedShape->SetSelected(0);
		selectedShape = s;
	}*/
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
	for (int i = 0,j=shapesList.size()-1; i < shapesList.size(); i++,j--)
	{

		int x = rand() % (1100) + 100;
		int y = rand() % (501) + 95;
		/*int x1 = shapesList[j]->getshapeparamters()[4];
		int y1 = shapesList[j]->getshapeparamters()[5];
		int x2 = shapesList[i]->getshapeparamters()[4];
		int y2 = shapesList[i]->getshapeparamters()[5];
		shapesList[j]->Move(x2, y2);*/
		shapesList[i]->Move(x, y);
		
	}

}
void Graph::Zoom_In()
{
	float Scale=2;
	for (auto& shapePointer : shapesList)
		shapePointer->Zoom(Scale);
}
void Graph::Zoom_Out()
{
	float Scale=0.5;
	for (auto& shapePointer : shapesList)
		shapePointer->Zoom(Scale);
}
void Graph::match(GUI* pUI)
{
	int score = 0;
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsHiden() == false)
			for (int j = i + 1; j < shapesList.size(); j++)
				if (shapesList[j]->IsHiden() == false) {
					if (i > j)
					{
						shapesList[i]->SetSelected(1);
						shapesList[j]->SetSelected(1);
						setDelete();
						score = score + 3;
						pUI->ClearStatusBar();
			            string msg = "new score is " + score;
			            pUI->PrintMessage(msg);
					}
					if (i < j)
					{
						shapesList[i]->SetSelected(1);
						shapesList[j-1]->SetSelected(1);
						setDelete();
						score = score + 3;
						pUI->ClearStatusBar();
						string msg = "new score is " + score;
						pUI->PrintMessage(msg);
					}
					else
					{
						shapesList[i]->SetHiden(1);
						shapesList[j]->SetHiden(1);
						score = score + 1;
						pUI->ClearStatusBar();
						string msg = "new score is " + score;
						pUI->PrintMessage(msg);
					}
				} 
					
	}
		
	
	//Point firstclick;
	//Point secondclick;
	//while (shapesList.size() != 0)
	//{
	//	int score = 0;
	//	Hide(pUI);
	//	pUI->GetPointClicked(firstclick.x, firstclick.y);
	//	shape* selectcard1 = Getshape(firstclick.x, firstclick.y);
	//	pUI->GetPointClicked(secondclick.x, secondclick.y);
	//	shape* selectcard2 = Getshape(secondclick.x, secondclick.y);
	//	//selectcard1->unhide
	//	//selectcard2->unhide
	//	if (selectcard1->getid() == selectcard2->getid())
	//	{
	//		selectcard1->SetSelected(true);
	//		selectcard2->SetSelected(true);
	//		setDelete();
	//		//selectcard1->unhide
	//		//selectcard2->unhide
	//		score = score + 3;
	//		pUI->ClearStatusBar();
	//		string msg = "new score is " + score;
	//		pUI->PrintMessage(msg);
	//	}
	//	else
	//	{
	//		selectcard1->SetHiden(1);
	//		selectcard2->SetHiden(1);
	//		score = score + 3;
	//		pUI->ClearStatusBar();
	//		string msg = "please try again ,new score is " + score;
	//		pUI->PrintMessage(msg);
	//	}
	//	pUI->ClearStatusBar();
	//	string finalmessage = "you finished the game with score " + score;
	//	pUI->PrintMessage(finalmessage);
	//}

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

void Graph::drawstickimage(GUI* pUI)
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsSelected())
		{
			int x = shapesList[i]->getshapeparamters()[0];
			int y = shapesList[i]->getshapeparamters()[1];
			int width = shapesList[i]->getshapeparamters()[2];
			int height = shapesList[i]->getshapeparamters()[3];
			pUI->StickImage("images\\MenuIcons\\Card.jpg", x, y, width, height);
			//pUI->StickImage("images\\MenuIcons\\TEAM.jpg", i*5, i*10, 20,20);
		}
	}
}

void Graph::Hide(GUI* pUI)
{
		for (int i = 0; i < shapesList.size(); i++)
		{
			shapesList[i]->SetHiden(1);
		}
	
	

}

void Graph::Unhide(Point* p)
{
	for (int i = 0; i < shapesList.size(); i++) {
		if (shapesList[i]->isinshape(p->x, p->y))
			shapesList[i]->SetHiden(0);

	}

}

//bool Graph::isHide()
//{
//	if (flag)
//		return true;
//	else
//	return false;
//}

void Graph::start(GUI* pUI)
{
		Duplicate();
		Hide(pUI);
		Scrambel();
		Point point;
		pUI->GetPointClicked(point.x, point.y);
		Unhide(&point);
		Point point2;
		pUI->GetPointClicked(point2.x, point2.y);
		Unhide(&point2);
		match(pUI);
}

vector<shape*>  Graph::selectedshapes()
{
	vector<shape*> selectedshapes;
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsSelected())
		{
			selectedshapes.push_back(shapesList[i]);
		}
	}
	return selectedshapes;
}

void Graph::moveshapetobin()
{
	int iend = shapesList.size()-1;
	if (shapesList[shapesList.size() - 1])
	{
		BinedList.push_back(shapesList[shapesList.size() - 1]);
		shapesList.erase(shapesList.end() - 1);
		cout << "Shape moved from shapes_list to Undone_shapes_list!";
	}
}

void Graph::returntoshapelist()
{
	int iend = BinedList.size() - 1;
	cout << "\nreturntoshapelist done";
	if (BinedList[shapesList.size() - 1])
	{
		shapesList.push_back(BinedList[shapesList.size() - 1]);
		BinedList.erase(BinedList.end() - 1);
		cout << "Shape moved from Undone_shapes_list to shapes_list!";
	}
}

