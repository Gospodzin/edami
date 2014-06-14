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

<<<<<<< HEAD
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
=======
//bool isCorePoint(EpsNeighborhood epsNeighborhood, WeightedNeighborhood weightedNeighborhood, int lambda, int mu){
//
//	// TODO w punkcie flaga czy epsNeighborhood.getPreferenceDimensionality() <= lambda, flaga na core
//	return epsNeighborhood.getPreferenceDimensionality() <= lambda &&
//			weightedNeighborhood.getCount() >= mu;
//}

//bool isDirectlyReachable(EpsNeighborhood p1EpsNeighborhood, WeightedNeighborhood p1WeightedNeighborhood,
//						 EpsNeighborhood p2EpsNeighborhood, Point p2, int lambda, int mu){
//	return isCorePoint(p1EpsNeighborhood, p1WeightedNeighborhood, lambda, mu) &&
//			p2EpsNeighborhood.getPreferenceDimensionality() <= lambda &&
//			vecContains(p1WeightedNeighborhood.getNeighbors(), p2);
//}
>>>>>>> PreDeCon is working

int getPointIndex(vector<Point> D, Point q){
	for (unsigned k = 0; k < D.size(); ++k) {
		if (D[k] == q) {
			return k;
			break;
		}
	}
	return -1;
}

<<<<<<< HEAD
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
=======
//EpsNeighborhood getNeighborhoodForPoint(vector<EpsNeighborhood> neighborhoods, Point & point){
//	for (int i = 0; i < neighborhoods.size(); ++i) {
//		if(neighborhoods[i].getThePoint() == point){
//			return neighborhoods[i];
//		}
//	}
//	return EpsNeighborhood();
//}

WeightedNeighborhood & getNeighborhoodForPointId(vector<WeightedNeighborhood> neighborhoods, int id){
	for (int i = 0; i < neighborhoods.size(); ++i) {
		if(neighborhoods[i].getThePoint()->id == id){
>>>>>>> PreDeCon is working
			return neighborhoods[i];
		}
	}
//	return WeightedNeighborhood();
}

void runPredecon(vector<Point> & D, double eps, double mu, double lambda, double delta, double kappa){
	vector<EpsNeighborhood> epsNeighborhoods;
	vector<WeightedNeighborhood> weightedNeighborhoods;

<<<<<<< HEAD
	for (unsigned i = 0; i < D.size(); ++i)
		epsNeighborhoods.push_back(bruteForceEpsNeighborhoodCalc(eps, D[i], D, measures::euclideanDistance));

	for (unsigned i = 0; i < D.size(); ++i)
=======
	int id = 0;
	for (int i = 0; i < D.size(); ++i) {
		D[i].id = id;
		++id;
	}

	for (int i = 0; i < D.size(); ++i)
		epsNeighborhoods.push_back(bruteForceEpsNeighborhoodCalc(eps, &D[i], D, preDeConMeasures::euclideanDistance));

	for (int i = 0; i < D.size(); ++i){
>>>>>>> PreDeCon is working
		epsNeighborhoods[i].computeSubspacePreferenceParameters(delta, kappa);
		D[i].meetsLambdaCondition = (epsNeighborhoods[i].getPreferenceDimensionality() <= lambda);
	}

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
		D[i].isCorePoint = (weightedNeighborhoods[i].getCount() >= mu);
	}

<<<<<<< HEAD
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
=======
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

					auto weightedNeighbors = getNeighborhoodForPointId(weightedNeighborhoods, q->id).getNeighbors();

					vector<Point*> R;
					for (int j = 0; j < weightedNeighbors.size(); ++j) {
						if (weightedNeighbors[j]->meetsLambdaCondition && weightedNeighbors[j]->id != q->id)
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
>>>>>>> PreDeCon is working
					}
				}
			} else
				D[i].ClId = NOISE;
		}
	}
}

//if(D[i].isCorePoint){
//				clusterId++;
//
//				cout << "o" << endl;
//				D[i].print();
//				cout << "cl id" << endl;
//				cout << clusterId << endl;
//
//	//			auto neighbors = weightedNeighborhoods[i].getNeighbors();
//
//	//			if(D[i].ClId == UNCLASSIFIED)
//	//				D[i].ClId = clusterId;
//
//				auto queue = getNeighborhoodForPointId(weightedNeighborhoods, D[i].id).getNeighbors();
//				cout << "queue" << endl;
//				for (int j = 0; j < queue.size(); ++j) {
//					queue[j]->print();
//				}
//
//				while(queue.size() != 0){
//
//					Point * q = queue.back();
//					queue.pop_back();
//
//					cout << "q" << endl;
//					q->print();
//
//					vector<Point*> R;
//					auto qNeighbors = getNeighborhoodForPointId(weightedNeighborhoods, q->id).getNeighbors();
//					for (int j = 0; j < qNeighbors.size(); ++j) {
//	//					if(qNeighbors[j]->meetsLambdaCondition && qNeighbors[j]->id != q->id)
//						if(qNeighbors[j]->meetsLambdaCondition)
//							R.push_back(qNeighbors[j]);
//					}
//
//					cout << "R" << endl;
//					for (int j = 0; j < R.size(); ++j) {
//						R[j]->print();
//					}
//
//					for (int j = 0; j < R.size(); ++j) {
//						if(R[j]->ClId == UNCLASSIFIED && R[j]->isCorePoint)
//						{
//							queue.push_back(R[j]);
//							cout << "added to queue "  << endl;
//							R[j]->print();
//						}
//						if(R[j]->ClId == UNCLASSIFIED || R[j]->ClId == NOISE)
//						{
//							R[j]->ClId = clusterId;
//							cout << "assigned " << clusterId << endl;
//							R[j]->print();
//						}
//					}
//				}
//			}
//			else
//				D[i].ClId = NOISE;

//int clusterId = 0;
//	cout << "========================" << endl;
//	for (int i = 0; i < D.size(); ++i) {
//		if(D[i].isCorePoint){
//			clusterId++;
//
//			cout << "o" << endl;
//			D[i].print();
//			cout << "cl id" << endl;
//			cout << clusterId << endl;
//
//			auto neighbors = weightedNeighborhoods[i].getNeighbors();
//
//			vector<Point*> queue;
//			if(D[i].ClId == UNCLASSIFIED){
//				queue.push_back(&D[i]);
//				D[i].ClId = clusterId;
//			}
//
//			while(queue.size() != 0){
//
//				Point * q = queue.back();
//				queue.pop_back();
//
//				cout << "q" << endl;
//				q->print();
//
//				auto weightedNeighbors = getNeighborhoodForPointId(weightedNeighborhoods, q->id).getNeighbors();
//
//				vector<Point*> R;
//				for (int j = 0; j < weightedNeighbors.size(); ++j) {
//					if(weightedNeighbors[j]->meetsLambdaCondition && weightedNeighbors[j]->id != q->id)
////					if(weightedNeighbors[j]->meetsLambdaCondition)
//						R.push_back(weightedNeighbors[j]);
//				}
//
//				cout << "R" << endl;
//				for (int j = 0; j < R.size(); ++j) {
//					R[j]->print();
//				}
//
//				for (int j = 0; j < R.size(); ++j) {
//					if(R[j]->ClId == UNCLASSIFIED && R[j]->isCorePoint)
//					{
//						queue.push_back(R[j]);
//						cout << "added to queue "  << endl;
//						R[j]->print();
//					}
//					if(R[j]->ClId == UNCLASSIFIED || R[j]->ClId == NOISE)
//					{
//						R[j]->ClId = clusterId;
//						cout << "assigned " << clusterId << endl;
//						R[j]->print();
//					}
//				}
//			}
//		}
//		else
//			D[i].ClId = NOISE;
//	}
