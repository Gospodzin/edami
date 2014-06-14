#include "PreDeCon.h"
#include "PreDeConMeasure.h"
#include "EpsNeighborhoodCalculation.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"
#include "commons.h"

#include <algorithm>
#include <exception>

bool vecContains(vector<Point> v, Point p){
	return (find(v.begin(), v.end(), p) != v.end());
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

WeightedNeighborhood & getNeighborhoodForPointId(vector<WeightedNeighborhood> neighborhoods, int id){
	for (int i = 0; i < neighborhoods.size(); ++i) {
		if(neighborhoods[i].getThePoint()->Id == id){
			return neighborhoods[i];
		}
	}
}

void runPredecon(vector<Point> & D, double eps, double mu, double lambda, double delta, double kappa){
	vector<EpsNeighborhood> epsNeighborhoods;
	vector<WeightedNeighborhood> weightedNeighborhoods;

	int id = 0;
	for (int i = 0; i < D.size(); ++i) {
		D[i].Id = id;
		++id;
	}

	for (int i = 0; i < D.size(); ++i)
		epsNeighborhoods.push_back(bruteForceEpsNeighborhoodCalc(eps, &D[i], D, preDeConMeasures::euclideanDistance));

	for (int i = 0; i < D.size(); ++i){
		epsNeighborhoods[i].computeSubspacePreferenceParameters(delta, kappa);
		D[i].meetsLambdaCondition = (epsNeighborhoods[i].getPreferenceDimensionality() <= lambda);
	}

	// TODO trzymać w pamięci tylko ważone sąsiedztwa

	for (int i = 0; i < D.size(); ++i) {
		vector<EpsNeighborhood> otherNeighborhoods;
		auto neighbors = epsNeighborhoods[i].getNeighbors();
		for (int k = 0; k < neighbors.size(); ++k) {
			for (int j = 0; j < epsNeighborhoods.size(); ++j) {
				if (epsNeighborhoods[j].getThePoint() == neighbors[k]) {
					otherNeighborhoods.push_back(epsNeighborhoods[j]);
					break;
				}
			}
		}
		weightedNeighborhoods.push_back(WeightedNeighborhood(eps, epsNeighborhoods[i], otherNeighborhoods, delta, kappa));
		D[i].isCorePoint = (weightedNeighborhoods[i].getCount() >= mu);
	}

	for (int i = 0; i < D.size(); ++i) {
//		cout << "eps " << i << endl;
//		epsNeighborhoods[i].print();
//		cout << "weighted" << endl;
//		weightedNeighborhoods[i].print();
//		cout << "lambda" << endl;
//		cout << D[i].meetsLambdaCondition << endl;
//		cout << "core" << endl;
//		cout << D[i].isCorePoint << endl;
	}

	int clusterId = 0;
	cout << "========================" << endl;
	for (int i = 0; i < D.size(); ++i) {
		if (D[i].ClId == UNCLASSIFIED) {
			if (D[i].isCorePoint) {
				clusterId++;

//				cout << "o" << endl;
//				D[i].print();
//				cout << "cl id" << endl;
//				cout << clusterId << endl;

				auto neighbors = weightedNeighborhoods[i].getNeighbors();

				vector<Point*> queue;
				queue.push_back(&D[i]);
				D[i].ClId = clusterId;

				while (queue.size() != 0) {

					Point * q = queue.back();
					queue.pop_back();

//					cout << "q" << endl;
//					q->print();

					auto weightedNeighbors = getNeighborhoodForPointId(weightedNeighborhoods, q->Id).getNeighbors();

					vector<Point*> R;
					for (int j = 0; j < weightedNeighbors.size(); ++j) {
						if (weightedNeighbors[j]->meetsLambdaCondition && weightedNeighbors[j]->Id != q->Id)
							R.push_back(weightedNeighbors[j]);
					}

//					cout << "R" << endl;
//					for (int j = 0; j < R.size(); ++j) {
//						R[j]->print();
//					}

					for (int j = 0; j < R.size(); ++j) {
						if (R[j]->ClId == UNCLASSIFIED && R[j]->isCorePoint) {
							queue.push_back(R[j]);
//							cout << "added to queue " << endl;
//							R[j]->print();
						}
						if (R[j]->ClId == UNCLASSIFIED || R[j]->ClId == NOISE) {
							R[j]->ClId = clusterId;
//							cout << "assigned " << clusterId << endl;
//							R[j]->print();
						}
					}
				}
			} else
				D[i].ClId = NOISE;
		}
	}
}
