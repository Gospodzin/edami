#ifndef PREDECON_H_
#define PREDECON_H_

#include "Point.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"

bool vecContains(vector<Point> v, Point p);

bool isCorePoint(EpsNeighborhood epsNeighborhood, WeightedNeighborhood weightedNeighborhood, double lambda, double mu);

bool isDirectlyReachable(EpsNeighborhood p1EpsNeighborhood, WeightedNeighborhood p1WeightedNeighborhood,
	EpsNeighborhood p2EpsNeighborhood, Point p2, double lambda, double mu);

void runPredecon(vector<Point> & D, double eps, double mu, double lambda, double delta, double kappa);

#endif /* PREDECON_H_ */
