#include "Rect.h"

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
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

void Rect::Zoom(float& scale)
{
	// to keep the center fixed and not change it after scaling the shape first we transalte the shape to the origin then scale the shape then translate the shape again to the original postion 

	Corner1.x = (Corner1.x - center.x) * scale + center.x;
	Corner1.y = (Corner1.y - center.y) * scale + center.y;
	Corner2.x = (Corner2.x - center.x) * scale + center.x;
	Corner2.y = (Corner2.y - center.y) * scale + center.y;
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

void Rect::Resize(double r)
{
	Corner1.x = (Corner1.x - center.x) * r + center.x;
	Corner1.y = (Corner1.y - center.y) * r + center.y;
	Corner2.x = (Corner2.x - center.x) * r + center.x;
	Corner2.y = (Corner2.y - center.y) * r + center.y;
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

int* Rect::getshapeparamters()
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
		list[0] = Corner2.x - 1;
		list[1] = Corner2.y - 1;
		list[2] = Corner1.x;
		list[3] = Corner1.y;
	}
	list[4] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	list[5] = sqrt(pow((Corner2.x - Corner1.x), 2) + (pow((Corner2.y - Corner1.y), 2)));
	/*list[4] = center.x;
	list[5] = center.y;*/
	return list;
}

void Rect::Rotate()
{
	int temp1x = Corner1.x;
	int temp1y = Corner1.y;
	int temp2x = Corner2.x;
	int temp2y = Corner2.y;
	Corner1.x = -temp1y + center.y + center.x;
	Corner1.y = temp1x - center.x + center.y;
	Corner2.x = -temp2y + center.y + center.x;
	Corner2.y = temp2x - center.x + center.y;
}



