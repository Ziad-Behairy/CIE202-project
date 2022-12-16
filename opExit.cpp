#include "opExit.h"
#include "controller.h"
#include"GUI/GUI.h"
#include"controller.h"
#include"OperationSave.h"
#include "operations/operation.h"
opExit::opExit(controller* pcont):operation(pcont)
{
}
opExit::~opExit()
{
}
void opExit::Execute() {
	GUI* pUI = pControl->GetUI();
	pUI->ClearDrawArea();
	Sleep(100);
	pUI->ClearStatusBar();
	Sleep(100);
	pUI->PrintMessage("Cleaning...");
	Sleep(100);
	//pManager->SaveCircuit();

	pUI-> PrintMessage("Exiting the program...");
	Sleep(100);
}
