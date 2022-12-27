#include "ApplicationManager.h"
#include "Actions/Actions.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include"SaveAction.h"


//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_SHAPE:
			pOut->PrintMessage("Action: Select a shape to draw");
			UI.InterfaceMode = MODE_SHAPE;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_CRCL:
			pAct = new AddCircAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
		case DRAW_SELECT:
			pAct = new SelectAction(this);
			pOut->PrintMessage("Action: Select object , Click anywhere");
			break;
		case DRAW_FillCol:
			pOut->PrintMessage("Action: Fill object , Select color");
			UI.InterfaceMode = MODE_COL_FILL;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_DrawCol:
			pOut->PrintMessage("Action: Draw color , Select color");
			UI.InterfaceMode = MODE_COL_DRW;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_BLACK:
			pOut->PrintMessage("Action: Selected color Black , Click anywhere");
			
			break;
		case DRAW_YELLOW:
			pOut->PrintMessage("Action: Selected color Yellow , Click anywhere");
			
			break;
		case DRAW_ORANGE:
			pOut->PrintMessage("Action: Selected color Orange , Click anywhere");
			
			break;
		case DRAW_RED:
			pOut->PrintMessage("Action: Selected color Red , Click anywhere");
		
			break;
		case DRAW_BLUE:
			pOut->PrintMessage("Action: Selected color Blue , Click anywhere");
			
			break;
		case DRAW_GREEN:
			pOut->PrintMessage("Action: Selected color Green , Click anywhere");
			
			break;
		case DRAW_MOVE:
			pOut->PrintMessage("Action: Move object , Click anywhere");
			break;
		case DRAW_DEL:
			pOut->PrintMessage("Action: Delete object , Click anywhere");
			break;
		case DRAW_UNDO:
			pOut->PrintMessage("Action: Undo action , Click anywhere");
			break;
		case DRAW_REDO:
			pOut->PrintMessage("Action: Redo action , Click anywhere");
			break;
		case DRAW_CLEAR:
			pOut->PrintMessage("Action: Clear drawing area , Click anywhere");
			break;
		case DRAW_StartRec:
			pOut->PrintMessage("Action: Start recording , Click anywhere");
			break;
		case DRAW_StopRec:
			pOut->PrintMessage("Action: Stop recording , Click anywhere");
			break;
		case DRAW_PlayRec:
			pOut->PrintMessage("Action: Play last record , Click anywhere");
			break;
		case DRAW_SAVE:
			pAct = new SaveAction(this);
			break;
		case DRAW_LOAD:
			pOut->PrintMessage("Action: Load file , Click anywhere");
			break;
		case PLAY_TYPE:
			pOut->PrintMessage("Action: Select objects of the same type , Click anywhere");
			break;
		case PLAY_FILL:
			pOut->PrintMessage("Action: Select objects of the same color , Click anywhere");
			break;
		case PLAY_TypeFill:
			pOut->PrintMessage("Action: Select objects of the same type and color , Click anywhere");
			break;
		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Action: Switch to Draw Mode, creating simualtion tool bar");
			UI.InterfaceMode = MODE_DRAW;
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Action: Switch to Play Mode, creating Design tool bar");
			pOut->CreatePlayToolBar();
			break;
		case EXIT:
			///create ExitAction here
			
			break;
		case STATUS:	//a click on the status bar ==> no action
			pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsPointInFigure(x, y))
			return FigList[i];
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::SaveAll(ofstream& outfile)
{
	
	outfile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(outfile);
}