#include "PickAndHideAction.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\Figures.h"

#include <cstdlib>
#include <iostream>
#include <time.h>
#include<fstream>
#include<string>

PickAndHideAction::PickAndHideAction(ApplicationManager* pApp, int m) :Action(pApp)
{
	mode = m;
	CountRight = 0; CountWrong = 0;
	LeaderColor = NULL;
	filled = true;
}

void PickAndHideAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	srand(time(0));
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("No Figures To Play.");
		return;
	}
	PickProperty();
	CFigure* Fig;
	while (SameTypeLeft())
	{
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pIn->GetPointClicked(P.x, P.y);
		if (P.y < UI.ToolBarHeight)
		{
			pOut->ClearStatusBar();
			break;
		}
		Fig = pManager->GetFigure(P.x, P.y);
		if (!Fig)
		{
			continue;
		}
		if (Fig->IsHidden())
		{
			continue;
		}
		else
		{
			if (Score(Fig))
			{
				pOut->PrintMessage("RIGHT!");
				PlaySound("Audio/Right.wav", NULL, SND_ASYNC);
				CountRight++;
			}
			else
			{
				pOut->PrintMessage("WRONG....");
				PlaySound("Audio/No.wav", NULL, SND_ASYNC);
				CountWrong++;
			}
			Fig->Hide(true);
		}
	}
	if (CountRight && P.y > UI.ToolBarHeight)
	{
		PlaySound("Audio/GameOver.wav", NULL, SND_ASYNC);
		PrintResults();
	}
	pOut->ClearDrawArea();
	pManager->UpdateInterface();
}

void PickAndHideAction::PickProperty()
{
	if (mode == 1 || mode == 3)
	{
		switch (abs(rand()) % 5)
		{
		case 0:
			LeaderType = 'R';
			break;
		case 1:
			LeaderType = 'S';
			break;
		case 2:
			LeaderType = 'T';
			break;
		case 3:
			LeaderType = 'C';
			break;
		case 4:
			LeaderType = 'H';
			break;
		}
	}
	if (mode == 2 || mode == 3)
	{
		switch (abs(rand()) % 7)
		{
		case 0:
			LeaderColor = BLACK;
			filled = true;
			break;
		case 1:
			LeaderColor = RED;
			filled = true;
			break;
		case 2:
			LeaderColor = GREEN;
			filled = true;
			break;
		case 3:
			LeaderColor = YELLOW;
			filled = true;
			break;
		case 4:
			LeaderColor = BLUE;
			filled = true;
			break;
		case 5:
			LeaderColor = ORANGE;
			filled = true;
			break;
		case 6:
			filled = false;
			break;
		}
	}
	if (!SameTypeLeft())
		PickProperty();
	else
		PrintProperty();
}


char PickAndHideAction::GetFigType(CFigure* Fig) const
{
	CRectangle* R = dynamic_cast <CRectangle*> (Fig);
	if (R)
	{
		return 'R';
	}
	CSquare* S = dynamic_cast <CSquare*> (Fig);
	if (S)
	{
		return 'S';
	}
	CTriangle* T = dynamic_cast <CTriangle*> (Fig);
	if (T)
	{
		return 'T';
	}
	CCircle* C = dynamic_cast <CCircle*> (Fig);
	if (C)
	{
		return 'C';
	}
	CHexagon* H = dynamic_cast <CHexagon*> (Fig);
	if (H)
	{
		return 'H';
	}

}

bool PickAndHideAction::SameTypeLeft() const
{
	CFigure* Fig;
	for (int i = 0; i < pManager->Get_Real_FigCount(); i++)
	{
		Fig = pManager->GetFigInList(i);
		if (!Fig->IsHidden() && Score(Fig) && !Fig->IsDeleted())
			return true;
	}
	return false;
}

bool PickAndHideAction::Score(CFigure* Fig) const
{
	if (mode == 1 && GetFigType(Fig) == LeaderType)
		return true;
	else if (mode == 2 && Fig->IsFilled() == filled)
	{
		if (Fig->getFillClr() == LeaderColor || filled == false)
			return true;
	}
	else if (mode == 3 && Fig->IsFilled() == filled && GetFigType(Fig) == LeaderType)
	{
		if (Fig->getFillClr() == LeaderColor || filled == false)
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

void PickAndHideAction::PrintProperty() const
{
	string clr = " ", figure = " ";
	ostringstream oss;
	if (mode == 1 || mode == 3)
	{
		switch (LeaderType)
		{
		case 'R':
			figure = "Rectangles.";
			break;
		case 'S':
			figure = "Squares.";
			break;
		case 'T':
			figure = "Triangles.";
			break;
		case 'C':
			figure = "Circles.";
			break;
		case 'H':
			figure = "Hexagons.";
			break;
		}
	}
	if (mode == 2 || mode == 3)
	{
		if (filled == false)
			clr = "Unfilled ";
		else if (LeaderColor == BLACK)
			clr = "Black ";
		else if (LeaderColor == YELLOW)
			clr = "Yellow ";
		else if (LeaderColor == RED)
			clr = "Red ";
		else if (LeaderColor == ORANGE)
			clr = "Orange ";
		else if (LeaderColor == BLUE)
			clr = "Blue ";
		else if (LeaderColor == GREEN)
			clr = "Green ";
		else
			clr = "empty";
	}
	oss << "Select " << clr << figure;
	pManager->GetOutput()->PrintMessage(oss.str());
}

void PickAndHideAction::Unhide() const
{
	CFigure* Fig;
	for (int i = 0; i < pManager->Get_Real_FigCount(); i++)
	{
		Fig = pManager->GetFigInList(i);
		if (Fig->IsHidden() && !Fig->IsDeleted())
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
