#include "Helpers.h"

void printVector(vector<double> vec) {
	cout << "(";
	for (int i = 0; i < vec.size(); ++i) {
		cout << vec.at(i);
		if(i < vec.size())
			cout << ",";
	}
	cout << ")";
	cout << endl;
}
