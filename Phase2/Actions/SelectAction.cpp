#include "SelectAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig[0] = NULL;
	SelectedFig[1] = NULL;
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure");
	int i;
	if (SelectedFig[0] == NULL)
		i = 0;
	else
		i = 1;
	//Read 1st corner and store in point P
	while (i < 2)
	{
		GfxInfo SelectedGfxInfo;
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
			if (SelectedFig[i] != SelectedFig[abs(i - 1)])
			{
				if (SelectedFig[abs(i - 1)] != NULL && SelectedFig[abs(i - 1)]->IsSelected())
				{
					if (SelectedClr[abs(i - 1)] != MAGENTA)
						SelectedFig[abs(i - 1)]->ChngFillClr(SelectedClr[abs(i - 1)]);
					SelectedFig[abs(i - 1)]->SetSelected(false);
					SelectedFig[abs(i - 1)] = NULL;
				}
				pOut->PrintMessage("Different");
				SelectedFig[i]->SetSelected(!SelectedFig[i]->IsSelected());
				SelectedClr[i] = SelectedFig[i]->getFillClr();
				SelectedFig[i]->ChngFillClr(MAGENTA);
				//SelectedFig[i]->PrintInfo(pOut);
			}
			else if (SelectedFig[i] == SelectedFig[abs(i - 1)])
			{
				pOut->PrintMessage("Same");
				SelectedFig[i]->SetSelected(!SelectedFig[i]->IsSelected());
				if (SelectedFig[i]->IsSelected())
				{
					SelectedClr[i] = SelectedFig[i]->getFillClr();
					SelectedFig[i]->ChngFillClr(MAGENTA);
					//SelectedFig[i]->PrintInfo(pOut);
				}
				else
				{
					SelectedFig[i]->ChngFillClr(SelectedClr[abs(i-1)]);
					pOut->PrintMessage("Unselected");
				}
				SelectedFig[abs(i - 1)] = NULL;
			}
		
		}
		pManager->UpdateInterface();
		if (++i == 2)
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
