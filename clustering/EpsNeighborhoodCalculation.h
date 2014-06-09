#ifndef EPSNEIGHBORHOODCALCULATION_H_
#define EPSNEIGHBORHOODCALCULATION_H_

#include "EpsNeighborhood.h"

EpsNeighborhood bruteForceEpsNeighborhoodCalc(double eps, Point thePoint, vector<Point> otherPoints, double (*distanceMeasure)(Point,Point));

#endif /* EPSNEIGHBORHOODDETERMINATION_H_ */
