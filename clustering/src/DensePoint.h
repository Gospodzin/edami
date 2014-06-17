#ifndef _DENSE_POINT_H
#define _DENSE_POINT_H

#include "Point.h"

class DensePoint : public Point
{
public:
	DensePoint();
	DensePoint(vector<double> coordinates) : Coordinates(coordinates) {}
	void print();
	string toString();
//	Point& getProjectionOntoNthAttr(int n);

	int size() const;
	void normalize();
	void calcSquareLength();
	double dotProd(Point& point);
	
	double& operator[](int n);
	bool operator==(Point& other);

	vector<double> Coordinates;

	vector <double> SubspacePreferenceVector;
};

#endif
