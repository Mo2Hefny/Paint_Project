#ifndef DRAW_CLR_ACTION_H
#define DRAW_CLR_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class DrawClrAction : public Action
{
private:
	CFigure* Fig;
	color NewOutline;
	color OldOutline;
	Point P;
public:
	DrawClrAction(ApplicationManager* pApp, color c);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	bool ClrSelected();
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	int ActType();
	virtual void undo();
	virtual void redo();
	virtual void play();
};

#endif