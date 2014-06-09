#include <iostream>
#include "utils.h"
#include "Clustering.h"
#include "BaseSetOfPoints.h"
#include "TISetOfPoints.h"
#include "Measures.h"

using namespace std;

void main ()
{
	vector<Point> data = utils::loadData("sports.mat");
	TISetOfPoints tISetOfPoints(data);
	tISetOfPoints.sortByReferencePoint(tISetOfPoints[6], euclideanDistance);
	Clustering::dbscan(tISetOfPoints, 1.1, 3, euclideanDistance);
}
