#include "BaseSetOfPoints.h"
#include "Measures.h"
BaseSetOfPoints::BaseSetOfPoints(vector<Point> dataSet)
{
	this->dataSet = dataSet;
}


BaseSetOfPoints::~BaseSetOfPoints()
{
}

vector<Point*> BaseSetOfPoints::regionQuery(Point& point, double eps, double(*measure)(Point, Point))
{
	vector<Point*> neighbours;
	for (vector<Point>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
		if (measure(point, *it) <= eps)
			neighbours.push_back(&*it);
	}
	return neighbours;
}
