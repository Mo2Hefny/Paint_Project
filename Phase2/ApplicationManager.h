#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

#include<fstream>

#include"Actions/DeleteAction.h"
#include "Actions/UndoAction.h"
#include "Actions/RedoAction.h"

//Main class that manages everything in the application.
class RedoAction;
class UndoAction;
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures
	enum { MaxRecordedCount = 20 };

private:
	int FigCount, RecordedCount;		//Actual number of figures
	bool IsRecording;
	Action* RecordingList[MaxRecordedCount];
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	UndoAction* undo_tool;
	RedoAction* redo_tool;
	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;

public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void SetSelectedFig(CFigure* pFig);
	CFigure* GetSelectedFig() const;
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	int GetFigCount() const;
	int Get_Real_FigCount() const;
	CFigure* GetFigInList(int) const;
	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SaveAll(ofstream& outfile);
	string getCrntFillClr() const;
	string getCrntDrawClr() const;
	void deleteFig(int); //deletes the figure of an index;
	int get_index(CFigure* ptr); // gets an index of a figure;
	int get_max_ID_index(bool);		//returns index of max id
	int get_min_ID_index(bool);
	void clear_figs();
	void clear_undo();
	void clear_gui();
	//test:
	void add_act(Action* pointer);
	int get_RecordedCount() const;
	bool get_IsRecording() const;
	void set_IsRecording(bool b);
	void AddToRecordingList(Action* p);
	void clear_recording();
	void PlayAll();
	//test for redo;
	void send_action_redo(int val, Action* ptr);
	void send_action_undo(int val, Action* ptr);
	void send_fig_undo(CFigure* ptr);
	void send_fig_redo(CFigure* ptr);

	void Fig_Unhide(int index);
	void Fig_Undel(int index);
	void add_to_tools(Action* p_Act); //adds action to undo and redo tools

};

#endif