#pragma once

#include "shape.h"
#include <fstream>
#include <ostream>
#include <iostream>

class Rect : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point center;
	GfxInfo shapeGfxInfo;
public:
	Rect(Point, Point, GfxInfo shapeGfxInfo);
	Rect(const Rect* copy);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	void Move(int&, int&);		//Move the shape
	void Zoom( float&);	//Zoom the shape
	bool isinshape(int x, int y) const;
	virtual string printdata() const;
	void Resize(double r);
	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	void Rotate();
};

