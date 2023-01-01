#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class UndoAction : public Action
{

private:
	int current;
	int ptrs_act[5];
	CFigure* arr[5];
	Action** ptr;

public:
	UndoAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters();
	void add_act(int);
	void dec_act();
	void add_fig(CFigure*);
	void clear();
	int act_type(); //returns 7(meaning undo)
	void add_action(Action* ptr);
	virtual void play();
	~UndoAction();

};

