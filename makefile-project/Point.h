#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
private:
	vector<double> coordinates;

public:
	Point(){}
	Point(vector<double> coordinates);
	Point(const Point& other) : coordinates( other.coordinates ){}

	void print();

	int getAttrsNumber();
	double getNthAttr(int n);
	Point getProjectionOntoNthAttr(int n);

	bool operator==(const Point& other);
};

#endif 
