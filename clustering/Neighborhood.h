#ifndef _NEIGHBORHOOD_H
#define _NEIGHBORHOOD_H

#include "commons.h"

#include "Point.h"

class Neighborhood
{
protected:
	Point thePoint;
	vector<Point> points;

public:

	Neighborhood();
	Neighborhood(Point thePoint, vector<Point> points): thePoint(thePoint), points(points) {}

	void print();

	int getCount();

	Point getThePoint();
	vector<Point> getNeighbors();
};

#endif 
