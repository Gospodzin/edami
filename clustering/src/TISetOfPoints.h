#ifndef _TI_SET_OF_POINTS_H
#define _TI_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class TISetOfPoints : public SetOfPoints<T>
{
public:
	TISetOfPoints(vector<T>& dataSet);
	vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&));
	void prepare(double(*measure)(T&, T&));
private:
	void sortByRefDist();
	void calculateRefDists(T refP, double(*measure)(T&, T&));
	T getRefP();
};

template<class T>
TISetOfPoints<T>::TISetOfPoints(vector<T>& dataSet) : SetOfPoints<T>(dataSet){}

template<class T>
void TISetOfPoints<T>::prepare(double(*measure)(T&, T&))
{
	cout << "Calculating ref distances..." << endl;
	clock_t start = clock();
	calculateRefDists(getRefP(), measure);
	clock_t ends = clock();
	cout << "time: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	start = clock();
	cout << "Sorting data..." << endl;
	sortByRefDist();
	ends = clock();
	cout << "time: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	this->setIds();
}

template<class T>
vector<int> TISetOfPoints<T>::regionQuery(int& pointId, double eps, double(*measure)(T&, T&))
{
	T& point = this->dataSet[pointId];
	vector<int> neighbours;
	//search backward
	for (int i = pointId; i >= 0 && abs(point.Ref.Dist - this->dataSet[i].Ref.Dist) <= eps; i--)
	{
		if (measure(point, this->dataSet[i]) <= eps)
			neighbours.push_back(i);
	}
	//search forward
	for (unsigned i = pointId + 1; i < this->dataSet.size() && abs(point.Ref.Dist - this->dataSet[i].Ref.Dist) <= eps; i++)
	{
		if (measure(point, this->dataSet[i]) <= eps)
			neighbours.push_back(i);
	}

	return neighbours;
}

template<class T>
void TISetOfPoints<T>::sortByRefDist()
{
	std::sort(this->dataSet.begin(), this->dataSet.end(), [](T a, T b) {
		return a.Ref.Dist <  b.Ref.Dist;
	});
}

template<class T>
void TISetOfPoints<T>::calculateRefDists(T refP, double(*measure)(T&, T&))
{
	for (typename vector<T>::iterator it = this->dataSet.begin(); it != this->dataSet.end(); ++it)
		it->Ref.Dist = measure(*it, refP);
}

template<class T>
T TISetOfPoints<T>::getRefP()
{
	vector<double> max(this->dataSet[0].size());
	for (typename vector<T>::iterator it = this->dataSet.begin(); it != this->dataSet.end(); ++it)
	{
		for (int i = 0; i < this->dataSet[0].size(); i++)
		{
			if (max[i] < abs((*it)[i]))
			{
				max[i] = (*it)[i];
			}
		}
	}

	return max;
}

#endif
