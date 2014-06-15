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
	Lengths,
};

enum MeasureType
{
	EuclideanDist,
	CosSim,
	TanimotoSim,
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
	//Choose DbScan
	SetOfPoints<T>* setOfPointsP = NULL;
	double(*measure)(T&, T&) = NULL;
	switch (dbScanType)
	{
	case DbScanType::Basic:
		setOfPointsP = new BaseSetOfPoints<T>(dataSet);
		switch (measureType)
		{
		case MeasureType::EuclideanDist:
			measure = measures::euclideanDistance;
			break;
		case MeasureType::CosSim:
			measure = measures::minusNormCosSim;
			eps = -eps;
			setOfPointsP->normalize();
			break;
		case MeasureType::TanimotoSim:
			measure = measures::euclideanDistance;
			eps = -eps;
			setOfPointsP->normalize();
			break;
		}
		break;
	case DbScanType::Half:
		setOfPointsP = new HSetOfPoints<T>(dataSet);
		switch (measureType)
		{
		case MeasureType::EuclideanDist:
			measure = measures::euclideanDistance;
			break;
		case MeasureType::CosSim:
			measure = measures::minusNormCosSim;
			eps = -eps;
			setOfPointsP->normalize();
			break;
		case MeasureType::TanimotoSim:
			measure = measures::euclideanDistance;
			eps = -eps;
			setOfPointsP->normalize();
			break;
		}
		break;
	case DbScanType::TI:
		setOfPointsP = new TISetOfPoints<T>(dataSet);
		switch (measureType)
		{
		case MeasureType::EuclideanDist:
			measure = measures::euclideanDistance;
			break;
		case MeasureType::CosSim:
			measure = measures::euclideanDistance;
			eps = sqrt(2 - 2 * eps);
			break;
		case MeasureType::TanimotoSim:
			throw "Error";
			break;
		}
		((TISetOfPoints<T>*)setOfPointsP)->prepare(measure);
		break;
	case DbScanType::Lengths:
		switch (measureType)
		{
		case MeasureType::EuclideanDist:
			throw "Error";
			break;
		case MeasureType::CosSim:
			measure = measures::cosSim;
			setOfPointsP = new LSetOfPoints<T>(dataSet);
			break;
		case MeasureType::TanimotoSim:
			measure = measures::tanimotoSim;
			setOfPointsP = new TLSetOfPoints<T>(dataSet);
			break;
		}
		break;
	}
	SetOfPoints<T>& setOfPoints = *setOfPointsP;

	//Run DbScan
	clock_t start = clock();
	int clusterId = nextId(NOISE);
	for (int i = 0; i < setOfPoints.size(); i++)
	{
		clock_t ends = clock();
		if ((double)(ends - start) / CLOCKS_PER_SEC > 3)
		{
			start = ends;
			printf("Points processed progress: %d\n", i);
		}
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
