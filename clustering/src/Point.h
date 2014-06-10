#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
public:
	Point() : ClId(UNCLASSIFIED) {}
	Point(vector<double> coordinates) : ClId(UNCLASSIFIED), coordinates(coordinates) {}

	void print();
	void set(int n, double f){ coordinates[n] = f; }
	int getAttrsNumber();
	double getNthAttr(int n);
	Point getProjectionOntoNthAttr(int n);

	bool operator==(const Point& other);

	int ClId;
	double RefDist;
	int id;
	vector<double> coordinates;
};

#endif 
