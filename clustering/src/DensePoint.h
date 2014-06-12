#ifndef _DENSE_POINT_H
#define _DENSE_POINT_H

#include "Point.h"

class DensePoint : public Point
{
public:
	DensePoint();
	~DensePoint();
	void print();
	void set(int n, double f){ coordinates[n] = f; }
	int getAttrsNumber();
	double getNthAttr(int n);
	Point getProjectionOntoNthAttr(int n);

	bool operator==(const Point& other);
};

#endif