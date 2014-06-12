#ifndef _CLUSTERING_H
#define _CLUSTERING_H

#include "Point.h"
#include "Measures.h"
#include "SetOfPoints.h"
#include "BaseSetOfPoints.h"
#include "TISetOfPoints.h"
#include "HSetOfPoints.h"

class Clustering
{
public:
	static void dbscan(SetOfPoints& setOfPoints, double eps, int minPts, double(*measure)(Point, Point));
private:
	static inline int nextId(int currentId);
	static bool expandCluster(SetOfPoints& setOfPoints, Point& point, int clId, double eps, int minPts, double(*measure)(Point, Point));
};

#endif 
