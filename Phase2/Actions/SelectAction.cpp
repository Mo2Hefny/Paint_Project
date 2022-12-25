#include "SelectAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure");

	//Read 1st corner and store in point P
	CFigure* SelectedFig[2];
	for(int i = 0; i < 2;)
	{
		pIn->GetPointClicked(P.x, P.y);
		if (P.y < UI.ToolBarHeight)
		{
			pOut->PrintMessage("Clicked outside");
			break;
		}
		SelectedFig[i] = pManager->GetFigure(P.x, P.y);
		if (SelectedFig[i] == NULL)
			continue;
		if (SelectedFig[i])
		{
			SelectedFig[i]->SetSelected(!SelectedFig[i]->IsSelected());
			SelectedGfxInfo = SelectedFig[i]->getGfxInfo();
			if (SelectedFig[i]->IsSelected())
			{
				SelectedFig[i]->ChngFillClr(MAGENTA);
				SelectedFig[i]->PrintInfo(pOut);
			}
			else
			{
				SelectedFig[i]->ChngFill(SelectedGfxInfo);
				pOut->PrintMessage("Unselected");
			}
		}
		if (i == 2)
			i = 0;
	}
	pOut->ClearStatusBar();

}

//Execute the action
void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures

}
