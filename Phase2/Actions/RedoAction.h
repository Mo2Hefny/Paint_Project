#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
class RedoAction : public Action
{

private:
	int current;
	int indices[5];
	int ptrs_act[5];
	CFigure* arr[5];
	Action** ptr;
public:
	RedoAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
	void add_act(int);
	void dec_act();
	void add_fig(CFigure*);
	void clear();
	void add_action(Action* ptr_act);
	void add_index(int index);
};

