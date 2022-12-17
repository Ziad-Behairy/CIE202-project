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
public:
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;

	virtual bool isinshape(int x, int y) const;

	void SaveDataForShapes(ofstream& SaveFile, int ID);
	int* getshapeparamters();

};

