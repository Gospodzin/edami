#ifndef _L_SET_OF_POINTS_H
#define _L_SET_OF_POINTS_H
#include "SetOfPoints.h"

template<class T>
class LSetOfPoints : public SetOfPoints<T>
{
public:
	LSetOfPoints(vector<T>& dataSet);
	vector<T*> regionQuery(T& point, double eps, double(*measure)(T&, T&));
	void prepare(T refP, double(*measure)(T&, T&));
private:
	void sortByRefDist();
	void calculateRefDists(T refP, double(*measure)(T&, T&));
	void setIds();
	T& findRefP();
};

#endif