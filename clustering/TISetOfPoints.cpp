#include "TISetOfPoints.h"
#include <algorithm>

TISetOfPoints::TISetOfPoints(vector<Point> dataSet, Point refP, double(*measure)(Point, Point))
{
	this->dataSet = dataSet;
	calculateRefDists(refP, measure);
	sortByRefDist();
	setIds();

}

TISetOfPoints::~TISetOfPoints()
{
}

vector<Point*> TISetOfPoints::regionQuery(Point& point, double eps, double(*measure)(Point, Point))
{
	vector<Point*> neighbours;
	//search upwards
	for (int i = point.id; i >= 0 && abs(point.RefDist - dataSet[i].RefDist) <= eps; i--)
	{
		if (measure(point, dataSet[i]) <= eps)
			neighbours.push_back(&dataSet[i]);
	}
	//search downwards
	for (int i = point.id + 1; i < dataSet.size() && abs(point.RefDist - dataSet[i].RefDist) <= eps; i++)
	{
		if (measure(point, dataSet[i]) <= eps)
			neighbours.push_back(&dataSet[i]);
	}

	return neighbours;
}

void TISetOfPoints::sortByRefDist()
{
	std::sort(dataSet.begin(), dataSet.end(), [](Point a, Point b) {
		return a.RefDist <  b.RefDist;
	});
}

void TISetOfPoints::calculateRefDists(Point refP, double(*measure)(Point, Point))
{
	for (vector<Point>::iterator it = dataSet.begin(); it != dataSet.end(); ++it)
		it->RefDist = measure(*it, refP);
}

void TISetOfPoints::setIds()
{
	for (int i = 0; i < dataSet.size(); i++)
		dataSet[i].id = i;
}