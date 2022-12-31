#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
/*typedef struct
{
	Action* ptr;
}actions; */
class UndoAction : public Action
{

private:
	int current;
	int ptrs_act[5];
	CFigure* arr[5];
	//test:
		//arr of action ptrs breaks the app -_-
	Action** ptr;

public:
	UndoAction(ApplicationManager* pApp);
	void Execute();
	void ReadActionParameters() {};
	void add_act(int);
	void dec_act();
	void add_fig(CFigure*);
	void clear();
	int act_type(); //returns 7(meaning undo)
	//test:
	void add_action(Action* ptr);
	virtual void play();

};

