#include "Neighborhood.h"

void Neighborhood::print() {
	cout << "The point" << endl;
	thePoint.print();
	cout << "neighbors" << endl;
	for (vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		oneOfPoints->print();
	}
}

int Neighborhood::getCount() {
	return (points.size()) + 1;
}

double Neighborhood::getVarianceAlongAttr(int n) {
	double sum = 0.0;
	for (vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		double dist = distanceMeasure(thePoint, oneOfPoints->getProjectionOntoNthAttr(n));
		sum = sum + (dist * dist);
	}
	return sum / getCount();
}

void Neighborhood::computeSubspacePreferenceParameters(double delta, double kappa){
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

vector<double> Neighborhood::getSubspacePreferenceVector(){
	return subspacePreferenceVector;
}

int Neighborhood::getPreferenceDimensionality(){
	return subspacePreferenceDimensionality;
}

double Neighborhood::getPreferenceWeightedDistanceTo(Point otherPoint){
	double sum = 0.0;
	for (int i = 0; i < thePoint.getAttrsNumber(); ++i) {
		double diff = thePoint.getNthAttr(i) - otherPoint.getNthAttr(i);
		sum += subspacePreferenceVector[i] * diff * diff;
	}
	return sqrt(sum);
}
