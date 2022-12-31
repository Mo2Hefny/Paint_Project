#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
	index = -1;
}

void DeleteAction::Execute()
{
	deleted = pManager->GetSelectedFig();
	index = pManager->get_index(deleted);
	if (index != -1)
		pManager->deleteFig(index);
	Output* p_out = pManager->GetOutput();
	p_out->ClearDrawArea();
	pManager->UpdateInterface();
	if (pManager->get_IsRecording() == true)
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
	deleted = pManager->GetSelectedFig();
	index = pManager->get_index(deleted);
	if (index != -1)
		pManager->deleteFig(index);
	Output* p_out = pManager->GetOutput();
	p_out->ClearDrawArea();
}