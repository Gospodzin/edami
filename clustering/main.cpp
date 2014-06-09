#include <iostream>
#include "utils.h"
#include "Clustering.h"
#include "SetOfPoints.h"

using namespace std;

void main ()
{
	string fileName = "sports.mat";
	vector<Point> dataSet = utils::loadData(fileName);
	SetOfPoints setOfPoints(dataSet);
	Clustering dbscan;
	dbscan.dbscan(setOfPoints, 1.1, 3);
}
