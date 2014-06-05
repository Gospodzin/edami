#include "Point.h"
#include "Helpers.h"
#include "Distances.h"

BOOST_AUTO_TEST_SUITE (Distances)

BOOST_AUTO_TEST_CASE(euclidean)
{
	vector<double> attrs1 = {1.0, 2.0, 3.0};
	Point p1(attrs1);

	vector<double> attrs2 = {2.0, 3.0, 4.0};
	Point p2(attrs2);

	double dist = euclideanDistance(p1,p2);

	BOOST_CHECK_CLOSE(dist, sqrt(3), 0.0001);
}

BOOST_AUTO_TEST_SUITE_END()
