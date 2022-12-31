#ifndef Fill_ACTION_H
#define Fill_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class FillAction : public Action
{
private:
	CFigure* Fig;
	color NewFill;
	color OldFill;
	bool filled;
public:
	FillAction(ApplicationManager* pApp, color);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	bool FillSelected();
	bool SetFilling(color, bool&);
	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual int ActType();
	virtual void undo();
	virtual void redo();
};

#endif