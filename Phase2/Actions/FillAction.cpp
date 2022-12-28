#include "FillAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillAction::FillAction(ApplicationManager* pApp) :Action(pApp)
{}

void FillAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (!FillSelected())
	{
		pOut->PrintMessage("Changed Fill Color");
		CurrentGfxInfo.FillClr = UI.FillColor;
	}
	else
	{
		pOut->PrintMessage("Changed Selected Figure Fill Color");
	}
}

bool FillAction::FillSelected()
{
	CFigure* Fig = pManager->GetSelectedFig();
	if (Fig == NULL)
		return false;
	if (UI.FillColor == Fig->getFillClr() && Fig->IsFilled())
	{
		filled = false;
		Fig->SetIsFilled(false);
		pManager->GetOutput()->ClearDrawArea();
	}
	else
	{
		filled = true;
		Fig->ChngFillClr(UI.FillColor);
	}
	return true;
}

//Execute the action
void FillAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}
