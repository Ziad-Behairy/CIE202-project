#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	center.x = (P1.x + P2.x) / 2;
	center.y = (P1.y + P2.y) / 2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

void Rect::Move(int& x, int& y)
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


bool Rect::isinshape(int x, int y) const
{
	if (x >= min(Corner1.x, Corner2.x) && x <= max(Corner1.x, Corner2.x) && y >= min(Corner1.y, Corner2.y) && y <= max(Corner1.y, Corner2.y))
		return true;
	else
		return false;
}

string Rect::printdata() const
{
	return string();
}


	

void Rect::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "RECT " + to_string(ID) + "  " +
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

int * Rect::getshapeparamters()
{
	int list[4];
	list[0] = Corner1.x;
	list[1] = Corner2.y;
	list[2] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[3] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	return list;
}



