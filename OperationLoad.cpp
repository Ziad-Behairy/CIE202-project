#include "OperationLoad.h"
#include"GUI/GUI.h"
#include<fstream>
#include<iostream>
#include"Shapes/Shape.h"
#include"Line.h"
#include"Circle.h"
#include"Triangle.h"
#include"Square.h"
#include"Shapes/Rect.h"
#include"controller.h"
#include<iostream>
#include<string>
#include"string.h"
using namespace std;

OperationLoad::OperationLoad(controller* pcont):operation(pcont)
{
}

OperationLoad::~OperationLoad()
{
}

void OperationLoad::Execute()
{
	string Name;
	GUI* pUI = pControl->GetUI();
	pUI->ClearDrawArea();
	pUI->PrintMessage("enter the filename to load ");
	Name= pUI->GetSrting();
	ifstream loadingfile;
	string color1, color2;
	GfxInfo Info;
	int id;
	Point corner1, corner2, corner3;
	string shapeName, DrawColor, FillCol, BkGrndColor;
	int NumOfDrawnShapes;
	string str_NumOfDrawnShapes;
	shape* pshape;
	loadingfile.open(Name +".txt");
	while (loadingfile.fail())       //Check if the FileName is a valid name
	{
		pUI->PrintMessage("Invalid Name");
		Name = pUI->GetSrting();
		loadingfile.open(Name + ".txt");
		if (loadingfile.good())
			break;
		return;
	}
	Graph* pGraph = pControl->getGraph();
	string item;
	vector <string> shapesdata;
	//pControl->UpdateInterface();
	  //Draw the figure list
	loadingfile >> DrawColor >> FillCol >> BkGrndColor;     //Read the Current FillColor and 
	loadingfile >> str_NumOfDrawnShapes;
	NumOfDrawnShapes = stoi(str_NumOfDrawnShapes);
	//Info.BorderWdth = 3;
	//while (!loadingfile.eof())
	while (!loadingfile.eof())
	{
		getline(loadingfile, item, '\t');
		shapesdata.push_back(item);
	}
	for(int i=0;i< shapesdata.size(); i++)
	{
		if (shapesdata[i] == "CIRC" || shapesdata[i] == "\nCIRC") {
			cout << "circle";
			GfxInfo Info;
			corner1.x = stoi(shapesdata[i + 2]);
			corner1.y= stoi(shapesdata[i + 3]);
			corner2.x = stoi(shapesdata[i +4]);
			corner2.y = stoi(shapesdata[i +5]);
			color colour1 = pControl-> ConvertStringToCoulour((shapesdata[i + 6]));
			color colour2 = pControl->ConvertStringToCoulour((shapesdata[i + 7]));
			//Info.DrawClr = colour1;
			Info.DrawClr = colour1;
			Info.BorderWdth = 3;
			if (color2 != "NO_FILL") {
				color colour2 = pControl->ConvertStringToCoulour(color2);
				Info.FillClr = colour2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			Info.isSelected = false;

		  pshape = new Circle(corner1, corner1, Info);
		  pUI->DrawCir(corner1, corner1, Info);
			pGraph->Addshape(pshape);
		}
		else if (shapeName == "LINE"|| shapeName == "\nLINE") {
			cout << "l";
			GfxInfo Info;
			corner1.x = stoi(shapesdata[i + 2]);
			corner1.y = stoi(shapesdata[i + 3]);
			corner2.x = stoi(shapesdata[i +4]);
			corner2.y = stoi(shapesdata[i + 5]);
			color colour1 = pControl->ConvertStringToCoulour((shapesdata[i + 6]));
			color colour2 = pControl->ConvertStringToCoulour((shapesdata[i + 7]));
			Info.DrawClr = colour1;
			Info.BorderWdth = 3;
			if (color2 != "NO_FILL") {
				color colour2 = pControl->ConvertStringToCoulour(color2);
				Info.FillClr = colour2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			Info.isSelected = false;
			 pshape = new Line(corner1, corner1, Info);
			 pUI->DrawLin(corner1, corner1, Info);
			pGraph->Addshape(pshape);
		}
		else if (shapeName == "RECT"|| shapeName == "\nRECT") {
			GfxInfo Info;
			corner1.x = stoi(shapesdata[i + 2]);
			corner1.y = stoi(shapesdata[i + 3]);
			corner2.x = stoi(shapesdata[i + 4]);
			corner2.y = stoi(shapesdata[i + 5]);
			color colour1 = pControl->ConvertStringToCoulour((shapesdata[i + 6]));
			color colour2 = pControl->ConvertStringToCoulour((shapesdata[i + 7]));
			Info.DrawClr = colour1;
			Info.BorderWdth = 3;
			if (color2 != "NO_FILL") {
				color colour2 = pControl->ConvertStringToCoulour(color2);
				Info.FillClr = colour2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			Info.isSelected = false;

		    pshape = new Rect(corner1, corner1, Info);
			pUI->DrawRect(corner1, corner1, Info);
			pGraph->Addshape(pshape);
		}
		else if (shapeName == "SQUARE"||shapeName == "\nSQUARE") {
			GfxInfo Info;
			corner1.x = stoi(shapesdata[i + 2]);
			corner1.y = stoi(shapesdata[i + 3]);
			corner2.x = stoi(shapesdata[i + 4]);
			corner2.y = stoi(shapesdata[i + 5]);
			color colour1 = pControl->ConvertStringToCoulour((shapesdata[i + 6]));
			color colour2 = pControl->ConvertStringToCoulour((shapesdata[i + 7]));
			Info.DrawClr = colour1;
			Info.BorderWdth = 3;
			if (color2 != "NO_FILL") {
				color colour2 = pControl->ConvertStringToCoulour(color2);
				Info.FillClr = colour2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			Info.isSelected = false;

		    pshape = new Square(corner1, corner1, Info);
			pUI->DrawSqu(corner1, corner1, Info);
			pGraph->Addshape(pshape);
		}
		else if (shapeName == "TRIANGLE"|| shapeName == "TRIANGLE") {
		GfxInfo Info;
		corner1.x = stoi(shapesdata[i + 2]);
		corner1.y = stoi(shapesdata[i + 3]);
		corner2.x = stoi(shapesdata[i + 4]);
		corner2.y = stoi(shapesdata[i + 5]);
		corner3.x = stoi(shapesdata[i + 6]);
		corner3.y = stoi(shapesdata[i + 7]);
		color colour1 = pControl->ConvertStringToCoulour((shapesdata[i + 8]));
		color colour2 = pControl->ConvertStringToCoulour((shapesdata[i + 9]));
			Info.DrawClr = colour1;
			Info.BorderWdth = 3;
			if (color2 != "NO_FILL") {
				color colour2 = pControl->ConvertStringToCoulour(color2);
				Info.FillClr = colour2;
				Info.isFilled = true;
			}
			else {
				//color c2 = pManager->ConvertToColor("LIGHTGOLDENRODYELLOW");
				Info.isFilled = false;
				Info.FillClr = NULL;
			}
			Info.isSelected = false;
			//pOp= new Triangle(corner1, corner1, corner2, Info);

		  Triangle* pshape = new Triangle(corner1, corner2, corner3, Info);
		   //pUI->DrawTri(corner1, corner2, corner3, Info);
		   pGraph->Addshape(pshape);
		}

	}
	loadingfile.close();
	pUI->PrintMessage("Drawing Loaded Successfully");
	//pUI->ClearStatusBar();
	//pUI->CreateStatusBar();
	//pUI->PrintMessage("Drawing Loaded Successfully");
	
}
