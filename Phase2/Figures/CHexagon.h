#ifndef CHEX_H
#define CHEX_H

#include "CFigure.h"

class CHexagon : public CFigure
{
private:
	Point Center;
public:
	CHexagon(Point, GfxInfo FigureGfxInfo);
	bool IsPointInFigure(int x, int y) const;
	virtual void Draw(Output* pOut) const;
	virtual void move(int x, int y);
	virtual Point GetCenter() const;
	virtual void PrintInfo(Output* pOut) const;
	void Save(ofstream& outfile);
};

#endif