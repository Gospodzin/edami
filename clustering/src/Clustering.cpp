#include "Clustering.h"
#include "utils.h"

void Clustering::dbscan(SetOfPoints& setOfPoints, double eps, int minPts, double(*measure)(Point, Point))
{
	int clusterId = nextId(NOISE);
	for (int i = 0; i < setOfPoints.size(); i++)
	{
		Point& point = setOfPoints[i];
		if (point.ClId == UNCLASSIFIED && expandCluster(setOfPoints, point, clusterId, eps, minPts, measure))
		{
			clusterId = nextId(clusterId);
		}
	}
}

int Clustering::nextId(int currentId)
{
	return currentId + 1;
}

bool Clustering::expandCluster(SetOfPoints& setOfPoints, Point& point, int clId, double eps, int minPts, double(*measure)(Point, Point))
{
	vector<Point*> seeds = setOfPoints.regionQuery(point, eps, measure);
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
			Point* currentP = seeds.front();
			vector<Point*> result = setOfPoints.regionQuery(*currentP, eps, measure);
			if ((int)result.size() >= minPts)
			for (unsigned i = 0; i < result.size(); i++)
				{
					Point* resultP = result[i];
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
