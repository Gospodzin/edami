#ifndef _NEIGHBORHOOD_H
#define _NEIGHBORHOOD_H

#include "commons.h"

#include "Point.h"

template<class T>
class Neighborhood
{
protected:
	T * thePoint;
	vector<T*> points;

public:

	Neighborhood();
	Neighborhood(T * thePoint, vector<T*> points): thePoint(thePoint), points(points) {}

	void print();

	int getCount();

	T * getThePoint();
	vector<T*> getNeighbors();
};

template<class T>
Neighborhood<T>::Neighborhood()
{
}

template<class T>
void Neighborhood<T>::print() {
	cout << "The point" << endl;
	thePoint->print();
	cout << "neighbors" << endl;
	for (typename vector<T*>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints) {
		(*oneOfPoints)->print();
	}
}

template<class T>
T * Neighborhood<T>::getThePoint(){
	return thePoint;
}

template<class T>
vector<T*> Neighborhood<T>::getNeighbors(){
	return points;
}

template<class T>
int Neighborhood<T>::getCount() {
	return points.size();
}

#endif 
