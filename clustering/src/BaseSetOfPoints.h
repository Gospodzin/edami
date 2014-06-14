#ifndef _BASE_SET_OF_POINTS_H
#define _BASE_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class BaseSetOfPoints : public SetOfPoints<T>
{
public:
	BaseSetOfPoints(vector<T> dataSet);
	~BaseSetOfPoints();
	vector<T*> regionQuery(T& point, double eps, double(*measure)(T&, T&));
};

template<class T>
BaseSetOfPoints<T>::BaseSetOfPoints(vector<T> dataSet)
{
	this->dataSet = dataSet;
}

template<class T>
BaseSetOfPoints<T>::~BaseSetOfPoints()
{
}

template<class T>
vector<T*> BaseSetOfPoints<T>::regionQuery(T& point, double eps, double(*measure)(T&, T&))
{
	vector<T*> neighbours;
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
		if (measure(point, *it) <= eps)
			neighbours.push_back(&*it);
	}
	return neighbours;
}

#endif 
