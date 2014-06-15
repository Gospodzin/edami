#ifndef _BASE_SET_OF_POINTS_H
#define _BASE_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class BaseSetOfPoints : public SetOfPoints<T>
{
public:
	BaseSetOfPoints(vector<T>& dataSet);
	vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&));
};

template<class T>
BaseSetOfPoints<T>::BaseSetOfPoints(vector<T>& dataSet) : SetOfPoints<T>(dataSet){}

template<class T>
vector<int> BaseSetOfPoints<T>::regionQuery(int& pointId, double eps, double(*measure)(T&, T&))
{
	vector<int> neighbours;
	for (int i = 0; i < this->dataSet.size();i++){
		if (measure(this->dataSet[pointId], this->dataSet[i]) <= eps)
			neighbours.push_back(i);
	}
	return neighbours;
}

#endif 
