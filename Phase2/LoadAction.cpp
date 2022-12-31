#include "LoadAction.h"
#include<string>
#include"ApplicationManager.h"
#include"GUI/UI_Info.h"
#include"GUI/Output.h"
#include"GUI/Input.h"
#include"Figures/CRectangle.h"
#include"Figures/CHexagon.h"
#include"Figures/CSquare.h"
#include"Figures/CTriangle.h"
#include"Figures/CCircle.h"
#include<fstream>
LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp)
{

}
void LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please enter the file name");
	file = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearDrawArea();
	pOut->ClearStatusBar();
}
void LoadAction::Execute()
{
	string drawclr, fillclr, type;
	int n;
	ReadActionParameters();
	ifstream infile(file);
	infile >> drawclr >> fillclr;
	if (drawclr == "RED")
		UI.DrawColor = RED;
	if (drawclr == "YELLOW")
		UI.DrawColor = YELLOW;
	if (drawclr == "BLACK")
		UI.DrawColor = BLACK;
	if (drawclr == "GREEN")
		UI.DrawColor = GREEN;
	if (drawclr == "ORANGE")
		UI.DrawColor = ORANGE;
	if (drawclr == "BLUE")
		UI.DrawColor = BLUE;
	if (fillclr == "NOTFILLED")
		UI.isFilled = false;
	else
	{
		if (fillclr == "RED")
			UI.FillColor = RED;
		if (fillclr == "YELLOW")
			UI.FillColor = YELLOW;
		if (fillclr == "BLACK")
			UI.FillColor = BLACK;
		if (fillclr == "GREEN")
			UI.FillColor = GREEN;
		if (fillclr == "ORANGE")
			UI.FillColor = ORANGE;
		if (fillclr == "BLUE")
			UI.FillColor = BLUE;
	}
	infile >> n;
	CFigure* myfig = NULL;
	for (int i = 0; i <= n; i++)
	{
		infile >> type;
		if (type == "RECT")
			myfig = new CRectangle;
		else if (type == "HEXA")
			myfig = new CHexagon;
		else if (type == "TRI")
			myfig = new CTriangle;
		else	if (type == "SQUARE")
			myfig = new CSquare;
		else if (type == "CIRC")
			myfig = new CCircle;
		myfig->load(infile);
		myfig->Delete(false); //testing
		myfig->Hide(false);
		pManager->AddFigure(myfig);
		pManager->UpdateInterface();

	}
}