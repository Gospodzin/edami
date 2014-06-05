#include "Point.h"
#include "Neighborhood.h"

BOOST_AUTO_TEST_SUITE (Predecon)

Neighborhood getSampleNeighborhood() {
	vector<Point> points;
	points.push_back(Point( { 1.0, 3.0 }));
	points.push_back(Point( { -3.0, 4.0 }));
	points.push_back(Point( { 2.0, -5.0 }));
	Neighborhood epsNeighborhood(Point( { 0.0, 0.0 }), points);
	return epsNeighborhood;
}

BOOST_AUTO_TEST_CASE(VarianceAlongAttr)
{
	auto epsNeighborhood = getSampleNeighborhood();
	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(0, euclideanDistance), 3.5, 0.0001);
	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(1, euclideanDistance), 12.5, 0.0001);
}

BOOST_AUTO_TEST_CASE(SubspacePreferenceVector)
{
	auto epsNeighborhood = getSampleNeighborhood();
	vector<double> expected = {1000.0, 1.0};
	auto actual = epsNeighborhood.getSubspacePreferenceVector(10.0, 1000.0, euclideanDistance);
	BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_SUITE_END()
