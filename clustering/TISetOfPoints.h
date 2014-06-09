#ifndef _TI_SET_OF_POINTS_H
#define _TI_SET_OF_POINTS_H
#include "SetOfPoints.h"

class TISetOfPoints : public SetOfPoints
{
public:
	TISetOfPoints(vector<Point> dataSet);
	~TISetOfPoints();
	vector<Point*> regionQuery(Point point, double eps, double(*measure)(Point, Point));
	void sortByReferencePoint(Point refP, double(*measure)(Point, Point));
private:
	vector<double> rDists;
};

#endif