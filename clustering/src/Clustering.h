#ifndef _CLUSTERING_H
#define _CLUSTERING_H

#include "Point.h"
#include "DensePoint.h"
#include "SparsePoint.h"
#include "Measures.h"
#include "SetOfPoints.h"
#include "BaseSetOfPoints.h"
#include "TISetOfPoints.h"
#include "HSetOfPoints.h"

template<class T>
class Clustering
{
public:
	static void dbscan(SetOfPoints<T>& setOfPoints, double eps, int minPts, double(*measure)(T&, T&));
private:
	static inline int nextId(int currentId);
	static bool expandCluster(SetOfPoints<T>& setOfPoints, T& point, int clId, double eps, int minPts, double(*measure)(T&, T&));
};

template<class T>
void Clustering<T>::dbscan(SetOfPoints<T>& setOfPoints, double eps, int minPts, double(*measure)(T&, T&))
{
	int clusterId = nextId(NOISE);
	for (int i = 0; i < setOfPoints.size(); i++)
	{
		T& point = setOfPoints[i];
		if (point.ClId == UNCLASSIFIED && expandCluster(setOfPoints, point, clusterId, eps, minPts, measure))
		{
			clusterId = nextId(clusterId);
		}
	}
}

template<class T>
int Clustering<T>::nextId(int currentId)
{
	return currentId + 1;
}

template<class T>
bool Clustering<T>::expandCluster(SetOfPoints<T>& setOfPoints, T& point, int clId, double eps, int minPts, double(*measure)(T&, T&))
{
	vector<T*> seeds = setOfPoints.regionQuery(point, eps, measure);
	if ((int)seeds.size() < minPts) // no core point
	{
		point.ClId = NOISE;
		return false;
	}
	else // all points in seeds are density-reachable from Point
	{
		utils::changeClIds(seeds, clId);
		utils::deleteSeed(seeds, &point);
		while (!seeds.empty())
		{
			T* currentP = seeds.front();
			vector<T*> result = setOfPoints.regionQuery(*currentP, eps, measure);
			if ((int)result.size() >= minPts)
			for (unsigned i = 0; i < result.size(); i++)
			{
				T* resultP = result[i];
				if (resultP->ClId == UNCLASSIFIED || resultP->ClId == NOISE)
				{
					if (resultP->ClId == UNCLASSIFIED)
						seeds.push_back(resultP);
					resultP->ClId = clId;
				}
			}
			utils::deleteSeed(seeds, currentP);
		}
		return true;
	}
}

#endif 
