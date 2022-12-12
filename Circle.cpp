#include "Circle.h"
#include"controller.h"
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

void Circle::SaveDataForShapes(ofstream &SaveFile,int ID)
{
	SaveFile<< "CIRC " + to_string(ID) + "  " +
		to_string(center.x) + "  " +
		to_string(center.y) + "  " +
		to_string(radius.x) + "  " +
		to_string(radius.y) + "  ";
	SaveFile << ConvertCoulourToString2(ShpGfxInfo.DrawClr) + " ";
	if (ShpGfxInfo.isFilled)
	{
		SaveFile << ConvertCoulourToString2(ShpGfxInfo.FillClr);
	}
	else
	{
		SaveFile << "NO_FILL";
	}
	SaveFile <<"\n";
}
