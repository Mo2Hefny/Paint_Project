#include "PlayRecordAction.h"
PlayRecordAction::PlayRecordAction(ApplicationManager* pApp) :Action(pApp)
{

}
void PlayRecordAction::ReadActionParameters()
{

}
void PlayRecordAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->get_RecordedCount() != 0)
	{
		pOut->PrintMessage("Playing the record");
		pManager->PlayAll();
		pOut->PrintMessage("The record ended");
	}
	else
	{
		pOut->PrintMessage("Please record first");
	}
}
