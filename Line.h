#pragma once

#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point center;
	GfxInfo shapeGfxInfo;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	Line(const Line* copy);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	void Move(int&, int&);		//Move the shape
	void Zoom(float&);	//Zoom the shape
	bool isinshape(int x, int y) const;
	virtual string printdata() const;
	void SaveDataForShapes(ofstream& FileName, int ID);
	int* getshapeparamters();
	void Resize(double r);
	void HideShape(GUI* pUI);
	void Rotate();
};

