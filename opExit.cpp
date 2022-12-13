#include "opExit.h"
#include"controller.h"
#include"OperationSave.h"
#include<windows.h>
#include"GUI/GUI.h"

opExit::opExit(controller* pCont) :operation(pCont)
{
};

opExit::~opExit(void)
{
};

void opExit::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->ClearDrawArea();
	Sleep(200);
	pUI->ClearStatusBar();
	Sleep(200);
	pUI->PrintMessage("Cleaning...");
	Sleep(200);
	pUI->PrintMessage("Exiting the program...");
	Sleep(200);
	
}
