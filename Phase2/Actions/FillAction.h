#ifndef Fill_ACTION_H
#define Fill_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class FillAction : public Action
{
private:
	GfxInfo CurrentGfxInfo;
	bool filled;
public:
	FillAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	bool FillSelected();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual int ActType();
	virtual void undo();

};

#endif