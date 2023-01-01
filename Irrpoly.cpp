#include "Irrpoly.h"

Irrpoly::Irrpoly(Point* arr, int vertices_num, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	points_arr = arr;
	this->vertices_num = vertices_num;
	x = new int[vertices_num];
	y = new int[vertices_num];
}

Irrpoly::~Irrpoly()
{
}

void Irrpoly::Draw(GUI* pUI) const
{
	// create arr for x-coordinats and another arr for y-coordinats to save them to use them later in drawing function
	for (int i = 0; i < vertices_num; i++) {
		x[i] = points_arr[i].x;
		y[i] = points_arr[i].y;
	}
	pUI->DrawIrrPoly(x, y, vertices_num, ShpGfxInfo);
}

void Irrpoly::SaveDataForShapes(ofstream& SaveFile, int ID)
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

int* Irrpoly::getshapeparamters()
{
	int list[4];

	list[0] = x[0];
	list[1] = y[1];
	list[2] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));
	list[3] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));

	list[0] = x[0];// get x
	list[1] = y[1];//get y
	list[2] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));//get width
	list[3] = sqrt(pow((x[1] - x[0]), 2) + (pow((y[1] - y[0]), 2)));// get height

	return list;
}

void Irrpoly::Move(int&, int&)
{
}

bool Irrpoly::isinshape(int x, int y) const
{
	return false;
}
