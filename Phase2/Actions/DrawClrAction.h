#ifndef DRAW_CLR_ACTION_H
#define DRAW_CLR_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class DrawClrAction : public Action
{
private:
	color outline;
public:
	DrawClrAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	bool ClrSelected();

	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif