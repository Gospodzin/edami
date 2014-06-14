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
	SparsePoint();
	~SparsePoint();

	vector<SparsePair> Coordinates;
};

#endif