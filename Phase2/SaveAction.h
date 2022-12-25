#pragma once
#include "Actions/Action.h"
#include<fstream>
#include<iostream>
#include "ApplicationManager.h"
class SaveAction : public Action
{
private:
	string file;
public:
	SaveAction(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();
};

