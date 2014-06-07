#include "PreDeCon.h"

#include <algorithm>

bool vecContains(vector<Point> v, Point p){
	return (find(v.begin(), v.end(), p) != v.end());
}

bool isCorePoint(EpsNeighborhood epsNeighborhood, WeightedNeighborhood weightedNeighborhood, int lambda, int mu){
	return epsNeighborhood.getPreferenceDimensionality() <= lambda &&
			weightedNeighborhood.getCount() >= mu;
}

bool isDirectlyReachable(EpsNeighborhood p1EpsNeighborhood, WeightedNeighborhood p1WeightedNeighborhood,
						 EpsNeighborhood p2EpsNeighborhood, Point p2, int lambda, int mu){
	return isCorePoint(p1EpsNeighborhood, p1WeightedNeighborhood, lambda, mu) &&
			p2EpsNeighborhood.getPreferenceDimensionality() <= lambda &&
			vecContains(p1WeightedNeighborhood.getNeighbors(), p2);
}
