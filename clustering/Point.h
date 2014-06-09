#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
public:
	Point();
	Point(vector<double> coordinates);

	void print();
	void set(int n, double f){ coordinates[n] = f; }
	int getAttrsNumber();
	double getNthAttr(int n);
	Point getProjectionOntoNthAttr(int n);

	bool operator==(const Point& other);

	int ClId = UNCLASSIFIED;
	double RefDist;
	int id;
protected:
	vector<double> coordinates;
};

#endif 
