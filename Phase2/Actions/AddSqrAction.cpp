#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Square: Click at center");

	do {
		//Read center and store in point P
		pIn->GetPointClicked(P.x, P.y);
	} while (40 > P.y - UI.ToolBarHeight);

	SqrGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{
	//This action needs to read some parameters first

	ReadActionParameters();

	//Create a square with the parameters read from the user
	CSquare* S = new CSquare(P, SqrGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(S);
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}

int AddSqrAction::ActType()
{
	return 1;
}
void AddSqrAction::play()
{
	CSquare* S = new CSquare(P, SqrGfxInfo);
	pManager->AddFigure(S);
}