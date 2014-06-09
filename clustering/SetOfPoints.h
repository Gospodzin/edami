#ifndef _SET_OF_POINTS_H
#define _SET_OF_POINTS_H
#include "commons.h"
#include "Point.h"

class SetOfPoints
{
public:
	int size();
	Point& operator[](int n);
	virtual vector<Point*> regionQuery(Point point, double eps, double(*measure)(Point, Point)) = 0;
protected:
	vector<Point> dataSet;
};

#endif 
