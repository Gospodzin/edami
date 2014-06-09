#include "utils.h"

vector<Point> utils::loadData(std::string fileName)
{
	//TODO mocked
	vector<Point> data;
	// task 3. from the 14L MockTestII :D
	data.push_back(Point(vector<double> { 1, 5}));
	data.push_back(Point(vector<double> { 2, 5}));
	data.push_back(Point(vector<double> { 2, 6}));
	data.push_back(Point(vector<double> { 3, 2}));
	data.push_back(Point(vector<double> { 3, 4}));
	data.push_back(Point(vector<double> { 3, 5}));
	data.push_back(Point(vector<double> { 4, 2}));
	data.push_back(Point(vector<double> { 4, 3}));
	data.push_back(Point(vector<double> { 4, 5}));
	data.push_back(Point(vector<double> { 8, 1}));
	data.push_back(Point(vector<double> { 8, 2}));
	data.push_back(Point(vector<double> { 9, 2}));
	data.push_back(Point(vector<double> { 10, 3}));
	data.push_back(Point(vector<double> { 10, 5}));
	data.push_back(Point(vector<double> { 11, 4}));
	return data;
}

void utils::changeClIds(vector<Point*> seeds, int clId)
{
	for (vector<Point*>::iterator it = seeds.begin(); it != seeds.end(); ++it)
		(*it)->ClId = clId;
}

void utils::deleteSeed(vector<Point*>& seeds, Point* seed)
{
	seeds.erase(std::find(seeds.begin(), seeds.end(), seed));
}

void utils::printVector(vector<double> vec) {
	cout << "(";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec.at(i);
		if (i < vec.size())
			cout << ",";
	}
	cout << ")";
	cout << endl;
}
