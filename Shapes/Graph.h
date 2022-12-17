#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape

	shape* GetSelected();
	void setselected(shape* s);
	void setDelete();
	void changefillcolor(shape* psh, color newcolor);
	void bordercolor(shape* psh, color newcoloe);
	//void Delete(shape* psh);
	//virtual bool isinshape(int x, int y)const ;

	void Save(ofstream& SaveFile);	//Save all shapes to a file
	//void load(ifstream& inputfile);	//Load all shapes from a file
	vector <shape*> getshapesList();
	void drawstickimage(GUI* pUI);

};
