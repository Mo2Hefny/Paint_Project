#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class SelectAction : public Action
{
private:
	Point P; 
	CFigure* SelectedFig[2];
public:
	SelectAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif