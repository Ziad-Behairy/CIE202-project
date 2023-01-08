#include "Circle.h"
#include"controller.h"
Circle::Circle(Point center, Point radius_p, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	this->center = center;
	this->radius_p = radius_p;
	this->shapeGfxInfo = shapeGfxInfo;
	raduis_dff = sqrt(pow((radius_p.x - center.x), 2) + pow((radius_p.y - center.y), 2));
}

Circle::Circle(const Circle* copy):shape(copy->ShpGfxInfo)
{
	this->center = copy->center;
	this->radius_p = copy->radius_p;
	this->raduis_dff = copy->raduis_dff;
	this->ID = copy->ID;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a Circle on the screen	
	pUI->DrawCir(center, radius_p, raduis_dff, ShpGfxInfo);//wait drawing function 
}

void Circle::Resize(double r)
{
	raduis_dff *= r;
}


bool Circle::isinshape(int x, int y) const
{
	//int Lradius = sqrt(pow((radius_p.x - center.x), 2) + pow((radius_p.y - center.y), 2));
	int distance = sqrt(pow((x - center.x), 2) + pow((y - center.y), 2));
	if (distance <= raduis_dff)

		return true;

	else
		return false;
}

void Circle::Move(int& x, int& y)
{
	center.x = x;
	center.y = y;
}

void Circle::Zoom(float& scale)
{
	// to keep the center fixed and not change it after scaling the shape first we transalte the shape to the origin then scale the shape then translate the shape again to the original postion 

	raduis_dff *= scale;
}

string Circle::printdata() const
{
	return string();
}

void Circle::SaveDataForShapes(ofstream& SaveFile, int ID)
{
	SaveFile << "CIRC " + to_string(ID) + "  " +

		+"  " +
		to_string(radius_p.x) + "  " +
		to_string(radius_p.y) + "  ";
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

int* Circle::getshapeparamters()
{
	int list[10];
	list[0] = center.x-raduis_dff;
	list[1] = center.y- raduis_dff;
	list[2] = center.x + raduis_dff;
	list[3] = center.y + raduis_dff;
	list[4] = raduis_dff*2;
	list[5] = raduis_dff *2;
	list[6] = center.x;
	list[7] = center.y;
	list[8] = raduis_dff;
	return list;

}

void Circle::Rotate()
{
}

void Circle::HideShape(GUI* pUI)
{
	if (IsHiden()) {
		int x = getshapeparamters()[0];
		int y = getshapeparamters()[1];
		int x2 = getshapeparamters()[2];
		int  y2 = getshapeparamters()[3];
		int width = getshapeparamters()[4];
		int height = getshapeparamters()[5];
		pUI->StickImage("images\\MenuIcons\\Card.jpg", x, y, width, height);
	}
}
