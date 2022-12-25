#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Vertix1;
	Point Vertix2;
	Point Vertix3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	virtual void PrintInfo(Output* pOut) const;
	void Save(ofstream& outfile);
};

#endif