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

double Neighborhood::getVarianceAlongAttr(int n, double (*distanceMeasure)(Point, Point)) {
	double sum = 0.0;
	for (vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		double dist = distanceMeasure(thePoint, oneOfPoints->getProjectionOntoNthAttr(n));
		sum = sum + (dist * dist);
	}
	return sum / getCount();
}
