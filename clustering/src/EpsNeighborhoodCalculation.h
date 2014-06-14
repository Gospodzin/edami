#ifndef EPSNEIGHBORHOODCALCULATION_H_
#define EPSNEIGHBORHOODCALCULATION_H_

#include "EpsNeighborhood.h"

template<class T>
EpsNeighborhood<T> bruteForceEpsNeighborhoodCalc(double eps, T * thePoint, vector<T> & otherPoints, double (*distanceMeasure)(T&,T&)){
	vector<T*> pointsInNeighborhood;
	for(typename vector<T>::iterator it = otherPoints.begin(); it != otherPoints.end(); ++it) {
	    if(distanceMeasure(*thePoint, *it) <= eps)
	    	pointsInNeighborhood.push_back(&(*it));
	}
	return EpsNeighborhood<T>(thePoint, pointsInNeighborhood);
}

#endif /* EPSNEIGHBORHOODDETERMINATION_H_ */
