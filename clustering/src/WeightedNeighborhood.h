#ifndef WEIGHTEDNEIGHBORHOOD_H_
#define WEIGHTEDNEIGHBORHOOD_H_

#include "Neighborhood.h"
#include "EpsNeighborhood.h"

class WeightedNeighborhood : public Neighborhood
{
public:
	WeightedNeighborhood(){}
	WeightedNeighborhood(double epsilon, EpsNeighborhood theNeighborhood, vector<EpsNeighborhood> otherNeighborhoods, double delta, double kappa);
};

#endif /* WEIGHTEDNEIGHBORHOOD_H_ */
