#include "StartRecordingAction.h"
StartRecordingAction::StartRecordingAction(ApplicationManager* pApp):Action(pApp)
{

}
void StartRecordingAction::ReadActionParameters()
{
	
}
void StartRecordingAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();	
	if ((pManager->get_Real_FigCount() == 0) && (pManager->get_IsRecording() == false) && (pManager->get_RecordedCount() == 0))
	{
		pOut->PrintMessage("Started Recording");
		pManager->set_IsRecording(true);
	}
	else
	{
		pOut->PrintMessage("Please Clear All First");
	}
}