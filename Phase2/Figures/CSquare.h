#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	void Save(ofstream& outfile);
	virtual void PrintInfo(Output* pOut) const;
};

#endif