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
	pOut->PrintMessage("Playing the record");
	pManager->PlayAll();
	pOut->PrintMessage("The record ended");
}
