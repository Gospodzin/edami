#ifndef _L_SET_OF_POINTS_H
#define _L_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class LSetOfPoints : public SetOfPoints<T>
{
public:
	LSetOfPoints(vector<T>& dataSet);
	vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&));
	void prepare(T refP, double(*measure)(T&, T&));
private:
	void calculateSquareLengths();
	void sortByLength();
	T& findRefP();
};

template<class T>
LSetOfPoints<T>::LSetOfPoints(vector<T>& dataSet) : SetOfPoints(dataSet)
{
	calculateSquareLengths();
	sortByLength();
}

template<class T>
vector<int> LSetOfPoints<T>::regionQuery(int& pointId, double eps, double(*measure)(T&, T&))
{
	double lowerB = eps*eps*dataSet[pointId].Ref.SquareLen;
	double upperB = dataSet[pointId].Ref.SquareLen / (eps*eps);
	Point& point = dataSet[pointId];
	vector<int> neighbours;
	//search backward
	for (int i = point.Id; i >= 0 && dataSet[i].Ref.SquareLen >= lowerB; i--)
	{
		if (measure(dataSet[pointId], dataSet[i]) >= eps)
			neighbours.push_back(i);
	}
	//search forward
	for (unsigned i = point.Id + 1; i < dataSet.size() && dataSet[i].Ref.SquareLen <= upperB; i++)
	{
		if (measure(dataSet[pointId], dataSet[i]) >= eps)
			neighbours.push_back(i);
	}

	return neighbours;
}

template<class T>
void LSetOfPoints<T>::calculateSquareLengths()
{
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
		it->calcSquareLength();
}

template<class T>
void LSetOfPoints<T>::sortByLength()
{
	std::sort(dataSet.begin(), dataSet.end(), [](T a, T b) {
		return a.Ref.Dist <  b.Ref.Dist;
	});
}
#endif