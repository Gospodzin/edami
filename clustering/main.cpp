#include <iostream>
#include <fstream>
#include "src/utils.h"
#include "src/Clustering.h"
#include "src/loader.h"

using namespace std;


void main()
{
	string filePath;
	int dbScanTypeId;
	int measureTypeId;
	int minPt;
	double eps;
	cout << "Enter file path: ";
	cin >> filePath;
	cout << "0. Basic\n1. Half\n2. TI\n3. Lengths" << endl;
	cout << "Choose dbScanType: ";
	cin >> dbScanTypeId;
	cout << "0. Euclidean Distance\n1. Cosine Similarity\n2. Tanimoto Similarity" << endl;
	cout << "Choose measureType: ";
	cin >> measureTypeId;
	cout << "Enter minPt: " << endl;
	cin >> minPt;
	cout << "Enter eps: " << endl;
	cin >> eps;

	cout << "Loading data..." << endl;
	vector<DensePoint> data = loader::loadDataDense(filePath);

	cout << "Computing..." << endl;
	Clustering<DensePoint>::dbscan(data, eps, minPt, (DbScanType)dbScanTypeId, (MeasureType)measureTypeId);

	cout << "Writing out results..." << endl;
	ofstream myfile;
	myfile.open("result.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++)
	{
		myfile << to_string(data[i].ClId) + "\n";
	}
	myfile.close();
	cout << "Completed" << endl;
	system("pause");
}
