#pragma once
#include "Actions/Action.h"
#include<fstream>
#include<iostream>
#include "ApplicationManager.h"
#include<string>
class LoadAction : public Action
{
private:
	string file;
public:
	LoadAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
	virtual void undo() {};
};

