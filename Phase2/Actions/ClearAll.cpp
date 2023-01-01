#include "ClearAll.h"

ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp)
{}

void ClearAll::Execute()
{
	ReadActionParameters();
	Output* p_out = pManager->GetOutput();
	pManager->clear_figs();
	pManager->clear_undo();
	pManager->clear_gui();
	pManager->clear_recording();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
	PlaySound("Audio/ClearAll.wav", NULL, SND_ASYNC);
	if (pManager->get_IsRecording() == true)
	{
		p_out->PrintMessage("Recording stopped");
		pManager->set_IsRecording(false);
	}
}

void ClearAll::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Cleared Drawing Area.");
}