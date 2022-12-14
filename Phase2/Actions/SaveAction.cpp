#include "SaveAction.h"
#include<fstream>
#include<string>
#include<iostream>

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp)
{

}
void SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name");
	 file = pIn->GetSrting(pOut)+".txt";
	 pOut->ClearDrawArea();
	 pOut->ClearStatusBar();
}
void SaveAction::Execute()
{
	ReadActionParameters();
	ofstream outfile(file);
	pManager->SaveAll(outfile);
}