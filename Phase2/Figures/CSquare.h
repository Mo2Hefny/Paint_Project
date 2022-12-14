#ifndef CSQR_H
#define CSQR_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	CSquare();
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	virtual void move(int x, int y);
	virtual Point GetCenter() const;
	virtual void PrintInfo(Output* pOut) const;
	void Save(ofstream& outfile);
	void load(ifstream& infile);
};

#endif