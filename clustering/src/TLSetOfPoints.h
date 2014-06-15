#ifndef _TL_SET_OF_POINTS_H
#define _TL_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class TLSetOfPoints : public SetOfPoints<T>
{
public:
	TLSetOfPoints(vector<T>& dataSet);
	vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&));
	void prepare(T refP, double(*measure)(T&, T&));
private:
	void calculateSquareLengths();
	void sortByLength();
	T& findRefP();
};

template<class T>
TLSetOfPoints<T>::TLSetOfPoints(vector<T>& dataSet) : SetOfPoints(dataSet)
{
	calculateSquareLengths();
	sortByLength();
}

template<class T>
vector<int> TLSetOfPoints<T>::regionQuery(int& pointId, double eps, double(*measure)(T&, T&))
{
	double lowerB = eps*dataSet[pointId].Ref.SquareLen;
	double upperB = dataSet[pointId].Ref.SquareLen / eps;
	Point& point = dataSet[pointId];
	vector<int> neighbours;
	//search upwards
	for (int i = point.Id; i >= 0 && dataSet[i].Ref.SquareLen >= lowerB; i--)
	{
		if (measure(dataSet[pointId], dataSet[i]) >= eps)
			neighbours.push_back(i);
	}
	//search downwards
	for (unsigned i = point.Id + 1; i < dataSet.size() && dataSet[i].Ref.SquareLen <= upperB; i++)
	{
		if (measure(dataSet[pointId], dataSet[i]) >= eps)
			neighbours.push_back(i);
	}

	return neighbours;
}

template<class T>
void TLSetOfPoints<T>::calculateSquareLengths()
{
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
		it->calcSquareLength();
}

template<class T>
void TLSetOfPoints<T>::sortByLength()
{
	std::sort(dataSet.begin(), dataSet.end(), [](T a, T b) {
		return a.Ref.Dist <  b.Ref.Dist;
	});
}
#endif