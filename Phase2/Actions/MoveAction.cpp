#include "MoveAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

MoveAction::MoveAction(ApplicationManager* pApp) :Action(pApp)
{	
	x = 0; y = 0;
}

void MoveAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelectedFig() != NULL)
	{
		pOut->PrintMessage("Moving current selected object.");
		while (pIn->GetButtonState(NewPos.x, NewPos.y) == BUTTON_UP)
		{ }
		OldPos = pManager->GetSelectedFig()->GetCenter();
		while (pIn->GetButtonState(NewPos.x, NewPos.y) == BUTTON_DOWN)
		{
			if (NewPos.x != x || NewPos.y != y)
			{
				MoveFig = pManager->GetSelectedFig();
				MoveFig->move(NewPos.x, NewPos.y);
				pOut->PrintMessage("Moving.....");
				pOut->ClearDrawArea();
				pManager->UpdateInterface();
			}
			else
			{
				pManager->UpdateInterface();
				pOut->PrintMessage("Moved.");
			}
			x = NewPos.x; y = NewPos.y;
		}
		
	}
	else
	{
		pOut->PrintMessage("No selected object.");
	}
}




//Execute the action
void MoveAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}

int MoveAction::ActType()
{
	return 4;
}

void MoveAction::undo()
{

}
