#pragma once
#include "Action.h"
class SwitchDraw : public Action
{
public:
	SwitchDraw(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

