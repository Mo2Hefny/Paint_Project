#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& outfile);
	virtual void PrintInfo(Output* pOut) const;
};

#endif