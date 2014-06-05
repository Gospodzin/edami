#ifndef _NEIGHBORHOOD_H
#define _NEIGHBORHOOD_H

#include "commons.h"

#include "Point.h"

class Neighborhood
{
private:
	Point thePoint;
	std::vector<Point> points;

public:
	Neighborhood(Point thePoint, std::vector<Point> points) : thePoint(thePoint), points(points) {}

	int getCount();
	double getVarianceAlongAttr(int n, double (*distanceMeasure)(Point,Point));
};

#endif 
