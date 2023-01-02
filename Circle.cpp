#include "Circle.h"
#include"controller.h"
Circle::Circle(Point center, Point radius_p, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	this->center = center;
	this->radius_p = radius_p;
	raduis_dff = sqrt(pow((radius_p.x - center.x), 2) + pow((radius_p.y - center.y), 2));
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a Circle on the screen	
	pUI->DrawCir(center, radius_p, raduis_dff, ShpGfxInfo);//wait drawing function 
}


bool Circle::isinshape(int x, int y) const
{
	//int Lradius = sqrt(pow((radius_p.x - center.x), 2) + pow((radius_p.y - center.y), 2));
	int distance = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (distance <= raduis_dff)

		return true;

	else
		return false;
}

void Circle::Move(int& x, int& y)
{
	center.x = x;
	center.y = y;
}

string Circle::printdata() const
{
	return string();
}

void Circle::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "CIRC " + to_string(ID) + "  " +

		+"  " +
		to_string(radius_p.x) + "  " +
		to_string(radius_p.y) + "  ";
	SaveFile << ConvertCoulourToString2(ShpGfxInfo.DrawClr) + " ";
	if (ShpGfxInfo.isFilled)
	{
		SaveFile << ConvertCoulourToString2(ShpGfxInfo.FillClr);
	}
	else
	{
		SaveFile << "NO_FILL";
	}
	SaveFile << "\n";
}

int* Circle::getshapeparamters()
{
	int list[4];
	list[0] = center.x;
	list[1] = center.y;
	list[2] = 2 * sqrt(pow((radius_p.x - center.x), 2) + (pow((radius_p.y - center.y), 2)));
	list[3] = 2 * sqrt(pow((radius_p.x - center.x), 2) + (pow((radius_p.y - center.y), 2)));
	return list;

}
