#include "Neighborhood.h"

Neighborhood::Neighborhood()
{
}

void Neighborhood::print() {
	cout << "The point" << endl;
	thePoint.print();
	cout << "neighbors" << endl;
	for (vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		oneOfPoints->print();
	}
}

Point Neighborhood::getThePoint(){
	return thePoint;
}

vector<Point> Neighborhood::getNeighbors(){
	return points;
}

int Neighborhood::getCount() {
	return points.size();
}
