#include "Triangle.h"
Triangle::Triangle(Point P1, Point P2,Point P3,GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pUI->DrawTri(Corner1, Corner2,Corner3,ShpGfxInfo);
}

void Triangle::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "TRIANGLE" + to_string(ID) + "  " +
		to_string(Corner1.x) + "  " +
		to_string(Corner1.y) + "  " +
		to_string(Corner2.x) + "  " +
		to_string(Corner2.y) + "  " +
		to_string(Corner3.x) + "  " +
		to_string(Corner3.y) + "  ";

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

