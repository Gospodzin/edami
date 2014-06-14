#ifndef _EPSNEIGHBORHOOD_H
#define _EPSNEIGHBORHOOD_H

#include "Neighborhood.h"
#include "Point.h"

class EpsNeighborhood : public Neighborhood
{
private:
	double (*distanceMeasure)(Point*,Point*);
	vector<double> subspacePreferenceVector;
	int subspacePreferenceDimensionality;

public:
	EpsNeighborhood(){}
	EpsNeighborhood(Point * thePoint, vector<Point*> points, double (*distanceMeasure)(Point*,Point*))
		: Neighborhood(thePoint, points), distanceMeasure(distanceMeasure), subspacePreferenceDimensionality(0) {}

	double getVarianceAlongAttr(int n);
	void computeSubspacePreferenceParameters(double delta, double kappa);
	vector<double> getSubspacePreferenceVector();
	int getPreferenceDimensionality();
	double getPreferenceWeightedDistanceTo(Point * point);
};

#endif 
