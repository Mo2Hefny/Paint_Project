#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	do {
		//Read 1st corner and store in point P1
		pIn->GetPointClicked(P1.x, P1.y);
	} while (P1.y < UI.ToolBarHeight);

	pOut->PrintMessage("New Rectangle: Click at second corner");

	do {
		//Read 2nd corner and store in point P2
		pIn->GetPointClicked(P2.x, P2.y);
	} while (P1.y < UI.ToolBarHeight);

	RectGfxInfo.isFilled = UI.isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute()
{
	//This action needs to read some parameters first
	
	ReadActionParameters();
	
	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
	if (pManager->get_IsRecording() == true)
		pManager->AddToRecordingList(this);
}

int AddRectAction::ActType()
{
	return 1;
}
void AddRectAction::play()
{
	CRectangle* R = new CRectangle(P1, P2, RectGfxInfo);
	pManager->AddFigure(R);
}