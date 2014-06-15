#ifndef _UTILS_H
#define _UTILS_H

#include "commons.h"
#include "Point.h"
#include "DensePoint.h"
#include "SetOfPoints.h"

namespace utils
{
	template<class T> void changeClIds(vector<int> seeds, SetOfPoints<T>& setOfPoints, int clId);
	void deleteSeed(vector<int>& seeds, int& seed);
	void printVector(vector<double> vec);
}

template<class T>
void utils::changeClIds(vector<int> seeds, SetOfPoints<T>& setOfPoints, int clId)
{
	for (typename vector<int>::iterator it = seeds.begin(); it != seeds.end(); ++it)
		setOfPoints[*it].ClId = clId;
}
#endif 
