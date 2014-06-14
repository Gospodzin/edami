#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
public:
	Point() : ClId(UNCLASSIFIED), meetsLambdaCondition(false), isCorePoint(false) {}
	Point(vector<double> coordinates) : ClId(UNCLASSIFIED), meetsLambdaCondition(false), isCorePoint(false), coordinates(coordinates) {}

	void print();
	void set(int n, double f){ coordinates[n] = f; }
	int getAttrsNumber();
	double& operator[](int n);
	Point getProjectionOntoNthAttr(int n);

	bool operator==(const Point& other);

	int ClId;
	double RefDist;
	int Id;
	vector<double> coordinates;

	bool meetsLambdaCondition;
	bool isCorePoint;

	vector<double> subspacePreferenceVector;
};

#endif 
