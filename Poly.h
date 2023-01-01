#pragma once
#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>

class Poly : public shape
{
private:
	Point p,center;
	int  vertices_num;
	int* x = nullptr;
	int* y = nullptr;
public:
	Poly(Point,Point,int, GfxInfo shapeGfxInfo);
	virtual ~Poly();
	virtual void Draw(GUI* pUI) const;
	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();
	virtual bool isinshape(int x, int y) const;
	virtual string printdata() const;
	virtual void Resize(int r);
	virtual void Rotate();
};

