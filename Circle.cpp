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
