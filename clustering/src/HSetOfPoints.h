#ifndef _H_SET_OF_POINTS_H
#define _H_SET_OF_POINTS_H

#include "commons.h"
#include "SetOfPoints.h"

template<class T>
class HSetOfPoints : public SetOfPoints<T>
{
public:
	HSetOfPoints(vector<T> dataSet);
	~HSetOfPoints();
	vector<T*> regionQuery(T& point, double eps, double(*measure)(T&, T&));
	void setIds();
private:
	vector<vector<int>> flags;
};

template<class T>
HSetOfPoints<T>::HSetOfPoints(vector<T> dataSet)
{
	this->dataSet = dataSet;
	flags.resize(dataSet.size());
	for (unsigned i = 0; i < dataSet.size(); ++i)
	{
		flags[i].resize(dataSet.size() - i);
		for (vector<int>::iterator it = flags[i].begin(); it != flags[i].end(); ++it) {
			*it = NOT_DECIDED;
		}
	}
}


template<class T>
HSetOfPoints<T>::~HSetOfPoints()
{
}

template<class T>
vector<T*> HSetOfPoints<T>::regionQuery(T& point, double eps, double(*measure)(T&, T&))
{
	vector<T*> neighbours;
	for (vector<T>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
		int left;
		int right;
		if (point.Id <= it->Id)
		{
			left = point.Id;
			right = it->Id - point.Id;
		}
		else
		{
			left = it->Id;
			right = point.Id - it->Id;
		}

		if (flags[left][right] == NOT_DECIDED)
		{
			if (measure(point, *it) <= eps)
			{
				flags[left][right] = NEIGHBOUR;
				neighbours.push_back(&*it);
			}
			else
			{
				flags[left][right] = NOT_NEIGHBOUR;
			}
		}
		else if (flags[left][right] == NEIGHBOUR)
		{
			neighbours.push_back(&*it);
		}
	}
	return neighbours;
}

template<class T>
void HSetOfPoints<T>::setIds()
{
	for (unsigned i = 0; i < dataSet.size(); i++)
		dataSet[i].Id = i;
}

#endif