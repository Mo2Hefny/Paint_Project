#include "ClearAll.h"

ClearAll::ClearAll(ApplicationManager* pApp) : Action(pApp)
{
}

void ClearAll::Execute()
{
	Output* p_out = pManager->GetOutput();
	pManager->clear_figs();
	pManager->clear_undo();
	pManager->clear_gui();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}
void ClearAll::play()
{

	Output* p_out = pManager->GetOutput();
	pManager->clear_figs();
	pManager->clear_undo();
	pManager->clear_gui();
	p_out->ClearDrawArea();
	
}