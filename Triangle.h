#pragma once

#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>

class Triangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	Triangle(Point, Point,Point, GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;

	virtual bool isinshape(int x, int y) const;
	virtual string printdata() const;


	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	virtual void Resize(int r);
	virtual void Rotate();
};



