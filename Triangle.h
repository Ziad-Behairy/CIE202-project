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
	Point center;
	GfxInfo shapeGfxInfo;
public:
	Triangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	Triangle(const Triangle* copy);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	bool isinshape(int x, int y) const;
	virtual string printdata() const;
	void Zoom(float&);
	void Move(int&, int&);		//Move the shape
	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	void Resize(double r);
	void HideShape(GUI* pUI);
	void Rotate();
};



