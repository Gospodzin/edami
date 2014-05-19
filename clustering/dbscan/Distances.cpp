#include "Distances.h"

#include <cmath>

double euclideanDistance(Point p1, Point p2) {

	double sum;

	for(int i = 0; i < p1.coordinates.size(); ++i) {
		double coord1 = p1.coordinates[i];
		double coord2 = p2.coordinates[i];
		sum += (coord1-coord2)*(coord1-coord2);
	}

	return sqrt(sum);
}
