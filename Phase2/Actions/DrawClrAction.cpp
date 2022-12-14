#include "DrawClrAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

DrawClrAction::DrawClrAction(ApplicationManager* pApp, color c) :Action(pApp)
{
	OldOutline = UI.DrawColor;
	UI.DrawColor = c;
	P.x = 0;
}

void DrawClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Fig = pManager->GetSelectedFig();
	if (Fig != NULL)
		P = Fig->GetCenter();
	if (!ClrSelected())
	{
		if (OldOutline == UI.DrawColor)
			pOut->PrintMessage("Same Outline Color");
		else
			pOut->PrintMessage("Changed Outline Color");
		NewOutline = UI.DrawColor;
	}
	else
	{
		if (OldOutline == NewOutline)
			pOut->PrintMessage("Same Selected Figure Outline Color");
		else
			pOut->PrintMessage("Changed Selected Figure Outline Color");
	}
}

bool DrawClrAction::ClrSelected()
{
	if (Fig == NULL)
		return false;
	NewOutline = UI.DrawColor;
	OldOutline = Fig->getDrawClr();
	Fig->ChngDrawClr(NewOutline);
	return true;
}

//Execute the action
void DrawClrAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	PlaySound("Audio/DrawOutline.wav", NULL, SND_ASYNC);
	if (pManager->get_IsRecording() == true && OldOutline != UI.DrawColor)
		pManager->AddToRecordingList(this);
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

void DrawClrAction::play()
{
	UI.DrawColor = NewOutline;
	pManager->GetOutput()->PrintMessage("Changed Outline Color in Record.");
	if (P.x)
	{
		Fig = pManager->GetFigure(P.x, P.y);
		Fig->ChngDrawClr(UI.DrawColor);
		pManager->GetOutput()->PrintMessage("Changed Selected Figure Outline Color in Record.");
	}
}
