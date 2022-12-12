#include "OperationSave.h"
#include "controller.h"
#include"GUI/GUI.h"
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstring>
#include <string>
#include"Shapes/Shape.h"
#include <fstream>
OperationSave::~OperationSave()
{
}

OperationSave::OperationSave(controller* pcont, int num) :operation(pcont)
{
	FileName = "DrawnShapes";
	NumOfDrawnShapes = num;
}

string OperationSave::GetFileName()
{
	return FileName;
}

shape* OperationSave::GetDrawnshapelist()
{
	return DrawnShapelist[MaxDrawnShapes];
}

int OperationSave::GetNumOfDrawnShapes()
{
	return NumOfDrawnShapes;
}

void OperationSave::SetDrawnShapelist(shape* newDrawnShapelist[MaxDrawnShapes])
{
	for (int i = 0; i < MaxDrawnShapes; i++)
	{
		DrawnShapelist[i] = newDrawnShapelist[i];
	}
}

void OperationSave::SetNumOfDrawnShapes(int newNumOfDrawnShapes)
{
	NumOfDrawnShapes = newNumOfDrawnShapes;
}

void OperationSave::SetFileName(string newFileName)
{
	FileName = newFileName;
}

void OperationSave::Execute()
{
	//Get a Pointer to the user Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("lets Save our drawings .. pleaes enter file name");
	string FileName = pUI->GetSrting();
	ofstream SaveFile;
	SaveFile.open(FileName + ".txt");  // create a file with FileName and .txt exetention
	while (SaveFile.fail())
	{
		pUI->PrintMessage("Please write a valid name then press ENTER");
		FileName = pUI->GetSrting();
		SaveFile.open(FileName + ".txt");
		if (SaveFile.good())
			break;
	}
	string FillCol;
	if (pUI->getCrntFillColor() == NULL)
	{
		FillCol = "NO_FILL";
	}
	else {
		FillCol = pControl->ConvertCoulourToString(pUI->getCrntFillColor());
	}
	SaveFile << pControl->ConvertCoulourToString(pUI->getCrntDrawColor());
	SaveFile << "\t" << FillCol;
	SaveFile << "\t" << pControl->ConvertCoulourToString(pUI->getBkGrndColor());
	SaveFile << "\n";  //Write the Current Draw Color 
	SaveFile << NumOfDrawnShapes << "\n";  //and Current Fill Color and in the second line write the number of figures 

	for (int i = 0; i < NumOfDrawnShapes; i++) {
		DrawnShapelist[i]-> SaveDataForShapes(SaveFile,(i + 1));
	}
	SaveFile.close(); //close the file 
	//Print Action Message'
	pUI->PrintMessage("Drawing SAVED");  //Done

}
