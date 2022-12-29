#ifndef PICK_AND_HIDE_ACTION_H
#define PICK_AND_HIDE_ACTION_H

#include "..\ApplicationManager.h"
#include "Action.h"

class PickAndHideAction : public Action
{
private:
	int mode;
	Point P;
	char LeaderType;
	color LeaderColor;
	bool filled;
	unsigned int CountRight, CountWrong;
public:
	PickAndHideAction(ApplicationManager* pApp, int m);

	//Reads rectangle parameters
	virtual void ReadActionParameters();
	char GetFigType(CFigure*) const;
	bool SameTypeLeft() const;
	void PrintResults() const;
	void Unhide() const;
	bool Score(CFigure*) const;
	void PickProperty();
	void PrintProperty() const;
	//Add rectangle to the ApplicationManager
	virtual void Execute();

};

#endif