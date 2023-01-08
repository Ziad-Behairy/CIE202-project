#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
#include<time.h>
using namespace std;

//forward decl
class GUI;

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector<shape*>::iterator iter;
	vector <shape*> shapesList; //a container to hold all shapes 
	//vector <shape*> imagesList; //a container to hold all shapes
	vector <shape*> BinedList; //a container to hold all shapes undoed
	shape* selectedShape;	//pointer to the currently selected shape
	shape* copiedShape;
	int flag = 0;
public:
	Graph();
	~Graph();
	void setCopied(shape*);
	shape* getCopied();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) ;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	void Duplicate();
	shape* GetSelected();
	void setselected(shape* s);
	void setDelete();
	void changefillcolor(shape* psh, color newcolor);
	void bordercolor(shape* psh, color newcoloe);
	//void Delete(shape* psh);
	//virtual bool isinshape(int x, int y)const ;
	void Scrambel();
	void Zoom_In();
	void Zoom_Out();
	void match(GUI* pUI);
	void Save(ofstream& SaveFile);	//Save all shapes to a file
	//void load(ifstream& inputfile);	//Load all shapes from a file
	vector <shape*> getshapesList();
	void drawstickimage(GUI* pUI);
	void Hide(GUI* pUI); // Hide shapes by drawing a card on each shape 
	bool isHide();

	void moveshapetobin();
	void returntoshapelist();


	void start(GUI* pUI);
	vector<shape*> selectedshapes();
	void Unhide(Point* p); 
	//bool isHide();

};
