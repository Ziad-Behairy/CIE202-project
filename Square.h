#pragma once
#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>
class Square:public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Square(Point p1, Point p2, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;

	virtual bool isinshape(int x, int y) const;
	virtual string printdata() const;

	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();

};

