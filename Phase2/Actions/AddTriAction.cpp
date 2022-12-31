#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at vertix 1");

	//Read vertix 1 and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at vertix 2");

	//Read vertix 2 and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at vertix 3");

	//Read vertix 3 and store in point P3
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
	TriGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriAction::Execute()
{
	//This action needs to read some parameters first
	
	ReadActionParameters();

	//Create a triangle with the parameters read from the user
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);

	//Add the triangle to the list of figures
	pManager->AddFigure(T);
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}

int AddTriAction::ActType()
{
	return 1;
}
