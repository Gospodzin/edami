#ifndef _SET_OF_POINTS_H
#define _SET_OF_POINTS_H
#include "commons.h"

template<class T>
class SetOfPoints
{
public:
	int size();
	T& operator[](int n);
	void normalize();
	virtual vector<T*> regionQuery(T& point, double eps, double(*measure)(T&, T&)) = 0;
protected:
	vector<T> dataSet;
};

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
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
	{
		it->normalize();
	}
}
#endif 
