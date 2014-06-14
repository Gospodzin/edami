#ifndef _DENSE_POINT_H
#define _DENSE_POINT_H

#include "Point.h"

class DensePoint : public Point
{
public:
	DensePoint();
	DensePoint(vector<double> coordinates) : Coordinates(coordinates) {}
	~DensePoint();
	void print();
	int size() const;
	Point getProjectionOntoNthAttr(int n);
	void normalize();
	double dotProd(DensePoint& point);

	double& operator[](int n);
	bool operator==(const Point& other);

	vector<double> Coordinates;
};

#endif