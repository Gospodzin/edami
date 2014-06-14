#ifndef _TI_SET_OF_POINTS_H
#define _TI_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class TISetOfPoints : public SetOfPoints<T>
{
public:
	TISetOfPoints(vector<T> dataSet, T refP, double(*measure)(T&, T&));
	vector<T*> regionQuery(T& point, double eps, double(*measure)(T&, T&));
private:
	void sortByRefDist();
	void calculateRefDists(T refP, double(*measure)(T&, T&));
	void setIds();
	T getRefP();
};

template<class T>
TISetOfPoints<T>::TISetOfPoints(vector<T> dataSet, T refP, double(*measure)(T&, T&))
{
	this->dataSet = dataSet;
	calculateRefDists(refP, measure);
	sortByRefDist();
	setIds();

}

template<class T>
vector<T*> TISetOfPoints<T>::regionQuery(T& point, double eps, double(*measure)(T&, T&))
{
	vector<T*> neighbours;
	//search upwards
	for (int i = point.Id; i >= 0 && abs(point.Ref.Dist - dataSet[i].Ref.Dist) <= eps; i--)
	{
		if (measure(point, dataSet[i]) <= eps)
			neighbours.push_back(&dataSet[i]);
	}
	//search downwards
	for (unsigned i = point.Id + 1; i < dataSet.size() && abs(point.Ref.Dist - dataSet[i].Ref.Dist) <= eps; i++)
	{
		if (measure(point, dataSet[i]) <= eps)
			neighbours.push_back(&dataSet[i]);
	}

	return neighbours;
}

template<class T>
void TISetOfPoints<T>::sortByRefDist()
{
	std::sort(dataSet.begin(), dataSet.end(), [](T a, T b) {
		return a.Ref.Dist <  b.Ref.Dist;
	});
}

template<class T>
void TISetOfPoints<T>::calculateRefDists(T refP, double(*measure)(T&, T&))
{
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
		it->Ref.Dist = measure(*it, refP);
}

template<class T>
void TISetOfPoints<T>::setIds()
{
	for (unsigned i = 0; i < dataSet.size(); i++)
		dataSet[i].Id = i;
}

template<class T>
T TISetOfPoints<T>::getRefP()
{

}

#endif