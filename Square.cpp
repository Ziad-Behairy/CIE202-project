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

void Square::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "Square" + to_string(ID) + "  " +
		to_string(Corner1.x) + "  " +
		to_string(Corner1.y) + "  " +
		to_string(Corner2.x) + "  " +
		to_string(Corner2.y) + "  ";
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

int* Square::getshapeparamters()
{
	int list[4];
	list[0] = Corner1.x;
	list[1] = Corner2.y;
	list[2] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[3] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	return list;
}

