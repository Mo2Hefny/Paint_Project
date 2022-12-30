#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H

#include "Action.h"

class AddSqrAction : public Action
{
private:
	Point P;
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);

	//Reads square parameters
	virtual void ReadActionParameters();

	//Add square to the ApplicationManager
	virtual void Execute();
	virtual int ActType();
	virtual void undo() {};
};

#endif