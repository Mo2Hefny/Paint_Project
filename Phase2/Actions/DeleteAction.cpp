#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
	index = -1;
	P.x = 0;
}

void DeleteAction::Execute()
{
	deleted = pManager->GetSelectedFig();
	if (deleted != NULL)
	{
		P = deleted->GetCenter();
		deleted->Delete(true);
		deleted->Hide(true);
		pManager->SetSelectedFig(NULL);
	}
	Output* p_out = pManager->GetOutput();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
	if (pManager->get_IsRecording() == true && deleted != NULL)
		pManager->AddToRecordingList(this);
}

void DeleteAction::ReadActionParameters()
{
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