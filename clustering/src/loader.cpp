#include "loader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>

vector<SparsePoint> loader::loadDataSparse(string filePath){
	ifstream infile(filePath);
		vector<SparsePoint> points;

		while (infile) {
			string s;
			if (!getline(infile, s))
				break;

			istringstream ss(s);
			SparsePoint point;
			vector<int> coords;

			while (ss) {
				string s;
				if (!getline(ss, s, ' '))
					break;
				coords.push_back(double(atoi(s.c_str())));
			}

			for (int i = 0; i < coords.size(); i = i + 2) {
				SparsePair pair;
				pair.Id = coords[i];
				pair.Value = double(coords[i+1]);
				point.Coordinates.push_back(pair);
			}

			points.push_back(point);
		}

		return points;
}

vector<DensePoint> loader::loadDataDense(string filePath) {
	ifstream infile(filePath);
	vector<DensePoint> points;

	while (infile) {
		string s;
		if (!getline(infile, s))
			break;

		istringstream ss(s);
		vector<double> coords;

		while (ss) {
			string s;
			if (!getline(ss, s, ' '))
				break;
			coords.push_back(double(atoi(s.c_str())));
		}

		points.push_back(DensePoint(coords));
	}

	return points;
}

vector<DensePoint> loader::loadDataMarcin()
{
	//TODO mocked
	vector<DensePoint> data;
	// task 3. from the 14L MockTestII :D
	data.push_back(DensePoint(vector<double> { 1, 5}));
	data.push_back(DensePoint(vector<double> { 2, 5}));
	data.push_back(DensePoint(vector<double> { 2, 6}));
	data.push_back(DensePoint(vector<double> { 3, 2}));
	data.push_back(DensePoint(vector<double> { 3, 4}));
	data.push_back(DensePoint(vector<double> { 3, 5}));
	data.push_back(DensePoint(vector<double> { 4, 2}));
	data.push_back(DensePoint(vector<double> { 4, 3}));
	data.push_back(DensePoint(vector<double> { 4, 5}));
	data.push_back(DensePoint(vector<double> { 8, 1}));
	data.push_back(DensePoint(vector<double> { 8, 2}));
	data.push_back(DensePoint(vector<double> { 9, 2}));
	data.push_back(DensePoint(vector<double> { 10, 3}));
	data.push_back(DensePoint(vector<double> { 10, 5}));
	data.push_back(DensePoint(vector<double> { 11, 4}));
	return data;
}

vector<DensePoint> loader::loadDataMichal()
{
	//TODO mocked
	vector<DensePoint> data;
	// task 3. from the 14L MockTestII :D
	data.push_back(DensePoint(vector<double> { 1, 2}));
	data.push_back(DensePoint(vector<double> { 2, 1}));
	data.push_back(DensePoint(vector<double> { 2, 2}));
	data.push_back(DensePoint(vector<double> { 3, 2}));
	data.push_back(DensePoint(vector<double> { 3, 3}));
	data.push_back(DensePoint(vector<double> { 3, 5}));
	data.push_back(DensePoint(vector<double> { 4, 2}));
	data.push_back(DensePoint(vector<double> { 4, 4}));
	data.push_back(DensePoint(vector<double> { 4, 5}));
	data.push_back(DensePoint(vector<double> { 8, 5}));
	data.push_back(DensePoint(vector<double> { 8, 6}));
	data.push_back(DensePoint(vector<double> { 9, 5}));
	data.push_back(DensePoint(vector<double> { 10, 4}));
	data.push_back(DensePoint(vector<double> { 10, 2}));
	data.push_back(DensePoint(vector<double> { 11, 3}));
	return data;
}
