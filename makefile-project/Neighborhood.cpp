#include "Neighborhood.h"

int Neighborhood::getCount()
{
	return (points.size()) + 1;
}

double Neighborhood::getVarianceAlongAttr(int n, double (*distanceMeasure)(Point,Point))
{
	double sum = 0.0;
	for(vector<Point>::iterator oneOfPoints = points.begin(); oneOfPoints != points.end(); ++oneOfPoints)
	{
		double dist = distanceMeasure(thePoint,*oneOfPoints);
		sum += dist*dist;
	}
	return sum / getCount();
}
