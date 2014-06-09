#include "SetOfPoints.h"

int SetOfPoints::size()
{
	return dataSet.size();
}

Point& SetOfPoints::operator[](int n)
{
	return dataSet[n];
}

void SetOfPoints::normalize()
{
	for (vector<Point>::iterator it = dataSet.begin(); it != dataSet.end(); ++it) {
		double length = sqrt(inner_product(it->coordinates.begin(), it->coordinates.end(), it->coordinates.begin(), double(0)));
		transform(it->coordinates.begin(), it->coordinates.end(), it->coordinates.begin(), [length](double val) -> double {return val / length; });
	}
}