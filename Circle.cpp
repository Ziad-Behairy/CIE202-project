#include "Circle.h"
Circle::Circle(Point center, Point radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	this->center = center;
	this->radius = radius;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a Circle on the screen	
	pUI->DrawCir(center, radius, ShpGfxInfo);//wait drawing function 
}

bool Circle::isinshape(int x, int y) const
{
	int Lradius = sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
	int distance = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (distance <= Lradius)

		return true;

	else
		return false;
}
