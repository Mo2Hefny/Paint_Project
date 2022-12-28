#include "PickAndHideAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\Figures.h"

PickAndHideAction::PickAndHideAction(ApplicationManager* pApp) :Action(pApp)
{
	pManager->GetOutput()->PrintMessage("Select Type");
	do {
		pManager->GetInput()->GetPointClicked(P.x, P.y);
		Leader = pManager->GetFigure(P.x, P.y);
	} while (Leader == NULL);
	LeaderType = GetFigType(Leader);
}

void PickAndHideAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	
}

char PickAndHideAction::GetFigType(CFigure* Fig) const
{
	CRectangle* R = dynamic_cast <CRectangle*> (Fig);
	if (R)
	{
		pManager->GetOutput()->PrintMessage("Selected Rectangle");
		return 'R';
	}
	CSquare* S = dynamic_cast <CSquare*> (Fig);
	if (S)
	{
		pManager->GetOutput()->PrintMessage("Selected Square");
		return 'S';
	}
	CTriangle* T = dynamic_cast <CTriangle*> (Fig);
	if (T)
	{
		pManager->GetOutput()->PrintMessage("Selected Triangle");
		return 'T';
	}
	CCircle* C = dynamic_cast <CCircle*> (Fig);
	if (C)
	{
		pManager->GetOutput()->PrintMessage("Selected Circle");
		return 'C';
	}
	CHexagon* H = dynamic_cast <CHexagon*> (Fig);
	if (H)
	{
		pManager->GetOutput()->PrintMessage("Selected Hexagon");
		return 'H';
	}

}

//Execute the action
void PickAndHideAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}
