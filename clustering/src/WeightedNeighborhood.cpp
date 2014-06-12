#include "WeightedNeighborhood.h"

WeightedNeighborhood::WeightedNeighborhood(double epsilon, EpsNeighborhood theNeighborhood, vector<EpsNeighborhood> otherNeighborhoods, double delta, double kappa){
	thePoint = theNeighborhood.getThePoint();
//	cout << "weighted nr" << endl;
//	theNeighborhood.getThePoint().print();
//	for (int i = 0; i < otherNeighborhoods.size(); ++i) {
//		otherNeighborhoods[i].getThePoint().print();
//	}
//	for(vector<EpsNeighborhood>::iterator it = otherNeighborhoods.begin(); it != otherNeighborhoods.end(); ++it)
//	    it->computeSubspacePreferenceParameters(delta, kappa);
	for(vector<EpsNeighborhood>::iterator otherNeighborhood = otherNeighborhoods.begin();
									   otherNeighborhood != otherNeighborhoods.end();
									   ++otherNeighborhood){
//		theNeighborhood.getThePoint().print();
//		otherNeighborhood->getThePoint().print();
		auto dist1 = theNeighborhood.getPreferenceWeightedDistanceTo(otherNeighborhood->getThePoint());
		auto dist2 = otherNeighborhood->getPreferenceWeightedDistanceTo(theNeighborhood.getThePoint());
//		cout << "dist: " << dist1 << " " << dist2 << endl;
		auto maxDist = dist1 > dist2 ? dist1 : dist2;
//		cout << "maxDist " << maxDist << endl;
		if(maxDist <= epsilon)
		{
//			cout << "here" << endl;
			points.push_back(otherNeighborhood->getThePoint());
		}
	}
}
