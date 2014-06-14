#ifndef _UTILS_H
#define _UTILS_H

#include "commons.h"
#include "Point.h"
#include "DensePoint.h"

namespace utils
{
	vector<DensePoint> loadData(string fileName);
	vector<DensePoint> loadDataMichal(string fileName);
	template<class T> void changeClIds(vector<T*> seeds, int clId);
	template<class T> void deleteSeed(vector<T*>& seeds, T* seed);
	void printVector(vector<double> vec);
}

template<class T>
void utils::deleteSeed(vector<T*>& seeds, T* seed)
{
	seeds.erase(std::find(seeds.begin(), seeds.end(), seed));
}

template<class T>
void utils::changeClIds(vector<T*> seeds, int clId)
{
	for (vector<T*>::iterator it = seeds.begin(); it != seeds.end(); ++it)
		(*it)->ClId = clId;
}
#endif 
