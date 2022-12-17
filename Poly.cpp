#include "Poly.h"
#include<math.h>
#include <corecrt_math_defines.h>
Poly::Poly(Point p1, Point center,int vertices_num, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	p = p1;
	this->center = center;
	this->vertices_num = vertices_num;
	x = new int[vertices_num];
	y = new int[vertices_num];
}

Poly::~Poly()
{
}

void Poly::Draw(GUI* pUI) const
{
	// create arr for x-coordinats and another arr for y-coordinats to save them to use them later in drawing function
	double distance = sqrt(pow(p.x - center.x, 2) + pow(p.y - center.y, 2));

	for (int i = 0; i < vertices_num; i++) {
		double p_x = center.x + distance * cos(i * 2 * M_PI / vertices_num);
		double p_y = center.y + distance * sin(i * 2 * M_PI / vertices_num);
		x[i] = p_x;
		y[i] = p_y;
	}
	pUI->DrawPoly(x, y, vertices_num, ShpGfxInfo);
}

void Poly::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "LINE" + to_string(ID) + "  " +
		to_string(5) + "  " +
		to_string(6) + "  " +
		to_string(4) + "  " +
		to_string(8) + "  ";
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

int* Poly::getshapeparamters()
{
	int list[4];
	list[0] = x[0];// get x
	list[1] = y[1];//get y
	list[2] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));//get width
	list[3] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));// get height
	return list;
}