#ifndef _SET_OF_POINTS_H
#define _SET_OF_POINTS_H
#include "Point.h"

class SetOfPoints
{
public:
	SetOfPoints(vector<Point> dataSet);
	~SetOfPoints();
	int size();
	Point& operator[](int n);
	vector<Point*> regionQuery(Point point, double eps);
private:
	vector<Point> dataSet;
};

#endif 
