#ifndef _TI_SET_OF_POINTS_H
#define _TI_SET_OF_POINTS_H
#include "SetOfPoints.h"

class TISetOfPoints : public SetOfPoints
{
public:
	TISetOfPoints(vector<Point> dataSet, Point refP, double(*measure)(Point, Point));
	~TISetOfPoints();
	vector<Point*> regionQuery(Point& point, double eps, double(*measure)(Point, Point));
private:
	void sortByRefDist();
	void calculateRefDists(Point refP, double(*measure)(Point, Point));
	void setIds();
};

#endif