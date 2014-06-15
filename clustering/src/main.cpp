#include <iostream>
#include <fstream>
#include <ctime>
#include "utils.h"
#include "Clustering.h"
#include "loader.h"

using namespace std;


int main()
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
	clock_t sstart = clock();
	vector<DensePoint> data = loader::loadDataDense(filePath);
	clock_t sends = clock();
	cout << "Data loading time: " << (double)(sends - sstart) / CLOCKS_PER_SEC << endl;

	cout << "Computing..." << endl;
	clock_t start = clock();
	Clustering<DensePoint>::dbscan(data, eps, minPt, (DbScanType)dbScanTypeId, (MeasureType)measureTypeId);
	clock_t ends = clock();
	cout << "Computing Time: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	cout << "Writing out results..." << endl;
	ofstream resultFile;
	resultFile.open("result.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++)
	{
		resultFile << to_string(data[i].ClId) + "\n";
	}
	resultFile.close();
	ofstream runtime;
	resultFile.open("runtime.txt", ios::trunc);
	for (int i = 0; i < data.size(); i++)
	{
		runtime << to_string((double)(ends - start) / CLOCKS_PER_SEC);
	}
	runtime.close();
	cout << "Completed" << endl;
	system("pause");
}
