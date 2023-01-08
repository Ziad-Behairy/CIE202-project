#include "opAddPlay_Mode.h"
#include "controller.h"
#include "GUI/GUI.h"
#include "GUI/GUI.h"
//Execute the operation
void opAddPlay_Mode::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	//pUI->ClearDrawArea();
	pUI->ClearWind();// Clear the whole window to create play_mode window 
	pUI->CreatePlayToolBar();
	pUI->CreateStatusBar();
	pUI->ClearDrawArea();
}

opAddPlay_Mode::opAddPlay_Mode(controller* pCont) :operation(pCont)
{

}

opAddPlay_Mode::~opAddPlay_Mode()
{
}
void opAddPlay_Mode::Undo()
{
}

void opAddPlay_Mode::Redo()
{
}