#include "EpsNeighborhood.h"
#include "utils.h"

double EpsNeighborhood::getVarianceAlongAttr(int n) {
	double sum = 0.0;
	for (vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		double dist = distanceMeasure(thePoint, oneOfPoints->getProjectionOntoNthAttr(n));
		sum = sum + (dist * dist);
	}
	return sum / getCount();
}

void EpsNeighborhood::computeSubspacePreferenceParameters(double delta, double kappa){
	for (int i = 0; i < thePoint.getAttrsNumber(); ++i) {
		double variance = getVarianceAlongAttr(i);
		if(variance <= delta){
			subspacePreferenceVector.push_back(kappa);
			subspacePreferenceDimensionality++;
		}
		else
			subspacePreferenceVector.push_back(1.0);
	}
}

vector<double> EpsNeighborhood::getSubspacePreferenceVector(){
	return subspacePreferenceVector;
}

int EpsNeighborhood::getPreferenceDimensionality(){
	return subspacePreferenceDimensionality;
}

double EpsNeighborhood::getPreferenceWeightedDistanceTo(Point otherPoint){
	double sum = 0.0;
	for (int i = 0; i < thePoint.getAttrsNumber(); ++i) {
		double diff = thePoint[i] - otherPoint[i];
		sum += subspacePreferenceVector[i] * diff * diff;
	}
	return sqrt(sum);
}
