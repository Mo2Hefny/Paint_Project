#ifndef MOVE_ACTION_H
#define MOVE_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class MoveAction : public Action
{
private:
	Point NewPos;
	Point OldPos;
	CFigure* MoveFig;
	int x, y;
public:
	MoveAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	int ActType();
	virtual void undo();
	virtual void redo();
};

#endif