#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class RedoAction : public Action
{

private:
	int current;
	int ptrs_act[5];
	CFigure* arr[5];
public:
	RedoAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters() {};
	void add_act(int);
	void dec_act();
	void add_fig(CFigure*);
	void clear();
	virtual void undo() {};



};

