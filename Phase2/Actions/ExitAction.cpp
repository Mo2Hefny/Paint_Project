#include "ExitAction.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ExitAction::ExitAction(ApplicationManager* pApp) : Action(pApp)
{}

void ExitAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}

//Execute the action
void ExitAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	PlaySound("Audio/Close.wav", NULL, SND_SYNC);
	//Create a rectangle with the parameters read from the user

	//Add the rectangle to the list of figures
	

}
