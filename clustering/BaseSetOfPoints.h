#ifndef _BASE_SET_OF_POINTS_H
#define _BASE_SET_OF_POINTS_H
#include "Point.h"
#include "SetOfPoints.h"

class BaseSetOfPoints : public SetOfPoints
{
public:
	BaseSetOfPoints(vector<Point> dataSet);
	~BaseSetOfPoints();
	vector<Point*> regionQuery(Point point, double eps, double(*measure)(Point, Point));
};

#endif 
