#ifndef _POINT_H
#define _POINT_H

#include "commons.h"

class Point
{
private:
	union Ref
	{
		double Dist;
		double SquareLen;
	};
public:
	Point() : ClId(UNCLASSIFIED), meetsLambdaCondition(false), isCorePoint(false) {}

	virtual int size() const = 0;
	virtual void normalize() = 0;
	virtual void calcSquareLength() = 0;
	virtual double dotProd(Point& point) = 0;
	virtual double& operator[](int n) = 0;
	virtual bool operator==(Point& other) = 0;
	void print(){}
	
	Ref Ref;
	int ClId;
	int Id;

	bool meetsLambdaCondition;
	bool isCorePoint;
};

#endif 
