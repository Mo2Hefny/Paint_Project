#include "DrawClrAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawClrAction::DrawClrAction(ApplicationManager* pApp, color c) :Action(pApp)
{
	OldOutline = UI.DrawColor;
	UI.DrawColor = c;
}

void DrawClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!ClrSelected())
	{
		pOut->PrintMessage("Changed Outline Color");
		NewOutline = UI.DrawColor;
	}
	else
	{
		pOut->PrintMessage("Changed Selected Figure Outline Color");
	}
}

bool DrawClrAction::ClrSelected()
{
	Fig = pManager->GetSelectedFig();
	if (Fig == NULL)
		return false;
	NewOutline = UI.DrawColor;
	Fig->ChngDrawClr(NewOutline);
	return true;
}

//Execute the action
void DrawClrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}

int DrawClrAction::ActType()
{	return 2; }

void DrawClrAction::undo()
{
	if (Fig != NULL)
	{
		pManager->GetOutput()->PrintMessage("Returned Previous Figure Outline Color");
		Fig->ChngDrawClr(OldOutline);
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Returned Previous Outline Color to Draw");
		UI.DrawColor = OldOutline;
	}
}

void DrawClrAction::redo()
{
	if (Fig != NULL)
	{
		pManager->GetOutput()->PrintMessage("Redo Figure Outline Color Change");
		Fig->ChngDrawClr(NewOutline);
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Redo Outline Color Change");
		UI.DrawColor = NewOutline;
	}
}