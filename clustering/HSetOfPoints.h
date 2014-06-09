#ifndef _H_SET_OF_POINTS_H
#define _H_SET_OF_POINTS_H

#include "commons.h"
#include "SetOfPoints.h"
#include "Point.h"

class HSetOfPoints : public SetOfPoints
{
public:
	HSetOfPoints(vector<Point> dataSet);
	~HSetOfPoints();
	vector<Point*> regionQuery(Point& point, double eps, double(*measure)(Point, Point));
	void setIds();
private:
	vector<vector<int>> flags;
};

#endif