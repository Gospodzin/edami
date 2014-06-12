#include "Measures.h"

double measures::euclideanDistance(Point p1, Point p2) {

	double sum = 0.0;

	for(int i = 0; i < p1.getAttrsNumber(); ++i) {
		double coord1 = p1.getNthAttr(i);
		double coord2 = p2.getNthAttr(i);
		double difference = (coord1-coord2);
		sum += difference*difference;
	}

	return sqrt(sum);
}

double measures::minusCosSim(Point p1, Point p2) {
	double dotProd = inner_product(p1.coordinates.begin(), p1.coordinates.end(), p2.coordinates.begin(), (double)0);
	double p1SquareLength = inner_product(p1.coordinates.begin(), p1.coordinates.end(), p1.coordinates.begin(), (double)0);
	double p2SquareLength = inner_product(p2.coordinates.begin(), p2.coordinates.end(), p2.coordinates.begin(), (double)0);
	
	return - dotProd / sqrt(p1SquareLength*p2SquareLength);
}

double measures::minusNormCosSim(Point p1, Point p2) {
	double dotProd = inner_product(p1.coordinates.begin(), p1.coordinates.end(), p2.coordinates.begin(), (double)0);
	return -dotProd;
}
