#pragma once
#include "Shapes/Shape.h"
#include <fstream>
#include <ostream>
#include <iostream>

class Irrpoly : public shape
{
private:
	Point* points_arr;
	int  vertices_num;
	int* x =nullptr;
	int* y=nullptr ;
public:
	Irrpoly(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~Irrpoly();
	virtual void Draw(GUI* pUI) const;
	void SaveDataForShapes(ofstream& SaveFile, int ID);
};

