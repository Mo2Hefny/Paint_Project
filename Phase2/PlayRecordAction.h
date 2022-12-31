#pragma once
#include"ApplicationManager.h"

class PlayRecordAction:public Action
{
public:
	PlayRecordAction(ApplicationManager*pApp);
	void ReadActionParameters();
	void Execute();
};

