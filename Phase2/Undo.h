#pragma once
#include "Actions/Action.h"
#include "Figures/CFigure.h"
class Undo

{
protected:
    int current;
    int current_redo;
    int ptrs[5];
    int ptrs_redo[5];
public:
    Undo();
    void addAct(Action*);
    int undo(int x); //takes input fig_count
    int redo(int y); //takes input fig_count
    void clear_redo();
};
