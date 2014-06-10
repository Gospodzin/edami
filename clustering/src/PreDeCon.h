#ifndef PREDECON_H_
#define PREDECON_H_

#include "Point.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"

bool vecContains(vector<Point> v, Point p);

bool isCorePoint(EpsNeighborhood epsNeighborhood, WeightedNeighborhood weightedNeighborhood, int lambda, int mu);

bool isDirectlyReachable(EpsNeighborhood p1EpsNeighborhood, WeightedNeighborhood p1WeightedNeighborhood,
						 EpsNeighborhood p2EpsNeighborhood, Point p2, int lambda, int mu);


#endif /* PREDECON_H_ */
