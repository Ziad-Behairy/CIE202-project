#include "Square.h"

Square::Square(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	center.x = (p1.x + p2.x) / 2;
	center.y = (p1.y + p2.y) / 2;
}

Square::~Square()
{
}

void Square::Draw(GUI* pUI) const
{
	pUI->DrawSqu(Corner1, Corner2, ShpGfxInfo);
}


bool Square::isinshape(int x, int y) const
{
	if (x >= min(Corner1.x, Corner2.x) && x <= max(Corner1.x, Corner2.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y))
		return true;
	else
		return false;
}


void Square::Move(int& x, int& y)
{
	int dx, dy;
	dx = abs(center.x - x);
	dy = abs(center.y - y);
	if (x >= center.x) {
		Corner1.x += dx;
		Corner2.x += dx;

	}                                                    //changing vertices x coocrdinates
	else {
		Corner1.x -= dx;
		Corner2.x -= dx;


	}
	if (y >= center.y) {
		Corner1.y += dy;
		Corner2.y += dy;

	}
	//changing vertices y coordinates
	else {
		Corner1.y -= dy;
		Corner2.y -= dy;


	}
	center.x = x;
	center.y = y;
}
void Square::Zoom(float& scale)
{

	// to keep the center fixed and not change it after scaling the shape first we transalte the shape to the origin then scale the shape then translate the shape again to the original postion 
	Corner1.x = (Corner1.x - center.x) * scale + center.x;
	Corner1.y = (Corner1.y - center.y) * scale + center.y;
	Corner2.x = (Corner2.x - center.x) * scale + center.x;
	Corner2.y = (Corner2.y - center.y) * scale + center.y;
}
string Square::printdata() const
{
	return string();

}

void Square::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "SQUARE " + to_string(ID) + "  " +
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
	int list[6];
	if (Corner1.y < Corner2.y) {
		list[0] = Corner1.x;
		list[1] = Corner1.y;
		list[2] = Corner2.x - 1;
		list[3] = Corner2.y - 1;
	}
	else
	{
		list[0] = Corner2.x-1;
		list[1] = Corner2.y-1;
		list[2] = Corner1.x;
		list[3] = Corner1.y;
	}
	list[4] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[5] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	/*list[4] = center.x;
	list[5] = center.y;*/
	return list;
}


