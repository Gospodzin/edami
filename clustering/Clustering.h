#ifndef _CLUSTERING_H
#define _CLUSTERING_H

#include "Point.h"
#include "SetOfPoints.h"

class Clustering
{
public:
	static void dbscan(SetOfPoints& setOfPoints, double eps, int minPts);
private:
	static inline int nextId(int currentId);
	static bool expandCluster(SetOfPoints& setOfPoints, Point& point, int clId, double eps, int minPts);
};

#endif 
