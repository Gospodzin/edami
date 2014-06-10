#ifndef _UTILS_H
#define _UTILS_H

#include "commons.h"
#include "Point.h"

namespace utils
{
	vector<Point> loadData(string fileName);
	void changeClIds(vector<Point*> seeds, int clId);
	void deleteSeed(vector<Point*>& seeds, Point* seed);
	void printVector(vector<double> vec);
}

#endif 
