#include "shape.h"

shape::shape(GfxInfo shapeGfxInfo)
{
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}

void shape::SetSelected(bool s)
{
	ShpGfxInfo.isSelected = s;
}

bool shape::IsSelected() const
{
	return ShpGfxInfo.isSelected;
}
bool shape::IsHiden()
{
	return ShpGfxInfo.IsHiden;
}
void shape::SetHiden(bool s)
{
	ShpGfxInfo.IsHiden = s;
}

GfxInfo shape::getGfxInfo()
{
	return ShpGfxInfo;
}

void shape::ChngDrawClr(color Dclr)
{
	ShpGfxInfo.DrawClr = Dclr;
}

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}


void shape::setisfilled()
{
	ShpGfxInfo.isFilled = true;

}
string shape::ConvertCoulourToString2(color anycolor)
{
	if (anycolor == BLACK) return "BLACK";
	else if (anycolor == WHITE) return "WHITE";
	else if (anycolor == BLUE) return "BLUE";
	else if (anycolor == RED) return "RED";
	else if (anycolor == YELLOW) return "YELLOW";
	else if (anycolor == GREEN) return "GREEN";
	else if (anycolor == GREY) return "GREY";
	else if (anycolor == LIGHTGOLDENRODYELLOW) return "LIGHTGOLDENRODYELLOW";
	return "COLOR";

}

