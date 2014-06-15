#include "utils.h"

void utils::printVector(vector<double> vec) {
	cout << "(";
	for (unsigned i = 0; i < vec.size(); ++i) {
		cout << vec.at(i);
		if (i < vec.size())
			cout << ",";
	}
	cout << ")";
	cout << endl;
}

void utils::deleteSeed(vector<int>& seeds, int& seed)
{
	seeds.erase(std::find(seeds.begin(), seeds.end(), seed));
}
