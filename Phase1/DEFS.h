#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_SHAPE,
	DRAW_RECT,		//Draw Rectangle
	DRAW_SQR,
	DRAW_TRI,
	DRAW_CRCL,
	DRAW_HEX,
	DRAW_SELECT,
	DRAW_FillCol,
	DRAW_DrawCol,
	DRAW_BLACK,
	DRAW_YELLOW,
	DRAW_ORANGE,
	DRAW_RED,
	DRAW_BLUE,
	DRAW_GREEN,
	DRAW_MOVE,
	DRAW_DEL,
	DRAW_UNDO,
	DRAW_REDO,
	DRAW_CLEAR,
	DRAW_StartRec,
	DRAW_StopRec,
	DRAW_PlayRec,
	DRAW_SAVE,
	DRAW_LOAD,
	PLAY_TYPE,
	PLAY_FILL,
	PLAY_TypeFill,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif