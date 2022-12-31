#include "FillAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillAction::FillAction(ApplicationManager* pApp, color c) :Action(pApp)
{
	filled = UI.isFilled;
	NewFill = c;
	OldFill = UI.FillColor;
	Fig = pManager->GetSelectedFig();
	if (Fig != NULL)
		filled = Fig->IsFilled();
}

void FillAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool empty = !SetFilling(NewFill, UI.isFilled);
	if (empty)
	{
		pOut->PrintMessage("UnFill Color");
	}
	if (!FillSelected())
	{
		if (!empty)
		{
		pOut->PrintMessage("Changed Fill Color");
		}
	}
	else
	{
		//pOut->PrintMessage("Changed Selected Figure Fill Color");
	}
}

bool FillAction::FillSelected()
{
	if (Fig == NULL)
		return false;
	if (NewFill == Fig->getFillClr() && filled)
	{
		pManager->GetOutput()->PrintMessage("UnFill Selected Color");
		filled = false;
		Fig->ChngFillClr(NewFill);
		Fig->SetIsFilled(filled);
		pManager->GetOutput()->ClearDrawArea();
	}
	else
	{
		Fig->ChngFillClr(NewFill);
	}
	return true;
}

bool FillAction::SetFilling(color c, bool &b)
{
	if (c == UI.FillColor && b)
	{
		b = false;
		return false;
	}
	else
		b = true;
	UI.FillColor = c;
	return true;
}
//Execute the action
void FillAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures
}

int FillAction::ActType()
{	return 2; }

void FillAction::undo()
{
	color temp;
	temp = OldFill;
	OldFill = NewFill;
	NewFill = temp;
	SetFilling(NewFill, filled);
	if (!FillSelected())
	{
		pManager->GetOutput()->PrintMessage("Undo Fill Color Change");
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Undo Selected Figure Fill Color Change");
	}
}

void FillAction::redo()
{
	color temp;
	temp = OldFill;
	OldFill = NewFill;
	NewFill = temp;
	SetFilling(NewFill, filled);
	if (!FillSelected())
	{
		pManager->GetOutput()->PrintMessage("Redo Fill Color Change");
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Redo Selected Figure Fill Color Change");
	}
}