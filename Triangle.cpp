#include "Triangle.h"
Triangle::Triangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	center.x = (P1.x + P2.x + P3.x) / 3;
	center.y = (P1.y + P2.y + P3.y) / 3;
}

Triangle::~Triangle()
{}

void Triangle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a triangle on the screen	
	pUI->DrawTri(Corner1, Corner2, Corner3, ShpGfxInfo);
}

bool Triangle::isinshape(int x, int y) const

{
	//Ax(By - Cy) + Bx(Cy - Ay) + Cx(Ay - By) divided by 2 (using triple scaler product)
	//double area1 = (1 / 2) * abs(x * (Corner1.y - Corner2.y) + Corner1.x * (Corner2.y - y) + Corner2.x * (y - Corner1.y));
	//double area2 = (1 / 2) * abs(x * (Corner1.y - Corner3.y) + Corner1.x * (Corner3.y - y) + Corner3.x * (y - Corner1.y));
	//double area3 = (1 / 2) * abs(x * (Corner3.y - Corner2.y) + Corner3.x * (Corner2.y - y) + Corner2.x * (y - Corner3.y));
	//double area = (1 / 2) * abs(Corner1.x * (Corner2.y - Corner3.y) + Corner2.x * (Corner3.y - Corner1.y) + Corner3.x * (Corner1.y - Corner2.y));

	//abs(0.5 * ((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)));
	double area1 = abs(0.5 * ((x - Corner2.x) * (y - Corner3.y) - (x - Corner3.x) * (y - Corner2.y)));
	double area2 = abs(0.5 * ((x - Corner2.x) * (y - Corner1.y) - (x - Corner1.x) * (y - Corner2.y)));
	double area3 = abs(0.5 * ((x - Corner1.x) * (y - Corner3.y) - (x - Corner3.x) * (y - Corner1.y)));

	double TotalArea = area1 + area2 + area3;
	double area = abs(0.5 * ((Corner2.x - Corner1.x) * (Corner2.y - Corner3.y) - (Corner2.x - Corner3.x) * (Corner2.y - Corner1.y)));

	if (TotalArea == area)
		return true;
	else
	{
		return false;

	}
}

string Triangle::printdata() const
{
	return string();
}

void Triangle::Zoom(float& scale)
{

		// to keep the center fixed and not change it after scaling the shape first we transalte the shape to the origin then scale the shape then translate the shape again to the original postion 

	Corner1.x = (Corner1.x - center.x) * scale + center.x;
	Corner1.y = (Corner1.y - center.y) * scale + center.y;
	Corner2.x = (Corner2.x - center.x) * scale + center.x;
	Corner2.y = (Corner2.y - center.y) * scale + center.y;
	Corner3.x = (Corner3.x - center.x) * scale + center.x;
	Corner3.y = (Corner3.y - center.y) * scale + center.y;


}


void Triangle::Move(int& x, int& y)
{
	int dx, dy;
	dx = abs(center.x - x);
	dy = abs(center.y - y);
	if (x > center.x) {
		Corner1.x += dx;
		Corner2.x += dx;
		Corner3.x += dx;
	}
	else
	{
		Corner1.x -= dx;
		Corner2.x -= dx;
		Corner3.x -= dx;
	}
	if (y > center.y) {
		Corner1.y += dy;
		Corner2.y += dy;
		Corner3.y += dy;
	}
	else
	{
		Corner1.y -= dy;
		Corner2.y -= dy;
		Corner3.y -= dy;
	}
	center.x = (Corner1.x + Corner2.x + Corner3.x) / 3;
	center.y = (Corner1.y + Corner2.y + Corner3.y) / 3;
}

void Triangle::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "TRIANGLE " + to_string(ID) + "  " +
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

int* Triangle::getshapeparamters()
{
	int list[6];
	int y1= Corner2.y- sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[0] = Corner2.x-4;
	list[1] = y1;
	list[5] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)))+5;
	list[4] = sqrt(pow((Corner2.x - Corner3.x), 2) + (pow((Corner2.y - Corner3.y), 2)))+5;
	return list;
}

void Triangle::Resize(double r)
{
	Corner1.x = (Corner1.x - center.x) * r + center.x;
	Corner1.y = (Corner1.y - center.y) * r + center.y;
	Corner2.x = (Corner2.x - center.x) * r + center.x;
	Corner2.y = (Corner2.y - center.y) * r + center.y;
	Corner3.x = (Corner3.x - center.x) * r + center.x;
	Corner3.y = (Corner3.y - center.y) * r + center.y;
}


