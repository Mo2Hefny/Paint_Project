#include "ApplicationManager.h"
#include "GUI/Output.h"
#include<iostream>
#include"Actions/Actions.h"

ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	IsRecording = false;
	RecordedCount = 0;
	FigCount = 0;
	undo_tool = new UndoAction(this);
	redo_tool = new RedoAction(this);
	//Create an array of figure pointers and set them to NULL		
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = NULL;
	for (int i = 0; i < MaxRecordedCount; i++)
		RecordingList[i] = NULL;
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
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, BLACK);
		else
			pAct = new DrawClrAction(this, BLACK);
		break;
	case DRAW_YELLOW:
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, YELLOW);
		else
			pAct = new DrawClrAction(this, YELLOW);
		break;
	case DRAW_ORANGE:
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, ORANGE);
		else
			pAct = new DrawClrAction(this, ORANGE);
		break;
	case DRAW_RED:
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, RED);
		else
			pAct = new DrawClrAction(this, RED);
		break;
	case DRAW_BLUE:
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, BLUE);
		else
			pAct = new DrawClrAction(this, BLUE);
		break;
	case DRAW_GREEN:
		if (UI.InterfaceMode == MODE_COL_FILL)
			pAct = new FillAction(this, GREEN);
		else
			pAct = new DrawClrAction(this, GREEN);
		break;
	case DRAW_MOVE:
		if (GetSelectedFig() != NULL)
			pAct = new MoveAction(this);
		else
			pOut->PrintMessage("No Selected Object.");
		break;
	case DRAW_DEL:
		if (GetSelectedFig() != NULL)
			pAct = new DeleteAction(this);
		else
			pOut->PrintMessage("No Selected Object.");
		break;
	case DRAW_UNDO:
		undo_tool->Execute();

		break;
	case DRAW_REDO:
		redo_tool->Execute();

		break;
	case DRAW_CLEAR:
		pAct = new ClearAll(this);
		break;
	case DRAW_StartRec:
		pAct = new StartRecordingAction(this);
		break;
	case DRAW_StopRec:
		pAct = new StopRecordingAction(this);
		break;
	case DRAW_PlayRec:
		pAct = new PlayRecordAction(this);
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
		pAct = new SwitchDraw(this);
		break;
	case TO_PLAY:
		pAct = new SwitchPlay(this);
		break;
	case EXIT:
		pAct = new ExitAction(this);
		break;
	case STATUS:	//a click on the status bar ==> no action
		pOut->PrintMessage("Action: a click on the Status Bar, Click anywhere");
		return;
	}

	//Execute the created action
	if (pAct != NULL)
	{
		if (pAct->ActType() != 7) //undo or select;
			redo_tool->clear();
		if (pAct->ActType() == 3)
		{

			undo_tool->add_fig(this->GetSelectedFig());
		}

		if (pAct->ActType() == 4 || pAct->ActType() == 2) //to be done
		{
			//test:
			this->add_act(pAct);
		}
		pAct->Execute();//Execute
		undo_tool->add_act(pAct->ActType());



		if (pAct->ActType() != 4 && pAct->ActType() != 2 && get_IsRecording() == false)
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
	if (FigCount < MaxFigCount)
		FigList[FigCount++] = pFig;
}
////////////////////////////////////////////////////////////////////////////////////
CFigure* ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsPointInFigure(x, y) && !FigList[i]->IsHidden())
		{
			return FigList[i];
		}
	}
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.

	return NULL;
}

void ApplicationManager::SetSelectedFig(CFigure* pFig)
{
	SelectedFig = pFig;
}

CFigure* ApplicationManager::GetSelectedFig() const
{
	return SelectedFig;
}

int ApplicationManager::GetFigCount() const
{
	int counter = 0;
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->IsDeleted())
			counter++;
	return counter;
}

int ApplicationManager::Get_Real_FigCount() const
{
	return FigCount;
}

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
	for (int i = 0; i < FigCount; i++)
		if (!FigList[i]->IsDeleted() && !FigList[i]->IsHidden())
			FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input* ApplicationManager::GetInput() const
{
	return pIn;
}
//Return a pointer to the output
Output* ApplicationManager::GetOutput() const
{
	return pOut;
}
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	delete undo_tool;
	delete redo_tool;

}
void ApplicationManager::SaveAll(ofstream& outfile)
{
	outfile << getCrntDrawClr() << " " << getCrntFillClr() << endl;
	outfile << GetFigCount() << endl;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected() == true)
			FigList[i]->SetSelected(false);

	}
	for (int i = 0; i < FigCount; i++)
	{
		if (!FigList[i]->IsDeleted() && !FigList[i]->IsHidden())			//test
			FigList[i]->Save(outfile);
	}
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
	FigList[index]->Hide(true);
	FigList[index]->Delete(true);
	FigList[index]->SetSelected(false);
	SetSelectedFig(NULL);
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
int ApplicationManager::get_max_ID_index(bool wanted)
{
	int max = 0;
	int index = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->get_ID() > max && FigList[i]->IsHidden() == wanted && FigList[i]->IsDeleted() == wanted)
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
	UI.FillColor = LIGHTGOLDENRODYELLOW;
	UI.isFilled = false;
	UI.DrawColor = BLUE;
}

void ApplicationManager::add_act(Action* pointer)
{
	if (pointer != NULL)
		undo_tool->add_action(pointer);
	pointer = NULL;
}

void ApplicationManager::send_action_redo(int val, Action* ptr)
{
	if (ptr != NULL)
	{
		redo_tool->add_action(ptr);
		redo_tool->add_act(ptr->ActType());
	}
	else
		redo_tool->add_act(val);
}
void ApplicationManager::send_action_undo(int val, Action* ptr)
{
	if (ptr != NULL)
	{
		undo_tool->add_action(ptr);
		undo_tool->add_act(ptr->ActType());
	}
	else
		undo_tool->add_act(val);
}

void ApplicationManager::send_fig_undo(CFigure* ptr)
{
	undo_tool->add_fig(ptr);
	ptr = NULL;
}

void ApplicationManager::send_fig_redo(CFigure* ptr)
{

	redo_tool->add_fig(ptr);
	ptr = NULL;
}

int ApplicationManager::get_RecordedCount() const
{
	return RecordedCount;
}

bool ApplicationManager::get_IsRecording() const
{
	return IsRecording;
}

void ApplicationManager::set_IsRecording(bool b)
{
	IsRecording = b;
}

void ApplicationManager::AddToRecordingList(Action* p)
{
	if (RecordedCount < MaxRecordedCount)
		RecordingList[RecordedCount++] = p;
	else
	{
		pOut->PrintMessage("You exceeded the allowable number of actions to record, Recording Stopped ");
		set_IsRecording(false);
	}
}

void ApplicationManager::clear_recording()
{
	for (int i = 0; i < RecordedCount; i++)
		RecordingList[i] = NULL;
	RecordedCount = 0;
}

void ApplicationManager::PlayAll()
{
	clear_figs();
	clear_undo();
	clear_gui();
	pOut->ClearDrawArea();
	for (int i = 0; i < RecordedCount; i++)
	{
		Sleep(1000);

		RecordingList[i]->play();
		add_to_tools(RecordingList[i]);


		GetOutput()->ClearDrawArea();
		UpdateInterface();
	}
}

void ApplicationManager::Fig_Unhide(int index)
{
	FigList[index]->Hide(false);
}

void ApplicationManager::Fig_Undel(int index)
{
	FigList[index]->Delete(false);
}

void ApplicationManager::Transfer_index(int index)
{
	redo_tool->add_index(index);
}

void ApplicationManager::add_to_tools(Action* p_Act)
{

	if (p_Act != NULL)
	{
		if (p_Act->ActType() == 1 || p_Act->ActType() == 2 || p_Act->ActType() == 3 || p_Act->ActType() == 4) //undo or select;
			redo_tool->clear();
		if (p_Act->ActType() == 3)
		{

			undo_tool->add_fig(p_Act->get_deleted());

		}

		if (p_Act->ActType() == 4 || p_Act->ActType() == 2) //to be done
		{
			//test:
			this->add_act(p_Act);
		}

		undo_tool->add_act(p_Act->ActType());




		//if (pAct->ActType() != 4 && pAct->ActType() != 2 && get_IsRecording() == false)
		p_Act = NULL;
	}
}
