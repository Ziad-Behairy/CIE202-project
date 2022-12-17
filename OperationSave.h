#pragma once
#include"operations/operation.h"
#include"Shapes/Shape.h"
class OperationSave :public operation
{
private:
	string FileName;

	int NumOfDrawnShapes;
	shape* DrawnShapelist[MaxDrawnShapes];
public:
	OperationSave(controller* pcont, int num);
	//virtual void GetAllShapeData();
	string GetFileName();
	void Execute();
	virtual	~OperationSave();

};

