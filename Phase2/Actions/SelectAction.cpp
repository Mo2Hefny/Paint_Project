#include "SelectAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedFig[0] = NULL;
	SelectedFig[1] = pApp->GetSelectedFig();
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select a figure");

	SelectedFig[1] = pManager->GetSelectedFig();
	//Read 1st corner and store in point P
	for (int i = 0; i < 2;)
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
		pManager->SetSelectedFig(SelectedFig[i]);
		if (SelectedFig[i])
		{
			if (SelectedFig[i] != SelectedFig[abs(i - 1)])
			{
				if (SelectedFig[abs(i - 1)] != NULL && SelectedFig[abs(i - 1)]->IsSelected())
				{
					SelectedFig[abs(i - 1)]->ChngSelectedDraw();
					SelectedFig[abs(i - 1)]->SetSelected(false);
					SelectedFig[abs(i - 1)] = NULL;
				}
				SelectedFig[i]->SetSelected(!SelectedFig[i]->IsSelected());
				
				SelectedFig[i]->PrintInfo(pOut);
				SelectedFig[i]->ChngDrawClr(UI.HighlightColor);
			}
			else if (SelectedFig[i] == SelectedFig[abs(i - 1)])
			{
				SelectedFig[i]->SetSelected(!SelectedFig[i]->IsSelected());
				if (SelectedFig[i]->IsSelected())
				{
					
					SelectedFig[i]->PrintInfo(pOut);
					SelectedFig[i]->ChngDrawClr(UI.HighlightColor);
				}
				else
				{
					SelectedFig[i]->ChngSelectedDraw();
					pManager->SetSelectedFig(NULL);
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
	ReadActionParameters();
}
