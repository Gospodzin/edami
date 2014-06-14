#include "commons.h"
#include "Point.h"

#ifndef _MEASURES_H
#define _MEASURES_H

namespace measures
{
	template<class T> double euclideanDistance(T& p1, T& p2);
	template<class T> double minusCosSim(T& p1, T& p2);
	template<class T> double minusNormCosSim(T& p1, T& p2);
	template<class T> double minusTanimotoSim(T& p1, T& p2);
	template<class T> double minusNormTanimotoSim(T& p1, T& p2);
}


template<class T>
double measures::euclideanDistance(T& p1, T& p2) {

	double sum = 0.0;

	for (int i = 0; i < p1.size(); ++i) {
		double coord1 = p1[i];
		double coord2 = p2[i];
		double difference = (coord1 - coord2);
		sum += difference*difference;
	}

	return sqrt(sum);
}

template<class T>
double measures::minusCosSim(T& p1, T& p2) {
	double dotProd = p1.dotProd(p2);
	double p1SquareLength = p1.dotProd(p1);
	double p2SquareLength = p2.dotProd(p2);

	return -dotProd / sqrt(p1SquareLength*p2SquareLength);
}

template<class T>
double measures::minusNormCosSim(T& p1, T& p2) {
	double dotProd = p1.dotProd(p2);
	return -dotProd;
}

template<class T>
double measures::minusTanimotoSim(T& p1, T& p2) {
	double dotProd = p1.dotProd(p2);
	double p1SquareLength = p1.dotProd(p1);
	double p2SquareLength = p2.dotProd(p2);

	return -dotProd / (p1SquareLength + p2SquareLength - dotProd);
}

template<class T>
double measures::minusNormTanimotoSim(T& p1, T& p2) {
	double dotProd = p1.dotProd(p2);
	return -dotProd / (2 - dotProd);
}

#endif 
