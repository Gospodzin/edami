#ifndef _H_SET_OF_POINTS_H
#define _H_SET_OF_POINTS_H

#include "commons.h"
#include "SetOfPoints.h"

template<class T>
class HSetOfPoints : public SetOfPoints<T>
{
public:
	HSetOfPoints(vector<T>& dataSet);
	vector<int> regionQuery(int& point, double eps, double(*measure)(T&, T&));
private:
	vector<vector<int>> flags;
};

template<class T>
HSetOfPoints<T>::HSetOfPoints(vector<T>& dataSet) : SetOfPoints<T>(dataSet)
{
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
vector<int> HSetOfPoints<T>::regionQuery(int& pointId, double eps, double(*measure)(T&, T&))
{
	T& point = this->dataSet[pointId];
	vector<int> neighbours;
	for (int i = 0; i < this->dataSet.size();i++) {
		int left;
		int right;
		if (pointId <= i)
		{
			left = pointId;
			right = i - pointId;
		}
		else
		{
			left = i;
			right = pointId - i;
		}

		if (flags[left][right] == NOT_DECIDED)
		{
			if (measure(point, this->dataSet[i]) <= eps)
			{
				flags[left][right] = NEIGHBOUR;
				neighbours.push_back(i);
			}
			else
			{
				flags[left][right] = NOT_NEIGHBOUR;
			}
		}
		else if (flags[left][right] == NEIGHBOUR)
		{
			neighbours.push_back(i);
		}
	}
	return neighbours;
}

#endif
