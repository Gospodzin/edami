#include <iostream>
#include "src/utils.h"
#include "src/Clustering.h"

using namespace std;


void main()
{
	vector<DensePoint> data = utils::loadData("sports.mat");
	Clustering<DensePoint>::dbscan(data, 1.1, 3, DbScanType::TanimotoLengths, MeasureType::EuclideanDist);

	for (int i = 0; i < data.size(); i++)
	{
		data[i].print();
	}
	system("pause");
}
