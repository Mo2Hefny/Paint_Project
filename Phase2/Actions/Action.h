#ifndef ACTION_H
#define ACTION_H

#include "..\DefS.h"
#include"../Figures/CFigure.h"
#include <Windows.h>

class ApplicationManager; //forward class declaration


//Base class for all possible actions
class Action
{
protected:
	ApplicationManager *pManager;	//Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp) { pManager = pApp; }	//constructor

	//Reads parameters required for action to execute (code depends on action type)
	virtual void ReadActionParameters() =0;
	
	//Execute action (code depends on action type)
	virtual void Execute() =0;
	
	virtual int ActType(); //returns 1 if a figure is created & 2 if a color changed;
	virtual CFigure* get_deleted();
	virtual void undo();
	virtual void redo();
	virtual void play();
};

#endif