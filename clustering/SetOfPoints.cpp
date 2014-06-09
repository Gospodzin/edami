#include "SetOfPoints.h"
#include "Measures.h"

SetOfPoints::SetOfPoints(vector<Point> dataSet)
{
	this->dataSet = dataSet;
}


SetOfPoints::~SetOfPoints()
{
}

int SetOfPoints::size()
{
	return dataSet.size();
}

vector<Point*> SetOfPoints::regionQuery(Point point, double eps)
{
	vector<Point*> neighbours;
	for (vector<Point>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
		if (euclideanDistance(point, *it) <= eps)
			neighbours.push_back(&*it);
	}
	return neighbours;
}

Point& SetOfPoints::operator[](int n)
{
	return dataSet[n];
}