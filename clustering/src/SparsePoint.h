#ifndef _SPARSE_POINT_H
#define _SPARSE_POINT_H

#include "Point.h"

struct SparsePair
{
	int Id;
	double Value;
};

class SparsePoint : public Point
{
public:
	SparsePoint(){}
	SparsePoint(vector<SparsePair> coordinates) : Coordinates(coordinates) {}
	void print();
	//	Point& getProjectionOntoNthAttr(int n);

	int size() const;
	void normalize();
	void calcSquareLength();
	double dotProd(Point& point);

	double& operator[](int n);
	bool operator==(Point& other);

	vector<SparsePair> Coordinates;
};

#endif
