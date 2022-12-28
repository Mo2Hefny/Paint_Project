#ifndef PICK_AND_HIDE_ACTION_H
#define PICK_AND_HIDE_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class PickAndHideAction : public Action
{
private:
	Point P;
	CFigure* Leader;
	char LeaderType;
public:
	PickAndHideAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	char GetFigType(CFigure*) const;
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif