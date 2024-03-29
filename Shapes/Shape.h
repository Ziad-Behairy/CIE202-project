#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info

	/// Add more parameters if needed.

public:
	int getid();
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	bool IsHiden();
	void SetHiden(bool s);
	GfxInfo getGfxInfo();
	virtual void Draw(GUI* pUI) const = 0;		//Draw the shape

	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color

	virtual bool isinshape(int x, int y) const = 0;
	virtual string printdata() const = 0;
	void setisfilled();

	virtual void SaveDataForShapes(ofstream& SaveFile, int ID) = 0;
	string ConvertCoulourToString2(color anycolor);
	virtual int* getshapeparamters() = 0;

	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	

	
	virtual void Rotate() = 0;	//Rotate the shape
	virtual void Resize(double r) = 0;	//Resize the shape
	virtual void Zoom(float &) = 0;	//Zoom the shape
	virtual void Move(int&, int&) = 0;		//Move the shape
	virtual void HideShape(GUI* pUI) = 0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
};

