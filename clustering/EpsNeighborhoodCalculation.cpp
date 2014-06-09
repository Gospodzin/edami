#include "EpsNeighborhoodCalculation.h"

#include "Measures.h"

EpsNeighborhood bruteForceEpsNeighborhoodCalc(double eps, Point thePoint, vector<Point> otherPoints, double (*distanceMeasure)(Point,Point)){
	vector<Point> pointsInNeighborhood;
	for(vector<Point>::iterator it = otherPoints.begin(); it != otherPoints.end(); ++it) {
	    if(distanceMeasure(thePoint,*it) <= eps)
	    	pointsInNeighborhood.push_back(*it);
	}
	return EpsNeighborhood(thePoint, pointsInNeighborhood, euclideanDistance);
}
