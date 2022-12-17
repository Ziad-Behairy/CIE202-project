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
bool Triangle::isinshape(int x, int y) const

{
	//Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By) divided by 2 (using triple scaler product)
	//double area1 = (1 / 2) * abs(x * (Corner1.y - Corner2.y) + Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y));
	//double area2 = (1 / 2) * abs(x * (Corner1.y - Corner3.y) + Corner1.x * (Corner3.y - y) + Corner3.x * (y - Corner1.y));
	//double area3 = (1 / 2) * abs(x * (Corner3.y - Corner2.y) + Corner3.x * (Corner2.y - y) + Corner2.x * (y - Corner3.y));
	//double area = (1 / 2) * abs(Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y));

	//abs(0.5 * ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)));
	double area1= abs(0.5 * ((x - Corner2.x) * (y - Corner3.y) - (x - Corner3.x) * (y - Corner2.y)));
	double area2 = abs(0.5 * ((x - Corner2.x) * (y - Corner1.y) - (x - Corner1.x) * (y - Corner2.y)));
	double area3= abs(0.5 * ((x - Corner1.x) * (y - Corner3.y) - (x - Corner3.x) * (y - Corner1.y)));
	
	double TotalArea = area1 + area2 + area3;
	double area = abs(0.5 * ((Corner2.x - Corner1.x) * (Corner2.y - Corner3.y) - (Corner2.x - Corner3.x) * (Corner2.y - Corner1.y)));
	
	if (TotalArea == area)
		return true;
	else
	{
		return false;

	}
}
