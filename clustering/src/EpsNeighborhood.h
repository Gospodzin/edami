#ifndef _EPSNEIGHBORHOOD_H
#define _EPSNEIGHBORHOOD_H

#include "Neighborhood.h"
#include "Point.h"

template<class T>
class EpsNeighborhood : public Neighborhood<T>
{
private:
	vector<double> subspacePreferenceVector;
	int subspacePreferenceDimensionality;

public:
	EpsNeighborhood(){}
	EpsNeighborhood(T * thePoint, vector<T*> points)
		: Neighborhood<T>(thePoint, points), subspacePreferenceDimensionality(0) {}

	double getVarianceAlongAttr(int n);
	void computeSubspacePreferenceParameters(double delta, double kappa);
	vector <double> getSubspacePreferenceVector();
	int getPreferenceDimensionality();
	double getPreferenceWeightedDistanceTo(T * point);
};

template<class T>
double EpsNeighborhood<T>::getVarianceAlongAttr(int n) {
	double sum = 0.0;
	for (typename vector<T*>::iterator oneOfPoints = this->points.begin(); oneOfPoints != this->points.end(); ++oneOfPoints) {
		double dist = (*(this->thePoint))[n] - (**oneOfPoints)[n];
		sum = sum + (dist * dist);
	}
	return sum / this->getCount();
}

template<class T>
void EpsNeighborhood<T>::computeSubspacePreferenceParameters(double delta, double kappa){
	for (int i = 0; i < (this->thePoint)->Coordinates.size(); ++i) {
		double variance = getVarianceAlongAttr(i);
		if(variance <= delta){
			subspacePreferenceVector.push_back(kappa);
			subspacePreferenceDimensionality++;
		}
		else
			subspacePreferenceVector.push_back(1.0);
	}
}

template<class T>
vector<double> EpsNeighborhood<T>::getSubspacePreferenceVector(){
	return subspacePreferenceVector;
}

template<class T>
int EpsNeighborhood<T>::getPreferenceDimensionality(){
	return subspacePreferenceDimensionality;
}

template<class T>
double EpsNeighborhood<T>::getPreferenceWeightedDistanceTo(T * otherPoint){
	double sum = 0.0;
	for (int i = 0; i < (this->thePoint)->Coordinates.size(); ++i) {
		double diff = (*(this->thePoint))[i] - (*otherPoint)[i];
		sum += subspacePreferenceVector[i] * diff * diff;
	}
	return sqrt(sum);
}

#endif 
