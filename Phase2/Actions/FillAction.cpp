#include "FillAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

FillAction::FillAction(ApplicationManager* pApp, color c) :Action(pApp)
{
	NewFill = c;
	P.x = 0;
}

void FillAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Fig = pManager->GetSelectedFig();
	if (Fig == NULL)
	{
		ChangeUI();
		return;
	}
	P = Fig->GetCenter();
	FillSelected();
}

void FillAction::FillSelected()
{
	OldFill = Fig->getFillClr();
	OldFilled = Fig->IsFilled();
	if (NewFill == OldFill && OldFilled)
	{
		pManager->GetOutput()->PrintMessage("UnFill Selected Figure Color");
		Filled = false;
		Fig->ChngFillClr(NewFill);
		Fig->SetIsFilled(false);
		pManager->GetOutput()->ClearDrawArea();
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Changed Selected Figure Fill Color");
		Filled = true;
		Fig->ChngFillClr(NewFill);
	}
	pManager->GetOutput()->ClearDrawArea();
}

void FillAction::ChangeUI()
{
	OldFilled = UI.isFilled;
	OldFill = UI.FillColor;
	if (NewFill == OldFill && OldFilled)
	{
		pManager->GetOutput()->PrintMessage("UnFill Color");
		UI.isFilled = false;
		Filled = false;
		UI.FillColor = NewFill;
	}
	else
	{
		pManager->GetOutput()->PrintMessage("Changed Fill Color");
		UI.isFilled = true;
		Filled = true;
		UI.FillColor = NewFill;
	}
}

//Execute the action
void FillAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	PlaySound("Audio/SprayPaint.wav", NULL, SND_ASYNC);
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures
}

int FillAction::ActType()
{	return 2; }

void FillAction::undo()
{
	color tempclr = OldFill;
	OldFill = NewFill;
	NewFill = tempclr;
	bool tempfill = OldFilled;
	OldFilled = Filled;
	Filled = tempfill;
	if (Fig)
		FillSelected();
	else
		ChangeUI();
}

void FillAction::redo()
{
	color tempclr = OldFill;
	OldFill = NewFill;
	NewFill = tempclr;
	bool tempfill = OldFilled;
	OldFilled = Filled;
	Filled = tempfill;
	if (Fig)
		FillSelected();
	else
		ChangeUI();
}

void FillAction::play()
{
	if (P.x)
	{
		Fig = pManager->GetFigure(P.x, P.y);
		FillSelected();
		pManager->GetOutput()->PrintMessage("Changed Figure Fill Color in Record");
	}
	else
	{
		ChangeUI();
		pManager->GetOutput()->PrintMessage("Changed Fill Color in Record");
	}
}