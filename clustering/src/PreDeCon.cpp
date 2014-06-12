#include "PreDeCon.h"
#include "Measures.h"
#include "EpsNeighborhoodCalculation.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"
#include "commons.h"

#include <algorithm>

bool vecContains(vector<Point> v, Point p){
	return (find(v.begin(), v.end(), p) != v.end());
}

bool isCorePoint(EpsNeighborhood epsNeighborhood, WeightedNeighborhood weightedNeighborhood, double lambda, double mu){

	// TODO w punkcie flaga czy epsNeighborhood.getPreferenceDimensionality() <= lambda, flaga na core
	return epsNeighborhood.getPreferenceDimensionality() <= lambda &&
			weightedNeighborhood.getCount() >= mu;
}

bool isDirectlyReachable(EpsNeighborhood p1EpsNeighborhood, WeightedNeighborhood p1WeightedNeighborhood,
						 EpsNeighborhood p2EpsNeighborhood, Point p2, double lambda, double mu){
	return isCorePoint(p1EpsNeighborhood, p1WeightedNeighborhood, lambda, mu) &&
			p2EpsNeighborhood.getPreferenceDimensionality() <= lambda &&
			vecContains(p1WeightedNeighborhood.getNeighbors(), p2);
}

int getPointIndex(vector<Point> D, Point q){
	for (unsigned k = 0; k < D.size(); ++k) {
		if (D[k] == q) {
			return k;
			break;
		}
	}
	return -1;
}

EpsNeighborhood getNeighborhoodForPoint(vector<EpsNeighborhood> neighborhoods, Point & point){
	for (unsigned i = 0; i < neighborhoods.size(); ++i) {
		if(neighborhoods[i].getThePoint() == point){
			return neighborhoods[i];
		}
	}
	return EpsNeighborhood();
}

WeightedNeighborhood getNeighborhoodForPoint(vector<WeightedNeighborhood> neighborhoods, Point & point){
	for (unsigned i = 0; i < neighborhoods.size(); ++i) {
		if(neighborhoods[i].getThePoint() == point){
			return neighborhoods[i];
		}
	}
	return WeightedNeighborhood();
}

void runPredecon(vector<Point> & D, double eps, double mu, double lambda, double delta, double kappa){
	vector<EpsNeighborhood> epsNeighborhoods;
	vector<WeightedNeighborhood> weightedNeighborhoods;

	for (unsigned i = 0; i < D.size(); ++i)
		epsNeighborhoods.push_back(bruteForceEpsNeighborhoodCalc(eps, D[i], D, measures::euclideanDistance));

	for (unsigned i = 0; i < D.size(); ++i)
		epsNeighborhoods[i].computeSubspacePreferenceParameters(delta, kappa);

	// TODO trzymać w pamięci tylko ważone sąsiedztwa

	for (unsigned i = 0; i < D.size(); ++i) {
		vector<EpsNeighborhood> otherNeighborhoods;
		auto neighbors = epsNeighborhoods[i].getNeighbors();
		for (unsigned k = 0; k < neighbors.size(); ++k) {
			for (unsigned j = 0; j < epsNeighborhoods.size(); ++j) {
				if (epsNeighborhoods[j].getThePoint() == neighbors[k]) {
					otherNeighborhoods.push_back(epsNeighborhoods[j]);
					break;
				}
			}
		}
		weightedNeighborhoods.push_back(WeightedNeighborhood(eps, epsNeighborhoods[i], otherNeighborhoods, delta, kappa));
	}

	for (unsigned i = 0; i < D.size(); ++i) {
		cout << "eps " << i << endl;
		epsNeighborhoods[i].print();
		cout << "weighted" << endl;
		weightedNeighborhoods[i].print();
	}

	int clusterId = 0;
	for (unsigned i = 0; i < D.size(); ++i) {
		if(isCorePoint(epsNeighborhoods[i], weightedNeighborhoods[i], lambda, mu)){
			clusterId++;
			cout << "new " << i + 1 << endl;
			auto neighbors = weightedNeighborhoods[i].getNeighbors();
			vector<Point*> queue;
			for (unsigned j = 0; j < neighbors.size(); ++j) {
				queue.push_back(&neighbors[j]);
			}
			while(queue.size() != 0){
				Point * q = queue.back();
				queue.pop_back();
				vector<Point*> R;
				for (unsigned j = 0; j < D.size(); ++j) {
					Point * x = &D[j];
					auto qEpsNeighborhood = getNeighborhoodForPoint(epsNeighborhoods, *q);
					auto qWeightedNeighborhood = getNeighborhoodForPoint(weightedNeighborhoods, *q);
					auto xEpsNeighborhood = getNeighborhoodForPoint(epsNeighborhoods, *x);
					if(isDirectlyReachable(qEpsNeighborhood, qWeightedNeighborhood, xEpsNeighborhood, *x, lambda, mu))
						R.push_back(x);
				}
				for (unsigned j = 0; j < R.size(); ++j) {
					if(R[j]->ClId == UNCLASSIFIED)
						queue.push_back(R[j]);
					if(R[j]->ClId == UNCLASSIFIED || R[j]->ClId == NOISE)
					{
						cout << "class" << clusterId << endl;
						R[j]->ClId = clusterId;
					}
				}
			}
		}
		else
			D[i].ClId = NOISE;
	}
}
