#include "WeightedNeighborhood.h"

WeightedNeighborhood::WeightedNeighborhood(double epsilon, EpsNeighborhood & theNeighborhood, vector<EpsNeighborhood> & otherNeighborhoods, double delta, double kappa){
	thePoint = theNeighborhood.getThePoint();
	for(vector<EpsNeighborhood>::iterator otherNeighborhood = otherNeighborhoods.begin();
									   otherNeighborhood != otherNeighborhoods.end();
									   ++otherNeighborhood){
		auto dist1 = theNeighborhood.getPreferenceWeightedDistanceTo(otherNeighborhood->getThePoint());
		auto dist2 = otherNeighborhood->getPreferenceWeightedDistanceTo(theNeighborhood.getThePoint());
		auto maxDist = dist1 > dist2 ? dist1 : dist2;
		if(maxDist <= epsilon)
		{
			points.push_back(otherNeighborhood->getThePoint());
		}
	}
}
