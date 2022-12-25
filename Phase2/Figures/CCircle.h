#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Edge;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& outfile);
	virtual void PrintInfo(Output* pOut) const;
};

#endif