#include "Point.h"
#include "Neighborhood.h"

BOOST_AUTO_TEST_SUITE (Predecon)

Neighborhood getSampleNeighborhood() {
	vector<Point> points;
	points.push_back(Point( { 1.0, 3.0 }));
	points.push_back(Point( { -3.0, 4.0 }));
	points.push_back(Point( { 2.0, -5.0 }));
	Neighborhood epsNeighborhood(Point( { 0.0, 0.0 }), points, euclideanDistance);
	return epsNeighborhood;
}

BOOST_AUTO_TEST_CASE(VarianceAlongAttr)
{
	auto epsNeighborhood = getSampleNeighborhood();
	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(0), 3.5, 0.0001);
	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(1), 12.5, 0.0001);
}

BOOST_AUTO_TEST_CASE(SubspacePreferenceVector)
{
	auto epsNeighborhood = getSampleNeighborhood();
	vector<double> expected = {1000.0, 1.0};
	epsNeighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
	auto actual = epsNeighborhood.getSubspacePreferenceVector();
	BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());
	BOOST_CHECK_EQUAL(epsNeighborhood.getPreferenceDimensionality(),1);
}

BOOST_AUTO_TEST_CASE(PreferenceWeightedDistance)
{
	auto epsNeighborhood = getSampleNeighborhood();
	epsNeighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
	auto actual = epsNeighborhood.getPreferenceWeightedDistanceTo(Point({2.0,5.0}));
	auto expected = sqrt(1000.0 * 4.0 + 1.0 * 25.0);
	BOOST_CHECK_CLOSE(actual, expected, 0.0001);
}

BOOST_AUTO_TEST_SUITE_END()
