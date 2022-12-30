#include "ApplicationManager.h"
#include "Actions/Actions.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddSqrAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include "Actions\AddHexAction.h"
#include"SaveAction.h"
#include "Undo.h"
#include "GUI/Output.h"
#include"LoadAction.h"
#include<iostream>
#include "Actions/ClearAll.h"
//Undo undo_tool;
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	undo_tool = new UndoAction(this);
	redo_tool = new RedoAction(this);
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
	SelectedFig = NULL;
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
			//undo_tool.addAct(pAct);
			//undo_tool.clear_redo();
			break;
		case DRAW_SQR:
			pAct = new AddSqrAction(this);
			//undo_tool.addAct(pAct);
			//undo_tool.clear_redo();
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			//undo_tool.addAct(pAct);
			//undo_tool.clear_redo();
			break;
		case DRAW_CRCL:
			pAct = new AddCircAction(this);
			//undo_tool.addAct(pAct);
			//undo_tool.clear_redo();
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			//undo_tool.addAct(pAct);
			//undo_tool.clear_redo();
			break;
		case DRAW_SELECT:
			pAct = new SelectAction(this);
			break;
		case DRAW_FillCol:
			UI.InterfaceMode = MODE_COL_FILL;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_DrawCol:
			UI.InterfaceMode = MODE_COL_DRW;
			pOut->CreateDrawToolBar();
			break;
		case DRAW_BLACK:
			setColors(BLACK);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_YELLOW:
			setColors(YELLOW);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_ORANGE:
			setColors(ORANGE);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_RED:
			setColors(RED);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_BLUE:
			setColors(BLUE);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_GREEN:
			setColors(GREEN);
			if (UI.InterfaceMode == MODE_COL_FILL)
				pAct = new FillAction(this);
			else
				pAct = new DrawClrAction(this);
			break;
		case DRAW_MOVE:
			pAct = new MoveAction(this);
			break;
		case DRAW_DEL:
			pAct = new DeleteAction(this);
			pOut->PrintMessage("Action: Delete object , Click anywhere");
			break;
		case DRAW_UNDO:
			//FigCount = undo_tool.undo(FigCount);
			undo_tool->Execute();
			pOut->ClearDrawArea();
			
			this->UpdateInterface();
			pOut->PrintMessage("Action: Undo action , Click anywhere");
			break;
		case DRAW_REDO:
			//FigCount = undo_tool.redo(FigCount);
			pOut->ClearDrawArea();

			this->UpdateInterface();
			pOut->PrintMessage("Action: Redo action , Click anywhere");
			break;
		case DRAW_CLEAR:
			pAct = new ClearAll(this);
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
			pAct = new LoadAction(this);
			break;
		case PLAY_TYPE:
			pAct = new PickAndHideAction(this, 1);
			break;
		case PLAY_FILL:
			pAct = new PickAndHideAction(this, 2);
			break;
		case PLAY_TypeFill:
			pAct = new PickAndHideAction(this, 3);
			break;
		case DRAWING_AREA:
			pOut->PrintMessage("Action: a click on the Drawing Area, Click anywhere");
			break;

		case EMPTY:
			pOut->PrintMessage("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;

		case TO_DRAW:
			pOut->PrintMessage("Switch to Draw Mode, creating Design tool bar");
			UI.InterfaceMode = MODE_DRAW;
			pOut->CreateDrawToolBar();
			break;

		case TO_PLAY:
			pOut->PrintMessage("Switch to Play Mode, creating simualtion tool bar");
			if (GetSelectedFig() != NULL)
			{
				GetSelectedFig()->SetSelected(false);
				SetSelectedFig(NULL);
			}
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
		if (pAct->ActType() == 1 || pAct->ActType() == 2 || pAct->ActType() == 3 || pAct->ActType() == 4)
			redo_tool->clear();
		if (pAct->ActType() == 3)
		{

			undo_tool->add_fig(this->GetSelectedFig());
		}
		pAct->Execute();//Execute
		if (pAct->ActType() == 4 || pAct->ActType() == 2) //to be done
		{
			//test:
			this->add_act(pAct);
		}
		undo_tool->add_act(pAct->ActType());
		
		

		if (pAct->ActType() != 4 && pAct->ActType() != 2)
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
		{
			return FigList[i];
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SetSelectedFig(CFigure* pFig)
{	SelectedFig = pFig; }

CFigure* ApplicationManager::GetSelectedFig() const
{	return SelectedFig; }

int ApplicationManager::GetFigCount() const
{	return FigCount; }

CFigure* ApplicationManager::GetFigInList(int i) const
{
	if (i < FigCount)
		return FigList[i];
	else
		return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		if (!FigList[i]->IsHidden())
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
	outfile << getCrntDrawClr() << " " << getCrntFillClr() << endl;
	outfile << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
			FigList[i]->SetSelected(false);
		
	}
	for (int i = 0; i < FigCount; i++)
	{
		
			FigList[i]->Save(outfile);
	}
}

void ApplicationManager::setColors(color c)
{
	if (UI.InterfaceMode == MODE_COL_FILL)
	{
		if (c == UI.FillColor && UI.isFilled)
		{
			UI.isFilled = false;
		}
		else
			UI.isFilled = true;
		UI.FillColor = c;
	}
	else
		UI.DrawColor = c;
}
string ApplicationManager::getCrntFillClr() const
{
	if (UI.isFilled == false)
		return "NOTFILLED";
	if (UI.FillColor == BLACK)
		return "BLACK";
	if (UI.FillColor == YELLOW)
		return "YELLOW";
	if (UI.FillColor == ORANGE)
		return "ORANGE";
	if (UI.FillColor == RED)
		return "RED";
	if (UI.FillColor == BLUE)
		return "BLUE";
	if (UI.FillColor == GREEN)
		return "GREEN";
}

string ApplicationManager::getCrntDrawClr() const
{
	if (UI.DrawColor == BLACK)
		return "BLACK";
	if (UI.DrawColor == YELLOW)
		return "YELLOW";
	if (UI.DrawColor == ORANGE)
		return "ORANGE";
	if (UI.DrawColor == RED)
		return "RED";
	if (UI.DrawColor == BLUE)
		return "BLUE";
	if (UI.DrawColor == GREEN)
		return "GREEN";
}
void ApplicationManager::deleteFig(int index)
{
	if (index == FigCount - 1)
	{
		FigList[FigCount - 1] = NULL;
		FigCount--;
	}
	else
	{
		FigList[index] = FigList[FigCount - 1];
		FigList[FigCount - 1] = NULL;
		FigCount--;
	}


}

int ApplicationManager::get_index(CFigure* ptr)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (ptr == FigList[i])
			return i;
	}
	return -1;
}
int ApplicationManager::get_max_ID_index()
{
	int max = (FigList[0]->get_ID());
	int index = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->get_ID() > max)
		{
			max = FigList[i]->get_ID();
			index = i;
		}
	}
	return index;

}

void ApplicationManager::clear_figs()
{
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	FigCount = 0;
}

void ApplicationManager::clear_undo()
{
	undo_tool->clear();
}

void ApplicationManager::clear_gui()
{
	UI.InterfaceMode = MODE_DRAW;
	pOut->CreateDrawToolBar();
	UI.FillColor = GREEN;
	UI.isFilled = false;
	UI.DrawColor = BLUE;
}

void ApplicationManager::add_act(Action* pointer)
{
	if (pointer != NULL)
		undo_tool->add_action(pointer);
	pointer = NULL;
}
