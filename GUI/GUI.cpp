#include "GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1600;
	height = 795;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 60;
	MenuIconWidth = 58;

	DrawColor = RED;	//default Drawing color
	FillColor = WHITE;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames


	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^&^ PLAY - - - - - - - - - -");
	//CreatePlayToolBar();
	CreateDrawToolBar();
	CreateStatusBar();
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if (Label.size() > 0)
				Label.resize(Label.size() - 1);
			else
				Key = '\0';
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_SQU: return DRAW_SQU;
			case ICON_LINE: return DRAW_LINE;
			case ICON_TRI: return DRAW_TRI;
				//case ICON_OVAL: return DRAW_OVAL;
			case ICON_REGPOL: return DRAW_REGPOL;
			case ICON_IRREGPOL: return DRAW_IRREGPOL;
			case ICON_EXIT: return EXIT;
			case ICON_SAVE: return SAVE;
			case ICON_LOAD: return LOAD;
			case ICON_COLORPAL: return CHNG_DRAW_CLR;
			case ICON_FILL: return CHNG_FILL_CLR;
			case ICON_PLAYMODE: return TO_PLAY;
			case ICON_SELECT: return SELECT;
			case ICON_DELETE: return DEL;
			case ICON_HIDE: return HIDE;
				//case ICON_UNDO: return UNDO;
				//case ICON_REDO: return REDO;
				//case ICON_COPY: return COPY;
				//case ICON_CUT: return CUT;
				//case ICON_PASTE: return PASTE;
			case ICON_SCRAMBEL: return SCRAMBEL;
			//case ICON_DUPLICATE: return DUPLICATE;
			 case ICON_ZOOM_IN: return ZOOM_IN;
			 case ICON_ZOOM_OUT: return ZOOM_OUT;
            case ICON_ROTATE: return ROTATE; 
			case ICON_RESIZE: return RESIZE;  





			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		//InterfaceMode == MODE_PLAY;
		///TODO:
		//perform checks similar to Draw mode checks above
		//and return the correspoding operation
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_START: return START_PLAY;
			case ICON_RESTART: return RESTART_PLAY;
			case ICON_STICK_IMAGE: return STICK_IMAGE;






			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		/*if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}*/

		//[3] User clicks on the status bar
		return STATUS;
	}


	return TO_PLAY;	//just for now. This should be updated
}


////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}

//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearWind() const
{
	//Clear window by drawing a filled white rectangle
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, width, height);
}
window* GUI::getwind() {
	return pWind;
}

//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar()
{
	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circ.jpg";
	MenuIconImages[ICON_SQU] = "images\\MenuIcons\\Menu_Squ.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	//MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_Oval.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_Line.jpg";
	MenuIconImages[ICON_REGPOL] = "images\\MenuIcons\\Menu_Regpol.jpg";
	MenuIconImages[ICON_IRREGPOL] = "images\\MenuIcons\\Menu_IRRegpol.jpg";
	MenuIconImages[ICON_FILL] = "images\\MenuIcons\\Menu_Fill.jpg";
	MenuIconImages[ICON_COLORPAL] = "images\\MenuIcons\\Menu_ColorPal.jpg";
	//MenuIconImages[ICON_PEN] = "images\\MenuIcons\\Menu_Pen.jpg";
	MenuIconImages[ICON_SELECT] = "images\\MenuIcons\\Menu_Select.jpg";
	MenuIconImages[ICON_RESIZE] = "images\\MenuIcons\\Menu_RESIZE.jpg";
	MenuIconImages[ICON_ROTATE] = "images\\MenuIcons\\Menu_ROTATE.jpg";
	MenuIconImages[ICON_ZOOM_IN] = "images\\MenuIcons\\Menu_ZOOMIN.jpg";
	MenuIconImages[ICON_ZOOM_OUT] = "images\\MenuIcons\\Menu_ZOOMOUT.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\Menu_COPY.jpg";
	//MenuIconImages[ICON_CUT] = "images\\MenuIcons\\Menu_CUT.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\Menu_PASTE.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\Menu_UNDO.jpg";
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\Menu_REDO.jpg";
	MenuIconImages[ICON_DELETE] = "images\\MenuIcons\\Menu_Delete.jpg";
	MenuIconImages[ICON_HIDE] = "images\\MenuIcons\\Menu_HIDE.jpg";
	MenuIconImages[ICON_SCRAMBEL] = "images\\MenuIcons\\Menu_SCRAMBEL.jpg";
	MenuIconImages[ICON_DUPLICATE] = "images\\MenuIcons\\Menu_DUPLICATE.jpg";
	MenuIconImages[ICON_SAVE] = "images\\MenuIcons\\Menu_Save.jpg";
	MenuIconImages[ICON_LOAD] = "images\\MenuIcons\\Menu_Load.jpg";
	MenuIconImages[ICON_PLAYMODE] = "images\\MenuIcons\\Menu_PlayMode.jpg";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSEAGREEN, 4);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar()
{
	pWind->ChangeTitle("- - - - - - - - - - PLAY MODE - - - - - - - - - -");

	InterfaceMode = MODE_PLAY;
	string MenuIconImages[PLAY_ICON_COUNT];
	MenuIconImages[ICON_START] = "images\\MenuIcons\\Menu_START.jpg";
	MenuIconImages[ICON_RESTART] = "images\\MenuIcons\\Menu_RESTART.jpg";
	MenuIconImages[ICON_STICK_IMAGE] = "images\\MenuIcons\\Menu_STICK_IMAGE.jpg";
	///TODO: write code to create Play mode menu
	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * 90, 0, 90, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSEAGREEN, 4);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "SWISS");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{
	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntFillColor() const	//get current filling color
{
	return FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////


int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}



color GUI::getBkGrndColor() const
{
	return BkGrndColor;
}

int GUI::Get_Mode() const
{
	return InterfaceMode;

}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	if ((P1.y > ToolBarHeight + 2 && P2.y > ToolBarHeight + 2) && (P1.y < height - StatusBarHeight && P2.y < height - StatusBarHeight))
	{
		color DrawingClr;
		if (RectGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = RectGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (RectGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(RectGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
		ClearStatusBar();
	}
	else
	{
		PrintMessage("Please select points in limits of drawing area ");
	}
}
void GUI::DrawLin(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	if ((P1.y > ToolBarHeight + 2 && P2.y > ToolBarHeight + 2) && (P1.y < height - StatusBarHeight && P2.y < height - StatusBarHeight))
	{
		color DrawingClr;
		if (LineGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = LineGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, 5);	//Set Drawing color & width

		drawstyle style;
		if (LineGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(LineGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
		ClearStatusBar();
	}

	else
	{
		PrintMessage("Please select points in limits of drawing area ");
	}

}
void GUI::DrawCir(Point P1, Point P2, int raduis_dif, GfxInfo CirGfxInfo) const
{
	int iRadius = raduis_dif;
	const int Max_Raduis_up = sqrt(pow(P1.y - ToolBarHeight, 2)); // raduis from center to toolbar
	const int Max_Raduis_down = sqrt(pow(P1.y - (height - StatusBarHeight), 2)); // raduis from center to statusbar
	string s = to_string(Max_Raduis_up), r = to_string(iRadius), d = to_string(P2.x), z = to_string(P2.y);
	if ((P1.y > ToolBarHeight + 2 && P2.y > ToolBarHeight + 2) && (P1.y < height - StatusBarHeight && P2.y < height - StatusBarHeight) && (iRadius < Max_Raduis_up) && (iRadius < Max_Raduis_down))
	{


		PrintMessage("raduis = " + r + " max= " + s + "p2= " + d + " " + z);
		color DrawingClr;
		if (CirGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = CirGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, CirGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (CirGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(CirGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawCircle(P1.x, P1.y, raduis_dif, style);
		ClearStatusBar();
	}
	else
	{
		PrintMessage("Please select points in limits of drawing area ");
	}

}
void GUI::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const
{
	if ((P1.y > ToolBarHeight + 2 && P2.y > ToolBarHeight + 2 && P3.y > ToolBarHeight + 2) && (P1.y < height - StatusBarHeight && P2.y < height - StatusBarHeight && P3.y < height - StatusBarHeight))
	{
		color DrawingClr;
		if (TriGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = TriGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, TriGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (TriGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(TriGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
		ClearStatusBar();
	}
	else
	{
		PrintMessage("Please select points in limits of drawing area ");
	}
}
void GUI::DrawSqu(Point P1, Point P2, GfxInfo SquGfxInfo) const
{
	int second_corner_y = P1.y + (P2.x - P1.x);
	if ((P1.y > ToolBarHeight + 2 && P2.y > ToolBarHeight + 2) && (P1.y < height - StatusBarHeight && second_corner_y < height - StatusBarHeight))
	{
		color DrawingClr;
		if (SquGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = SquGfxInfo.DrawClr;

		pWind->SetPen(DrawingClr, SquGfxInfo.BorderWdth);	//Set Drawing color & width

		drawstyle style;
		if (SquGfxInfo.isFilled)
		{
			style = FILLED;
			pWind->SetBrush(SquGfxInfo.FillClr);
		}
		else
			style = FRAME;

		const int Squ_length = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));
		pWind->DrawRectangle(P1.x, P1.y, P2.x, P1.y + (P2.x - P1.x), style);
		ClearStatusBar();
	}
	else
	{
		PrintMessage("Please select points in limits of drawing area ");
	}
}
void GUI::DrawIrrPoly(int* x, int* y, int vertices_num, GfxInfo IrrpolyGfxInfo) const
{
	color DrawingClr;
	if (IrrpolyGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = IrrpolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, IrrpolyGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (IrrpolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(IrrpolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(x, y, vertices_num, style);
	ClearStatusBar();

}
void GUI::DrawPoly(int* x, int* y, int vertices_num, GfxInfo PolyGfxInfo) const
{
	color DrawingClr;
	if (PolyGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolyGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(x, y, vertices_num, style);
	ClearStatusBar();

}

void GUI::StickImage(string photo, int x, int y, int width, int hight) const
{
	pWind->DrawImage(photo, x, y, width, hight);

}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

