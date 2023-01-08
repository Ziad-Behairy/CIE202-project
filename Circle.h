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
	Point radius_p;
	int raduis_dff;
	GfxInfo shapeGfxInfo;
public:
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	Circle(const Circle * copy);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	void Resize(double r);
	bool isinshape(int x, int y) const;
	void Move(int&, int&);		//Move the shape
	void Zoom(float&) ;	//Zoom the shape
	string printdata() const;
	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	void HideShape(GUI* pUI);

	void Rotate();

};
