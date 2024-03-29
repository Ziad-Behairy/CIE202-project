#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

#include <string>
using namespace std;

struct Point	//To be used for shapes points
{
	int x, y;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	bool IsHiden=0;
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY//Playing mode

	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC,		//Circle icon in menu

		//TODO: Add more icons names here
		ICON_SQU,		//Square icon in menu
		//ICON_OVAL,		//Oval icon in menu
		ICON_LINE,		//Line icon in menu
		ICON_TRI,		//Line icon in menu
		ICON_REGPOL,	//Regular polygon icon in menu
		ICON_IRREGPOL,	//Irregular polygon icon in menu
		ICON_FILL,		//Fill icon in menu
		ICON_COLORPAL,	//Color palette  icon in menu
		//ICON_palette,
		//ICON_PEN,		//Pen  icon in menu
		ICON_SELECT,	//Select  icon in menu
		ICON_RESIZE,	//Resize  icon in menu
		ICON_ROTATE,	//Rotate  icon in menu
		ICON_MOVE,
		ICON_ZOOM_IN,	//Zoom in  icon in menu
		ICON_ZOOM_OUT,	//Zoom out  icon in menu
		ICON_COPY,	    //Copy  icon in menu
		//ICON_CUT,	    //Cut  icon in menu
		ICON_PASTE,	    //Paste  icon in menu
		ICON_UNDO,	    //Undo  icon in menu
		ICON_REDO,	    //Undo  icon in menu
		ICON_DELETE,	//Delete  icon in menu
		ICON_HIDE,
		ICON_SCRAMBEL,	//Scrambel  icon in menu
		ICON_DUPLICATE, // Duplicate icon in menu
		ICON_SAVE,	    //Save  icon in menu
		ICON_LOAD,	    //Load  icon in menu
		ICON_PLAYMODE,	//Play mode  icon in menu
		ICON_EXIT,		//Exit icon

		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here

		//TODO: Add more icons names here
		ICON_START,
		ICON_RESTART,
		ICON_UNHIDE,
		ICON_STICK_IMAGE,
		

		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};


	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes

	/// Add more members if needed
	window* pWind;

public:

	GUI();

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation

	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	window* getwind();
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearWind() const; //clear whole  window to move to pla
	void ClearStatusBar() const;	//Clears the status play_mode
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawLin(Point P1, Point P2, GfxInfo LineGfxInfo) const; //Draw a line 
	void DrawCir(Point P1, Point P2, int raduis_dif, GfxInfo CirGfxInfo) const; //Draw a Circle 
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo) const; //Draw a triangle 
	void DrawSqu(Point P1, Point P2, GfxInfo SquGfxInfo) const;//Draw a square

	void DrawIrrPoly(int* x, int* y, int vertices_num, GfxInfo IrrpolyGfxInfo) const;//Draw a Irrpolygon
	void DrawPoly(int* x, int* y, int vertices_num, GfxInfo PolyGfxInfo) const;//Draw a polygon
	void StickImage(string photo, int x, int y, int width, int hight) const;//Draw a square

	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar
	int Get_Mode() const;
	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	color getBkGrndColor() const;


	~GUI();
};

