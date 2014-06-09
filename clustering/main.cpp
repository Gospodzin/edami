#include <iostream>
#include "utils.h"
#include "Clustering.h"

using namespace std;

void main ()
{
	vector<Point> data = utils::loadData("sports.mat");
	HSetOfPoints setOfPoints(data);
	setOfPoints.setIds();
	Clustering::dbscan(setOfPoints, 1.1, 3, measures::euclideanDistance);
	system("pause");
}
