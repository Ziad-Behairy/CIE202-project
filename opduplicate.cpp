#include "opduplicate.h"
#include"controller.h"
opduplicate::opduplicate(controller* pcont) : operation(pcont)
{
}

opduplicate::~opduplicate()
{
}

void opduplicate::Execute()
{
	Graph* pGr = pControl->getGraph();
	pGr->duplicateShape();
}
