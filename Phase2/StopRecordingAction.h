#pragma once
#include"ApplicationManager.h"
class StopRecordingAction:public Action
{
public:
	StopRecordingAction(ApplicationManager*pApp);

	virtual	void ReadActionParameters();

	virtual void Execute();
};
