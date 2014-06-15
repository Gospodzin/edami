#include <iostream>
#include <fstream>
#include <ctime>
#include "utils.h"
#include "Clustering.h"
#include "PreDeCon.h"
#include "loader.h"

using namespace std;


void statistics(vector<DensePoint>& data)
{
	vector<int> stat;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i].ClId + 1 > stat.capacity())
			stat.resize(data[i].ClId + 1);
		++stat[data[i].ClId];
	}

	ofstream resultFile;
	resultFile.open("stats.txt", ios::trunc);
	resultFile << "NoOfClusters:" << stat.size() - 1 << endl;
	resultFile << "Noise:" << stat[0] << endl;
	for (int i = 1; i < stat.size(); i++)
	{
		resultFile << i << ":" << stat[i] <<endl;
	}
	resultFile.close();
	
}

int main()
{
	string filePath;
	int dbScanTypeId;
	int measureTypeId;
	int minPt;

	double eps;
	double delta;
	double lambda;
	double kappa;

	int algorithmChoice;

	cout << "Choose algorithm:" << endl;
	cout << "0. Dbscan\n1. PreDeCon" << endl;
	cin >> algorithmChoice;

	if(algorithmChoice == 0){
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
		runtime << to_string((double)(ends - start) / CLOCKS_PER_SEC);
		runtime.close();
		statistics(data);
		cout << "Completed" << endl;
		system("pause");
	}
	else {
		cout << "Enter file path: ";
		cin >> filePath;
		cout << "Enter minPt (μ parameter): " << endl;
		cin >> minPt;
		cout << "Enter eps: " << endl;
		cin >> eps;
		cout << "Enter lambda (λ): " << endl;
		cin >> lambda;
		cout << "Enter delta (δ): " << endl;
		cin >> delta;
		cout << "Enter kappa (κ): " << endl;
		cin >> kappa;

		cout << "Loading data..." << endl;
		clock_t sstart = clock();
		vector<DensePoint> data = loader::loadDataDense(filePath);
		clock_t sends = clock();
		cout << "Data loading time: " << (double)(sends - sstart) / CLOCKS_PER_SEC << endl;

		cout << "Computing..." << endl;

		vector<double> times;

		clock_t start = clock();
		runPredecon(data, eps, minPt, lambda, delta, kappa, times);
		clock_t ends = clock();
		cout << "Computing Time: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
		cout << "Writing out results..." << endl;
		ofstream resultFile;
		resultFile.open("result-predecon.txt", ios::trunc);
		for (int i = 0; i < data.size(); i++)
		{
			resultFile << to_string(data[i].ClId) + "\n";
		}
		resultFile.close();
		ofstream runtime;
		resultFile.open("runtime-predecon.txt", ios::trunc);
		runtime << to_string((double)(ends - start) / CLOCKS_PER_SEC);
		for (int i = 0; i < times.size(); i++)
		{
			runtime << times[i];
		}
		runtime.close();
		statistics(data);
		cout << "Completed" << endl;
		system("pause");
	}
}

