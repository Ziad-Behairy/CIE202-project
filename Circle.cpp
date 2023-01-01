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
}

void Circle::Move(int& x,int& y)
{
	center.x = x;
	center.y = y;

string Circle::printdata() const
{
	string values;
	double rad = pow(pow(radius.x - center.x, 2) + pow(radius.y - center.y, 2), -1);
	values = "This is a Circle.The ID: " + to_string(ID) + ". The Point of the center: (" + to_string(center.x) + ", " + to_string(center.y) + "). The Radious is: " + to_string(rad) + ".";
	return values;

}
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
