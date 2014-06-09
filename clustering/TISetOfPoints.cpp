#include "TISetOfPoints.h"
#include <algorithm>

TISetOfPoints::TISetOfPoints(vector<Point> dataSet)
{
	this->dataSet = dataSet;
}

TISetOfPoints::~TISetOfPoints()
{
}

vector<Point*> TISetOfPoints::regionQuery(Point point, double eps, double(*measure)(Point, Point))
{
	vector<Point*> neighbours;
	//TODO find
	return neighbours;
}

void TISetOfPoints::sortByReferencePoint(Point refP, double(*measure)(Point, Point))
{
	std::sort(dataSet.begin(), dataSet.end(), [refP, measure](Point a, Point b) {
		return measure(a, refP) <  measure(b, refP);
	});
}