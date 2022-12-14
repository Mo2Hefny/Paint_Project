#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	static unsigned int IDcounter;
	bool Selected;	//true if the figure is selected.
	bool Hidden;
	bool deleted;
	GfxInfo FigGfxInfo;	//Figure graphis info
	GfxInfo OldFigGfxInfo;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();
	void SetSelected(bool s);	//select/unselect the figure
	void SetIsFilled(bool Fill);
	void Hide(bool s);
	bool IsSelected() const;	//check whether fig is selected
	bool IsFilled() const;
	bool IsHidden() const;
	virtual bool IsPointInFigure(int, int) const = 0;
	virtual void Draw(Output* pOut) const = 0;		//Draw the figure
	GfxInfo getGfxInfo() const;
	color getFillClr() const;
	color getDrawClr();
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	virtual void PrintInfo(Output* pOut) const = 0;
	string getDrawClrStr() const;
	string getFillClrStr() const;
	virtual Point GetCenter() const = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void move(int x, int y) = 0;
	virtual void Save(ofstream& outfile) = 0;
	//virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	//virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file
	virtual void load(ifstream& infile) = 0;
	int get_ID() const;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	bool IsDeleted() const;
	void Delete(bool s);

};

#endif