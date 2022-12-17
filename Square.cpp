#include "Square.h"

Square::Square(Point p1, Point p2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
}

Square::~Square()
{
}

void Square::Draw(GUI* pUI) const
{
	pUI->DrawSqu(Corner1, Corner2, ShpGfxInfo);
}

bool Square::isinshape(int x, int y) const
{
	if (x >= min(Corner1.x, Corner2.x) && x <= max(Corner1.x, Corner2.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y))
		return true;
	else
		return false;
}
