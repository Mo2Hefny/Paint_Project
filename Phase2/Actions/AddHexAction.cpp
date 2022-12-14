#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at center");

	do {
		//Read center and store in point P
		pIn->GetPointClicked(P.x, P.y);
	} while (40 > P.y - UI.ToolBarHeight);

	HexGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	
	ReadActionParameters();

	//Create a hexagon with the parameters read from the user
	CHexagon* H = new CHexagon(P, HexGfxInfo);

	//Add the hexagon to the list of figures
	pManager->AddFigure(H);
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}

int AddHexAction::ActType()
{
	return 1;
}
void AddHexAction::play()
{
	CHexagon* H = new CHexagon(P, HexGfxInfo);
	pManager->AddFigure(H);
}