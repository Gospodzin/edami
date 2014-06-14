#include <iostream>
#include "src/utils.h"
#include "src/Clustering.h"

using namespace std;


void main()
{
	vector<DensePoint> data = utils::loadData("sports.mat");
	TISetOfPoints<DensePoint> setOfPoints(data, data[6], measures::euclideanDistance);
	Clustering<DensePoint>::dbscan(setOfPoints, 1.1, 3, measures::euclideanDistance);

	for (int i = 0; i < setOfPoints.size(); i++)
	{
		cout << setOfPoints[i].ClId<<endl;
	}
	system("pause");
}
