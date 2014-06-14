#ifndef WEIGHTEDNEIGHBORHOOD_H_
#define WEIGHTEDNEIGHBORHOOD_H_

#include "Neighborhood.h"
#include "EpsNeighborhood.h"

template<class T>
class WeightedNeighborhood : public Neighborhood<T>
{
public:
	WeightedNeighborhood(){}
	WeightedNeighborhood(double epsilon, EpsNeighborhood<T> theNeighborhood, vector<EpsNeighborhood<T>> otherNeighborhoods, double delta, double kappa);
};

template<class T>
WeightedNeighborhood<T>::WeightedNeighborhood(double epsilon, EpsNeighborhood<T> theNeighborhood, vector<EpsNeighborhood<T>> otherNeighborhoods, double delta, double kappa){
	this->thePoint = theNeighborhood.getThePoint();
	for(typename vector<EpsNeighborhood<T>>::iterator otherNeighborhood = otherNeighborhoods.begin();
									   otherNeighborhood != otherNeighborhoods.end();
									   ++otherNeighborhood){
		auto dist1 = theNeighborhood.getPreferenceWeightedDistanceTo(otherNeighborhood->getThePoint());
		auto dist2 = otherNeighborhood->getPreferenceWeightedDistanceTo(theNeighborhood.getThePoint());
		auto maxDist = dist1 > dist2 ? dist1 : dist2;
		if(maxDist <= epsilon)
			this->points.push_back(otherNeighborhood->getThePoint());
	}
}

#endif /* WEIGHTEDNEIGHBORHOOD_H_ */
