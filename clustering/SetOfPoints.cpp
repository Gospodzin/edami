#include "SetOfPoints.h"

int SetOfPoints::size()
{
	return dataSet.size();
}

Point& SetOfPoints::operator[](int n)
{
	return dataSet[n];
}