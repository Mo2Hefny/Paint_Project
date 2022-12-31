#pragma once
#include "Action.h"
class SwitchPlay : public Action
{
public:
	SwitchPlay(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};

