#include "DrawClrAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawClrAction::DrawClrAction(ApplicationManager* pApp) :Action(pApp)
{}

void DrawClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!ClrSelected())
	{
		pOut->PrintMessage("Changed Outline Color");
		outline = UI.DrawColor;
	}
	else
	{
		pOut->PrintMessage("Changed Selected Figure Outline Color");
	}
}

bool DrawClrAction::ClrSelected()
{
	CFigure* Fig = pManager->GetSelectedFig();
	if (Fig == NULL)
		return false;
	outline = UI.DrawColor;
	Fig->ChngDrawClr(outline);
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
{}