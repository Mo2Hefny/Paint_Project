#include "SwitchPlay.h"
#include "../ApplicationManager.h"
SwitchPlay::SwitchPlay(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchPlay::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to Play Mode, creating simualtion tool bar");
	if (pManager->GetSelectedFig() != NULL)
	{
		pManager->GetSelectedFig()->SetSelected(false);
		pManager->SetSelectedFig(NULL);
	}
	pOut->CreatePlayToolBar();
	PlaySound("Audio/SwitchMode.wav", NULL, SND_ASYNC);
}

void SwitchPlay::Execute()
{
	ReadActionParameters();
}
