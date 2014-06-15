#ifndef _SET_OF_POINTS_H
#define _SET_OF_POINTS_H
#include "commons.h"

template<class T>
class SetOfPoints
{
public:
	SetOfPoints(vector<T>& dataSet);
	int size();
	T& operator[](int n);
	void normalize();
	void setIds();
	virtual vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&)) = 0;
protected:
	vector<T> dataSet;
};

template<class T>
SetOfPoints<T>::SetOfPoints(vector<T>& dataSet)
{ 
	this->dataSet = dataSet; 
	setIds();
}

template<class T>
void SetOfPoints<T>::setIds()
{
	for (unsigned i = 0; i < dataSet.size(); i++)
		dataSet[i].Id = i;
}

template<class T>
int SetOfPoints<T>::size()
{
	return dataSet.size();
}

template<class T>
T& SetOfPoints<T>::operator[](int n)
{
	return dataSet[n];
}

template<class T>
void SetOfPoints<T>::normalize()
{
	for (typename vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
	{
		it->normalize();
	}
}
#endif 
