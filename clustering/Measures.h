#include "commons.h"
#include "Point.h"

#ifndef _MEASURES_H
#define _MEASURES_H

namespace measures
{
	double euclideanDistance(Point p1, Point p2);
	double minusCosSim(Point p1, Point p2);
	double minusNormCosSim(Point p1, Point p2);
}
#endif 
