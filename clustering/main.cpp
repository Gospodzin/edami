#include <iostream>
#include "src/utils.h"
#include "src/Clustering.h"

using namespace std;

void main()
{
	vector<Point> data = utils::loadData("sports.mat");
	TISetOfPoints setOfPoints(data, data[6], measures::euclideanDistance);
	Clustering::dbscan(setOfPoints, 1.1, 3, measures::euclideanDistance);
	system("pause");
}
