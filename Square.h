#pragma once
#include "Shapes/Shape.h"
class Square:public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Square(Point p1, Point p2, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
};
