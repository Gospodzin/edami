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
#include "LSetOfPoints.h"
#include "TLSetOfPoints.h"

enum DbScanType
{
	Basic,
	Half,
	TI,
	CosLengths,
	TanimotoLengths,
};

enum MeasureType
{
	EuclideanDist,
	CosSim,
	NormCosSim,
	TanimotoSim,
	NormTanimotoSim
};

template<class T>
class Clustering
{
public:
	static void dbscan(vector<T>& dataSet, double eps, int minPts, DbScanType dbScanType, MeasureType measureType);
private:
	static inline int nextId(int currentId);
	static bool expandCluster(SetOfPoints<T>& setOfPoints, int pointId, int clId, double eps, int minPts, double(*measure)(T&, T&));
};

template<class T>
void Clustering<T>::dbscan(vector<T>& dataSet, double eps, int minPts, DbScanType dbScanType, MeasureType measureType)
{
	SetOfPoints<T>* setOfPointsP = NULL;
	switch (dbScanType)
	{
	case DbScanType::Basic:
		setOfPointsP = new BaseSetOfPoints<T>(dataSet);
		break;
	case DbScanType::Half:
		setOfPointsP = new HSetOfPoints<T>(dataSet);
		break;
	case DbScanType::TI:
		setOfPointsP = new TISetOfPoints<T>(dataSet);
		break;
	case DbScanType::CosLengths:
		setOfPointsP = new LSetOfPoints<T>(dataSet);
		break;
	case DbScanType::TanimotoLengths:
		setOfPointsP = new TLSetOfPoints<T>(dataSet);
		break;
	}
	SetOfPoints<T>& setOfPoints = *setOfPointsP;

	double(*measure)(T&, T&) = NULL;
	switch (measureType)
	{
	case MeasureType::EuclideanDist:
		measure = measures::euclideanDistance;
		break;
	case MeasureType::CosSim:
		if (dbScanType == DbScanType::TI)
		{
			measure = measures::euclideanDistance;
			eps = sqrt(2 - 2 * eps);
		}
		else if (dbScanType == DbScanType::CosLengths)
		{
		}
		else
		{
			measure = measures::minusNormCosSim;
			eps = -eps;
		}
		setOfPoints.normalize();
		break;
	case MeasureType::TanimotoSim:
		measure = measures::minusNormTanimotoSim;
		if (dbScanType == DbScanType::TanimotoLengths)
		{
		}
		else
		{
			eps = -eps;
			setOfPoints.normalize();
		}
		break;
	}

	if (dbScanType == DbScanType::TI)
	{
		((TISetOfPoints<T>&)setOfPoints).prepare(measure);
	}

	int clusterId = nextId(NOISE);
	for (int i = 0; i < setOfPoints.size(); i++)
	{
		T& point = setOfPoints[i];
		if (point.ClId == UNCLASSIFIED && expandCluster(setOfPoints, i, clusterId, eps, minPts, measure))
		{
			clusterId = nextId(clusterId);
		}
	}

	// write clusters ids to the origin data
	for (int i = 0; i < setOfPoints.size(); i++)
	{
		dataSet[i].ClId = setOfPoints[i].ClId;
	}
}

template<class T>
int Clustering<T>::nextId(int currentId)
{
	return currentId + 1;
}

template<class T>
bool Clustering<T>::expandCluster(SetOfPoints<T>& setOfPoints, int pointId, int clId, double eps, int minPts, double(*measure)(T&, T&))
{
	vector<int> seeds = setOfPoints.regionQuery(pointId, eps, measure);
	if ((int)seeds.size() < minPts) // no core point
	{
		setOfPoints[pointId].ClId = NOISE;
		return false;
	}
	else // all points in seeds are density-reachable from Point
	{
		utils::changeClIds(seeds, setOfPoints, clId);
		utils::deleteSeed(seeds, pointId);
		while (!seeds.empty())
		{
			int currentId = seeds.front();
			vector<int> result = setOfPoints.regionQuery(currentId, eps, measure);
			if ((int)result.size() >= minPts)
			for (unsigned i = 0; i < result.size(); i++)
			{
				int resultId = result[i];
				if (setOfPoints[resultId].ClId == UNCLASSIFIED || setOfPoints[resultId].ClId == NOISE)
				{
					if (setOfPoints[resultId].ClId == UNCLASSIFIED)
						seeds.push_back(resultId);
					setOfPoints[resultId].ClId = clId;
				}
			}
			utils::deleteSeed(seeds, currentId);
		}
		return true;
	}
}

#endif 
