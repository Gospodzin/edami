#include "Point.h"
#include "DensePoint.h"
#include "SparsePoint.h"
#include "Measures.h"
#include "EpsNeighborhoodCalculation.h"

BOOST_AUTO_TEST_SUITE (Distances)

//BOOST_AUTO_TEST_CASE(euclidean)
//{
//	vector<double> attrs1 = {1.0, 2.0, 3.0};
//	DensePoint p1(attrs1);
//
//	vector<double> attrs2 = {2.0, 3.0, 4.0};
//	DensePoint p2(attrs2);
//
//	double dist = measures::euclideanDistance<DensePoint>(p1,p2);
//
//	BOOST_CHECK_CLOSE(dist, sqrt(3), 0.0001);
//}
//
//BOOST_AUTO_TEST_CASE(bruteForceEpsNeighborCalc)
//{
//	Point * thePoint = new DensePoint({0.0,0.0});
//	vector<DensePoint> otherPoints = {DensePoint({1.0,1.0}),DensePoint({1.9,0.0}),DensePoint({1.0,0.0}), DensePoint({-1.5,-1.7}), DensePoint({-3.0, 0})};
//
//	auto epsNeighborhood = bruteForceEpsNeighborhoodCalc<DensePoint>(2.0, thePoint, otherPoints, measures::euclideanDistance);
//
//	BOOST_CHECK(epsNeighborhood.getThePoint() == DensePoint({0.0,0.0}));
//	for (int i = 0; i < epsNeighborhood.getNeighbors().size(); ++i) {
//		BOOST_CHECK(epsNeighborhood.getNeighbors()[i] == otherPoints[i]);
//	}
//}

BOOST_AUTO_TEST_SUITE_END()
