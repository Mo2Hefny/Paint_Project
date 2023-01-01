#include "StopRecordingAction.h"
StopRecordingAction::StopRecordingAction(ApplicationManager* pApp) :Action(pApp)
{

}
void StopRecordingAction::ReadActionParameters()
{

}
void StopRecordingAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->get_IsRecording() == false)
	{
		pOut->PrintMessage("Please Record First");
	}
	else
	{
		pOut->PrintMessage("Recording stopped");
		pManager->set_IsRecording(false);
	}
}