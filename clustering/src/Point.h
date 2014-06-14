#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
private:
	union Ref
	{
		double Dist;
		double Length;
	};
public:
	Point() : ClId(UNCLASSIFIED) {}

	virtual int size() const;
	virtual void normalize();
	virtual double dotProd(Point& point);
	virtual double& operator[](int n) const;
	virtual bool operator==(const Point& other) const;
	

	Ref Ref;
	int ClId;
	int Id;
};

#endif 
