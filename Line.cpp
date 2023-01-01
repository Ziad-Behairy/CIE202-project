#include "Line.h"
#include <math.h>
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	center.x = (P1.x + P2.x) / 2;
	center.x = (P1.y + P2.y) / 2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawLin(Corner1, Corner2, ShpGfxInfo);
}

void Line::Move(int& x, int& y)
{
	int dx;
	int dy;




	dx = abs(center.x - x);
	dy = abs(center.y - y);


	if (x > center.x) {
		Corner1.x += dx;
		Corner2.x += dx;
	}
	else
	{
		Corner1.x -= dx;
		Corner2.x -= dx;


	}

	if (y > center.y) {
		Corner1.y += dy;
		Corner2.y += dy;
	}
	else
	{
		Corner1.y -= dy;
		Corner2.y -= dy;


	}

	center.x = (Corner1.x + Corner2.x) / 2;
	center.y = (Corner1.y + Corner2.y) / 2;



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

void Line::Resize(double r)
{
	double midx = (Corner1.x + Corner2.x) / 2;		
	double midy= (Corner1.y + Corner2.y) / 2;
	int dx1 = Corner1.x - midx;
	int dy1 = Corner1.y - midy;
	int dx2 = Corner2.x - midx;
	int dy2 = Corner2.y - midy;
	Corner1.x = midx + (dx1 * r);
	Corner1.y = midy + (dy1 * r);
	Corner2.x = midx + (dx2 * r);
	Corner2.y = midy + (dy2 * r);

	/*Corner1.x = Corner1.x*r;
	Corner1.y = Corner1.y*r;
	Corner2.x = Corner2.x*r;
	Corner2.y = Corner2.y*r;*/
}

void Line::Rotate()
{
	cout << "alo";
}


