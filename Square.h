#pragma once
#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>
class Square :public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point center;
	GfxInfo shapeGfxInfo;
public:
	Square(Point p1, Point p2, GfxInfo shapeGfxInfo);
	Square(const Square* copy);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	void Resize(double r);
	bool isinshape(int x, int y) const;

	void Move(int&, int&);		//Move the shape
	void Zoom(float&);

	virtual string printdata() const;

	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	void Rotate();
	void HideShape(GUI* pUI);

};

