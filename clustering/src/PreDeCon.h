#ifndef PREDECON_H_
#define PREDECON_H_

#include <ctime>

#include "Point.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"
#include "Measures.h"
#include "EpsNeighborhoodCalculation.h"

template<class T>
bool vecContains(vector<T> & v, T p){
	return (find(v.begin(), v.end(), p) != v.end());
}

template<class T>
int getPointIndex(vector<T> & D, T q){
	for (int k = 0; k < D.size(); ++k) {
		if (D[k] == q) {
			return k;
			break;
		}
	}
}

template<class T>
WeightedNeighborhood<T> & getNeighborhoodForPointId(vector<WeightedNeighborhood<T>> neighborhoods, int id){
	for (int i = 0; i < neighborhoods.size(); ++i) {
		if(neighborhoods[i].getThePoint()->Id == id){
			return neighborhoods[i];
		}
	}
}

template<class T>
void runPredecon(vector<T> & D, double eps, double mu, double lambda, double delta, double kappa, vector<double> times){

	vector<WeightedNeighborhood<T>> weightedNeighborhoods;

	int Id = 0;
	for (int i = 0; i < D.size(); ++i) {
		D[i].Id = Id;
		++Id;
	}

	{
		vector<EpsNeighborhood<T>> epsNeighborhoods;

		clock_t start = clock();
		for (int i = 0; i < D.size(); ++i)
			epsNeighborhoods.push_back(bruteForceEpsNeighborhoodCalc<T>(eps, &D[i], D, measures::euclideanDistance));
		clock_t ends = clock();
		times.push_back((double)(ends - start) / CLOCKS_PER_SEC);
		cout << "epsNeighborhoods calculation: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;

		start = clock();
		for (int i = 0; i < D.size(); ++i){
			epsNeighborhoods[i].computeSubspacePreferenceParameters(delta, kappa);
			D[i].meetsLambdaCondition = (epsNeighborhoods[i].getPreferenceDimensionality() <= lambda);
		}
		ends = clock();
		times.push_back((double)(ends - start) / CLOCKS_PER_SEC);
		cout << "computeSubspacePreferenceParameters: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;

		start = clock();
		for (int i = 0; i < D.size(); ++i) {
			vector<EpsNeighborhood<T>> otherNeighborhoods;
			auto neighbors = epsNeighborhoods[i].getNeighbors();
			for (int k = 0; k < neighbors.size(); ++k) {
				for (int j = 0; j < epsNeighborhoods.size(); ++j) {
					if (epsNeighborhoods[j].getThePoint() == neighbors[k]) {
						otherNeighborhoods.push_back(epsNeighborhoods[j]);
						break;
					}
				}
			}
			weightedNeighborhoods.push_back(WeightedNeighborhood<T>(eps, epsNeighborhoods[i], otherNeighborhoods, delta, kappa));
			D[i].isCorePoint = (weightedNeighborhoods[i].getCount() >= mu);
		}
		ends = clock();
		times.push_back((double)(ends - start) / CLOCKS_PER_SEC);
		cout << "weighted neighborhoods calculation: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
	}

//	for (int i = 0; i < D.size(); ++i) {
////		cout << "eps " << i << endl;
////		epsNeighborhoods[i].print();
////		cout << "weighted" << endl;
////		weightedNeighborhoods[i].print();
////		cout << "lambda" << endl;
////		cout << D[i].meetsLambdaCondition << endl;
////		cout << "core" << endl;
////		cout << D[i].isCorePoint << endl;
//	}

	clock_t start = clock();
	int clusterId = 0;
	for (int i = 0; i < D.size(); ++i) {
		if (D[i].ClId == UNCLASSIFIED) {
			if (D[i].isCorePoint) {
				clusterId++;

//				cout << "o" << endl;
//				D[i].print();
//				cout << "cl Id" << endl;
//				cout << clusterId << endl;

				auto neighbors = weightedNeighborhoods[i].getNeighbors();

				vector<T*> queue;
				queue.push_back(&D[i]);
				D[i].ClId = clusterId;

				while (queue.size() != 0) {

					T * q = queue.back();
					queue.pop_back();

//					cout << "q" << endl;
//					q->print();

					auto weightedNeighbors = getNeighborhoodForPointId(weightedNeighborhoods, q->Id).getNeighbors();

					vector<T*> R;
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
	clock_t ends = clock();
	times.push_back((double)(ends - start) / CLOCKS_PER_SEC);
	cout << "predecon run: " << (double)(ends - start) / CLOCKS_PER_SEC << endl;
}


#endif /* PREDECON_H_ */
