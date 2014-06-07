#include "Point.h"
#include "Helpers.h"
#include "Distances.h"
#include "EpsNeighborhoodCalculation.h"

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

BOOST_AUTO_TEST_CASE(bruteForceEpsNeighborCalc)
{
	Point thePoint({0.0,0.0});
	vector<Point> otherPoints = {Point({1.0,1.0}), Point({1.9,0.0}), Point({1.0,0.0}),
			Point({-1.5,-1.7}), Point({-3.0, 0})};

	auto epsNeighborhood = bruteForceEpsNeighborhoodCalc(2.0, thePoint, otherPoints, euclideanDistance);

	BOOST_CHECK(epsNeighborhood.getThePoint() == Point({0.0,0.0}));
	for (int i = 0; i < epsNeighborhood.getNeighbors().size(); ++i) {
		BOOST_CHECK(epsNeighborhood.getNeighbors()[i] == otherPoints[i]);
	}
}

BOOST_AUTO_TEST_SUITE_END()
