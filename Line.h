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
public:
	Line(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	void SaveDataForShapes(ofstream &FileName,int ID);
	int* getshapeparamters();
};

