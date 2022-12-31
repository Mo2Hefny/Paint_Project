#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class DeleteAction : public Action
{
private:
	int index;
	CFigure* deleted;
public:
	DeleteAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
	CFigure* get_deleted();
	int ActType();
	virtual void undo() {};
	
};

