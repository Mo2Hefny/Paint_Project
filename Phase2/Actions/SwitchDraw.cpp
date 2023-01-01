#include "SwitchDraw.h"
#include "../ApplicationManager.h"
SwitchDraw::SwitchDraw(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchDraw::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Switch to Draw Mode, creating Design tool bar");
	UI.InterfaceMode = MODE_DRAW;
	pOut->CreateDrawToolBar();
	PlaySound("Audio/SwitchMode.wav", NULL, SND_ASYNC);
}

void SwitchDraw::Execute()
{
	ReadActionParameters();
}
