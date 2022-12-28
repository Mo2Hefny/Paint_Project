#include "PickAndHideAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\Figures.h"

#include <cstdlib>
#include <iostream>
#include <time.h>

PickAndHideAction::PickAndHideAction(ApplicationManager* pApp, int m) :Action(pApp)
{
	mode = m;
	CountRight = 0; CountWrong = 0;
	LeaderColor = NULL;
}

void PickAndHideAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	PickProperty();
	CFigure* Fig;
	while (SameTypeLeft())
	{
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pIn->GetPointClicked(P.x, P.y);
		if (P.y < UI.ToolBarHeight)
		{
			pOut->PrintMessage("Clicked outside");
			break;
		}
		Fig = pManager->GetFigure(P.x, P.y);
		if (!Fig)
		{
			pOut->PrintMessage("Clicked on Draw Area");
			continue;
		}
		if (Fig->IsHidden())
		{
			pOut->PrintMessage("Already selected");
			continue;
		}
		else
		{
			Fig->Hide(true);
				if (GetFigType(Fig) == LeaderType)
					CountRight++;
				else
					CountWrong++;
			pOut->PrintMessage("New Fig selected");
		}
	}
	PrintResults();
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}

void PickAndHideAction::PickProperty()
{
	srand(time(0));
	ostringstream oss;
	oss << "Select ";
	if (mode == 2 || mode == 3)
	{
		switch (rand() % 6)
		{
		case 0:
			LeaderColor = BLACK;
			oss << "Black ";
			break;
		case 1:
			LeaderColor = RED;
			oss << "Red ";
			break;
		case 2:
			LeaderColor = GREEN;
			oss << "Green ";
			break;
		case 3:
			LeaderColor = YELLOW;
			oss << "Yellow ";
			break;
		case 4:
			LeaderColor = BLUE;
			oss << "Blue ";
			break;
		case 5:
			LeaderColor = ORANGE;
			oss << "Orange ";
			break;
		}
	}
	if (mode == 1 || mode == 3)
	{
		switch (rand() % 5)
		{
		case 0:
			LeaderType = 'R';
			oss << "Rectangles.";
			break;
		case 1:
			LeaderType = 'S';
			oss << "Squares.";
			break;
		case 2:
			LeaderType = 'T';
			oss << "Triangles.";
			break;
		case 3:
			LeaderType = 'C';
			oss << "Circles.";
			break;
		case 4:
			LeaderType = 'H';
			oss << "Hexagons.";
			break;
		}
	}
	pManager->GetOutput()->PrintMessage(oss.str());
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

bool PickAndHideAction::SameTypeLeft() const
{
	CFigure* Fig;
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		Fig = pManager->GetFigInList(i);
		if (GetFigType(Fig) == LeaderType && !Fig->IsHidden())
			return true;
	}
	return false;
}

void PickAndHideAction::PrintResults() const
{
	ostringstream oss;
	oss << "Correct: " << CountRight << "\t Incorrect: " << CountWrong;
	pManager->GetOutput()->PrintMessage(oss.str());
}

void PickAndHideAction::Unhide() const
{
	CFigure* Fig;
	for (int i = 0; i < pManager->GetFigCount(); i++)
	{
		Fig = pManager->GetFigInList(i);
		if (Fig->IsHidden())
			Fig->Hide(false);
	}

}

//Execute the action
void PickAndHideAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Unhide();
	//Add the rectangle to the list of figures
}
