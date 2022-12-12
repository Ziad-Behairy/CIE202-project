#pragma once
#include"operations/operation.h"
#include"Shapes/Shape.h"
class OperationSave :public operation
{
private:
	string FileName;
	enum { MaxDrawnShapes = 150 };
	int NumOfDrawnShapes;
	shape* DrawnShapelist[MaxDrawnShapes];
public:
	OperationSave(controller* pcont, int num);
	//virtual void GetAllShapeData();
	string GetFileName();
	shape* GetDrawnshapelist();
	int GetNumOfDrawnShapes();
	void SetDrawnShapelist(shape* newDrawnShapelist[MaxDrawnShapes]);
	void SetNumOfDrawnShapes(int newNumOfDrawnShapes);
	void SetFileName(string newFileName);
	void Execute();
	virtual	~OperationSave();

};

