#include <iostream>
#include "utils.h"
#include "Clustering.h"

using namespace std;

void main ()
{
	vector<Point> data = utils::loadData("sports.mat");
	BaseSetOfPoints setOfPoints(data);
	setOfPoints.normalize();
	Clustering::dbscan(setOfPoints, -0.99, 3, measures::minusNormCosSim);
	system("pause");
}
