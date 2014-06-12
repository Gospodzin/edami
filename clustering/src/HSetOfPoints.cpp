#include "HSetOfPoints.h"


HSetOfPoints::HSetOfPoints(vector<Point> dataSet)
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


HSetOfPoints::~HSetOfPoints()
{
}

vector<Point*> HSetOfPoints::regionQuery(Point& point, double eps, double(*measure)(Point, Point))
{
	vector<Point*> neighbours;
	for (vector<Point>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
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

void HSetOfPoints::setIds()
{
	for (unsigned i = 0; i < dataSet.size(); i++)
		dataSet[i].Id = i;
}