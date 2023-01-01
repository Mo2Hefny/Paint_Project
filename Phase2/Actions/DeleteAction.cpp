#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
	index = -1;
	P.x = 0;
}

void DeleteAction::Execute()
{
	Output* p_out = pManager->GetOutput();
	ReadActionParameters();
	P = deleted->GetCenter();
	deleted->Delete(true);
	deleted->Hide(true);
	deleted->SetSelected(false);
	pManager->SetSelectedFig(NULL);
	PlaySound("Audio/Delete.wav", NULL, SND_ASYNC);
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	deleted = pManager->GetSelectedFig();
	pOut->PrintMessage("Deleted Selected Object.");
}

CFigure* DeleteAction::get_deleted()
{
	if(deleted != NULL)
		return deleted;
}

int DeleteAction::ActType()
{
	return 3;
}

void DeleteAction::play()
{
	if (P.x)
	{
		deleted = pManager->GetFigure(P.x, P.y);
		deleted->Delete(true);
		deleted->Hide(true);
		pManager->GetOutput()->PrintMessage("Deleted Object in Record.");
	}
}