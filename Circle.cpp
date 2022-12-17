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


bool Circle::isinshape(int x, int y) const
{
	int Lradius = sqrt(pow((radius.x - center.x), 2) + pow((radius.y - center.y), 2));
	int distance = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (distance <= Lradius)

		return true;

	else
		return false;
void Circle::SaveDataForShapes(ofstream &SaveFile,int ID)
{
	SaveFile<< "CIRC " + to_string(ID) + "  " +
	
		+ "  " +
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

int* Circle::getshapeparamters()
{
	int list[4];
	list[0] = center.x;
	list[1] = center.y;
	list[2] = 2 * sqrt(pow((radius.x - center.x), 2)+ (pow((radius.y - center.y), 2)));
	list[3] =2*sqrt(pow((radius.x - center.x), 2) + (pow((radius.y - center.y), 2)));
	return list;

}
