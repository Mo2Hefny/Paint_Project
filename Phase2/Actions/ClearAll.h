#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class ClearAll : public Action
{
public:

	ClearAll(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
};

