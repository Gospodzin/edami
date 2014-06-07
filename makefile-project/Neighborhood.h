#ifndef _NEIGHBORHOOD_H
#define _NEIGHBORHOOD_H

#include "commons.h"

#include "Point.h"

class Neighborhood
{
private:
	Point thePoint;
	vector<Point> points;
	vector<double> subspacePreferenceVector;
	double (*distanceMeasure)(Point,Point);
	int subspacePreferenceDimensionality;

public:
	Neighborhood(Point thePoint, vector<Point> points, double (*distanceMeasure)(Point,Point))
		: thePoint(thePoint), points(points), distanceMeasure(distanceMeasure), subspacePreferenceDimensionality(0) {}

	void print();

	int getCount();
	double getVarianceAlongAttr(int n);
	void computeSubspacePreferenceParameters(double delta, double kappa);
	vector<double> getSubspacePreferenceVector();
	int getPreferenceDimensionality();
	double getPreferenceWeightedDistanceTo(Point point);
};

#endif 
