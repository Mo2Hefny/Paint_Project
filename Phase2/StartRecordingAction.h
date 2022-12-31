#pragma once
#include"ApplicationManager.h"
#include"Actions/Actions.h"
class StartRecordingAction:public Action
{
public:
	StartRecordingAction(ApplicationManager*pApp);
	void ReadActionParameters();
	virtual void Execute();
};

