#pragma once
#include <fstream>
#include <ostream>
#include <iostream>

#include "Shapes/Shape.h"
#include "math.h"

class Circle : public shape
{
private:
	Point center;
	Point radius;
	
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;

	virtual bool isinshape(int x, int y) const;

	void Move(int&,int&) ;		//Move the shape

	virtual string printdata() const;


	void SaveDataForShapes(ofstream &SaveFile, int ID);
	int* getshapeparamters();
	virtual void Resize(double r);
	virtual void Rotate();
};
