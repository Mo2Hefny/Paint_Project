#ifndef CCIRC_H
#define CCIRC_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Center;
	Point Edge;
	double Radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);
	CCircle();
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	virtual void move(int x, int y);
	virtual Point GetCenter() const;
	void Save(ofstream& outfile);
	virtual void PrintInfo(Output* pOut) const;
	virtual void load(ifstream& infile);
};

#endif