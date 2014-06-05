#ifndef _NEIGHBORHOOD_H
#define _NEIGHBORHOOD_H

#include "commons.h"

#include "Point.h"

class Neighborhood
{
private:
	Point thePoint;
	vector<Point> points;

public:
	Neighborhood(Point thePoint, vector<Point> points) : thePoint(thePoint), points(points) {}

	void print();

	int getCount();
	double getVarianceAlongAttr(int n, double (*distanceMeasure)(Point,Point));
	vector<double> getSubspacePreferenceVector(double delta, double kappa, double (*distanceMeasure)(Point,Point));
};

#endif 
