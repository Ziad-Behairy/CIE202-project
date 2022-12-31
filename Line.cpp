#include "Line.h"
#include <math.h>
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawLin(Corner1, Corner2, ShpGfxInfo);
}


bool Line::isinshape(int x, int y) const
{
	// y = mx + c
	//c= y1 - (slope(m)) * x1 // intercept
	//int slope = (Corner2.y - Corner1.y) / (Corner2.x - Corner1.x);
	//int c = Corner1.y - slope * Corner1.x; // intercept
	int ab = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
	int pa= sqrt(pow(x - Corner1.x, 2) + pow(y - Corner1.y, 2));
	int pb = sqrt(pow(x - Corner2.x, 2) + pow(y - Corner2.y, 2));
	if (ab == (pa+pb))
		return true;
	else
		return false;
}

string Line::printdata() const
{
	return string();
}

void Line::SaveDataForShapes(ofstream &SaveFile, int ID)
{
	SaveFile<< "LINE " + to_string(ID) + "  " +
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

int* Line::getshapeparamters()
{
	int list[4];
	list[0] = Corner1.x;// get x
	list[1] = Corner2.y;//get y
	list[2] =  sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));//get width
	list[3] =  sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));// get height
	return list;
}


