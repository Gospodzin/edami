#include "Point.h"
#include "Neighborhood.h"

BOOST_AUTO_TEST_SUITE (Predecon)

BOOST_AUTO_TEST_CASE(VarianceAlongAttr)
{
	vector<Point> points;
	points.push_back(Point({1.0,3.0}));
	points.push_back(Point({-3.0,4.0}));
	points.push_back(Point({2.0,-5.0}));
	Neighborhood epsNeighborhood(Point({0.0,0.0}), points);
	epsNeighborhood.print();

	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(0, euclideanDistance), 14.0 / 4.0, 0.0001);
	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(1, euclideanDistance), (9.0 + 16.0 + 25.0) / 4.0, 0.0001);
}

BOOST_AUTO_TEST_SUITE_END()
