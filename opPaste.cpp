#include "opPaste.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
#include"controller.h"
#include <iostream>
#include"Circle.h"
#include"Line.h"
#include"Square.h"
#include"Shapes/Rect.h"
#include"Triangle.h"
using namespace std;
opPaste::opPaste(controller* pcont):operation(pcont)
{
}

opPaste::~opPaste()
{
}

void opPaste::Execute()
{
	Point P;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
	pUI->PrintMessage("Click At The Location you want to paste the items at");

	//Read 1 Center and store in point and Radius.
	pUI->GetPointClicked(P.x, P.y);
	pUI->ClearStatusBar();	
	//int copiedCounter = pApp->getCopiedCounter();
	shape* shapeCopied = pGraph->getCopied();
	Point refPoint;
	//for (int i = 0; i < copiedCounter; i++) {
		//std::cout << FiguresCopied[i]->print();;
	Circle* pocir = dynamic_cast<Circle*>(shapeCopied);
	Rect* porect = dynamic_cast<Rect*>(shapeCopied);
	Triangle* potrig = dynamic_cast<Triangle*>(shapeCopied);
	Line* poline = dynamic_cast<Line*>(shapeCopied);
	Square* poSquare = dynamic_cast<Square*>(shapeCopied);

		if (pocir!=NULL) {
			//if (i == 0) {
				//refPoint = posscir->getCenter();
			//}
			
			refPoint.x = pocir->getshapeparamters()[6];
			refPoint.y = pocir->getshapeparamters()[7];
			Point orgcen;
			orgcen.x =pocir->getshapeparamters()[6];
			orgcen.y = pocir->getshapeparamters()[7];
			int orgrad = pocir->getshapeparamters()[8];
			//inf.DrawClr = pUI->getCrntDrawColor();
			//inf.FillClr = pUI->getCrntFillColor();
			//inf.BorderWdth = pUI->getCrntPenWidth();
			//inf.isFilled = false;	//default is not filled
			//inf.isSelected = false;	//defualt is not selected
			GfxInfo inf = pocir->getGfxInfo();
			inf.isSelected = false;
			Point newcen;
			Point diff = { refPoint.x - orgcen.x,refPoint.y - orgcen.y };
			//diff.x=
			newcen.x = P.x - diff.x;
			newcen.y = P.y - diff.y;
			/*newcen.x = 500;
			newcen.y =  500;*/
			Point newrad = { newcen.x + orgrad,newcen.y };
			/*newrad.x = 450;
			newrad.y = 450;*/
			Circle* newCir = new Circle(newcen, newrad, inf);
			cout << newcen.x<<"  "<< newrad.x;
			pGraph->Addshape(newCir);
			
			//pControl->AddAnotherShape(newCir);
		}
		if (porect != NULL) {
			/*if (i == 0) {
				refPoint = possrect->getCorner2();
			}*/
			refPoint.x = porect->getshapeparamters()[2];
			refPoint.y = porect->getshapeparamters()[3];
			Point A;
			A.x= porect->getshapeparamters()[0]; //corner1.x
			A.y = porect->getshapeparamters()[1];//corner1.y
			Point B;
			B.x= porect->getshapeparamters()[2]; //Corner2.x
			B.y = porect->getshapeparamters()[3]; //Corner2.y
			Point diff = { refPoint.x - B.x,refPoint.y - B.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - B.x, P.y - B.y };
			Point d = { A.x + diffdiff.x - diff.x,A.y + diffdiff.y - diff.y };
			GfxInfo inf = porect->getGfxInfo();
			inf.isSelected = false;

			Rect* R = new Rect(d, newCorner2, inf); //Create a rectangle with the parameters read from the user
			pGraph->Addshape(R);  //Add the rectangle to the list of figures
		}
		if (potrig != NULL) {
			/*if (i == 0) {
				refPoint = posstrig->getCorner3();
			}*/
			refPoint.x = potrig->getshapeparamters()[10]; //corner 3
			refPoint.y = potrig->getshapeparamters()[11];
			Point A;
			A.x = potrig->getshapeparamters()[6];  //corner1.x
			A.y = potrig->getshapeparamters()[7]; //corner1.y;
			Point B;
			B.x = potrig->getshapeparamters()[8];  //corner2.x
			B.y = potrig->getshapeparamters()[9]; //corner2.y
			Point C;
			C.x = potrig->getshapeparamters()[10];  //corner1.x
			C.y = potrig->getshapeparamters()[11]; //corner1.y;
			Point diff = { refPoint.x - C.x,refPoint.y - C.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - C.x, P.y - C.y };
			Point d = { A.x + diffdiff.x - diff.x,A.y + diffdiff.y - diff.y };
			Point e = { B.x + diffdiff.x - diff.x,B.y + diffdiff.y - diff.y };
			GfxInfo inf = potrig->getGfxInfo();
			inf.isSelected = false;
			Triangle* T = new Triangle(d, e, newCorner2, inf); //Create a rectangle with the parameters read from the user
			pGraph->Addshape(T);  //Add the rectangle to the list of figures
		}
		if (poline != NULL) {
		/*	if (i == 0) {
				refPoint = possline->getP1();
			}*/
			refPoint.x = poline->getshapeparamters()[7]; //point 
			refPoint.y = poline->getshapeparamters()[8];
			Point A;
			A.x = poline->getshapeparamters()[7];  //point1.x
			A.y = poline->getshapeparamters()[8]; //point1.y
			Point B; 
			B.x = poline->getshapeparamters()[9];  //point2.x
			B.y = poline->getshapeparamters()[10]; // point2.y;
			Point diff = { refPoint.x - A.x,refPoint.y - A.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - A.x, P.y - A.y };
			Point d = { B.x + diffdiff.x - diff.x,B.y + diffdiff.y - diff.y };
			GfxInfo inf = poline->getGfxInfo();
			inf.isSelected = false;
			Line* L = new Line(newCorner2, d, inf);
			pGraph->Addshape(L);;
		}
		if (poSquare!= NULL) {
			/*if (i == 0) {
				refPoint = possrect->getCorner2();
			}*/
			refPoint.x = poSquare->getshapeparamters()[6];
			refPoint.y = poSquare->getshapeparamters()[7];
			Point A;
			A.x = poSquare->getshapeparamters()[6]; //corner1.x
			A.y = poSquare->getshapeparamters()[7];//corner1.y
			Point B;
			B.x = poSquare->getshapeparamters()[8]; //Corner2.x
			B.y = poSquare->getshapeparamters()[9]; //Corner2.y
			Point diff = { refPoint.x - B.x,refPoint.y - B.y };
			Point newCorner2 = { P.x - diff.x,P.y - diff.y };
			Point diffdiff = { P.x - B.x, P.y - B.y };
			Point d = { A.x + diffdiff.x - diff.x,A.y + diffdiff.y - diff.y };
			GfxInfo inf = poSquare->getGfxInfo();
			inf.isSelected = false;
			
			Square* S = new Square(d, newCorner2, inf); //Create a rectangle with the parameters read from the user
			pGraph->Addshape(S);  //Add the rectangle to the list of figures
		}
		
}

void opPaste::Undo()
{
}

void opPaste::Redo()
{
}
