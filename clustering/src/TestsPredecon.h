#include "Point.h"
#include "EpsNeighborhood.h"
#include "WeightedNeighborhood.h"
#include "PreDeCon.h"

BOOST_AUTO_TEST_SUITE (Predecon)

//EpsNeighborhood getSampleNeighborhood() {
//	vector<Point*> points;
//	Point * p1 = new Point({ 1.0, 3.0 });
//	Point * p2 = new Point({ -3.0, 4.0 });
//	Point * p3 = new Point({ 2.0, -5.0 });
//	points.push_back(p1);
//	points.push_back(p2);
//	points.push_back(p3);
//	Point * thePoint = new Point({ 0.0, 0.0 });
//	EpsNeighborhood epsNeighborhood(thePoint, points, preDeConMeasures::euclideanDistance);
//	return epsNeighborhood;
//}
//
//BOOST_AUTO_TEST_CASE(VarianceAlongAttr)
//{
//	vector<Point*> points = {new Point( { 0.0, 0.0 }), new Point( { 1.0, 3.0 }), new Point( { -3.0, 4.0 }), new Point( { 2.0, -5.0 })};
//	auto epsNeighborhood = EpsNeighborhood(new Point({ 0.0, 0.0 }), points, preDeConMeasures::euclideanDistance);
//	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(0), 3.5, 0.0001);
//	BOOST_CHECK_CLOSE(epsNeighborhood.getVarianceAlongAttr(1), 12.5, 0.0001);
//}
//
//BOOST_AUTO_TEST_CASE(SubspacePreferenceVector)
//{
//	auto epsNeighborhood = getSampleNeighborhood();
//	epsNeighborhood.print();
//	vector<double> expected = {1000.0, 1.0};
//	epsNeighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
//	auto actual = epsNeighborhood.getSubspacePreferenceVector();
//	BOOST_CHECK_EQUAL_COLLECTIONS(actual.begin(), actual.end(), expected.begin(), expected.end());
//	BOOST_CHECK_EQUAL(epsNeighborhood.getPreferenceDimensionality(),1);
//}
//
//BOOST_AUTO_TEST_CASE(PreferenceWeightedDistance)
//{
//	auto epsNeighborhood = getSampleNeighborhood();
//	epsNeighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
//	auto actual = epsNeighborhood.getPreferenceWeightedDistanceTo(new Point({2.0,5.0}));
//	auto expected = sqrt(1000.0 * 4.0 + 1.0 * 25.0);
//	BOOST_CHECK_CLOSE(actual, expected, 0.0001);
//}
//
//EpsNeighborhood createAndHandleNeighborhood(Point * thePoint, vector<Point*> points) {
//	auto neighborhood = EpsNeighborhood(thePoint, points, preDeConMeasures::euclideanDistance);
//	neighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
//	return neighborhood;
//}
//
//BOOST_AUTO_TEST_CASE(WeightedNeighborhoodTest)
//{
//	EpsNeighborhood theNeighborhood = getSampleNeighborhood();
//	theNeighborhood.computeSubspacePreferenceParameters(10.0, 1000.0);
//
//	vector<EpsNeighborhood> otherNeighborhoods;
//	vector<Point*> points1 = {new Point({ 1.0, 3.0 }), new Point({ 1.1, 3.0 }), new Point({ 1.0, 2.9 })};
//	otherNeighborhoods.push_back(createAndHandleNeighborhood(new Point({ 1.0, 3.0 }), points1));
//
//	vector<Point*> points2 = {new Point({ -3.1, 4.1 }), new Point({ -2.9, 4.1 }), new Point({ -2.9, 3.9 })};
//	otherNeighborhoods.push_back(createAndHandleNeighborhood(new Point({ -3.0, 4.0 }), points2));
//	vector<Point*> points3 = {new Point({ 2.1, -5.0 }), new Point({ 2.0, -5.1 }), new Point({ 2.1, -5.1 })};
//	otherNeighborhoods.push_back(createAndHandleNeighborhood(new Point({ 2.0, -5.0 }), points3));
//
//	WeightedNeighborhood weighted1(125.0, theNeighborhood, otherNeighborhoods, 10.0, 1000.0);
//	BOOST_CHECK(weighted1.getThePoint() == theNeighborhood.getThePoint());
//	vector<Point*> expecteds = {new Point({ 1.0, 3.0 })};
//	vector<Point*> actuals = weighted1.getNeighbors();
//
//	BOOST_CHECK(expecteds.size() == actuals.size());
//	for (int i = 0; i < expecteds.size(); ++i)
//		BOOST_CHECK(*expecteds[i] == *actuals[i]);
//}
//
//BOOST_AUTO_TEST_CASE(VecContains)
//{
//	BOOST_CHECK(vecContains({Point({1.0,0.0}), Point({1.0,1.0}), Point({0.0,0.0})}, Point({0.0,0.0})));
//	BOOST_CHECK(!vecContains({Point({1.0,0.0}), Point({1.0,1.0}), Point({0.0,0.0})}, Point({2.0,0.0})));
//}

vector<DensePoint> loadDataMichal(std::string fileName)
{
	//TODO mocked
	vector<DensePoint> data;
	// task 3. from the 14L MockTestII :D
	data.push_back(DensePoint(vector<double> { 1, 2}));
	data.push_back(DensePoint(vector<double> { 2, 1}));
	data.push_back(DensePoint(vector<double> { 2, 2}));
	data.push_back(DensePoint(vector<double> { 3, 2}));
	data.push_back(DensePoint(vector<double> { 3, 5}));
	data.push_back(DensePoint(vector<double> { 4, 2}));
	data.push_back(DensePoint(vector<double> { 4, 4}));
	data.push_back(DensePoint(vector<double> { 4, 5}));
	data.push_back(DensePoint(vector<double> { 8, 5}));
	data.push_back(DensePoint(vector<double> { 8, 6}));
	data.push_back(DensePoint(vector<double> { 9, 5}));
	data.push_back(DensePoint(vector<double> { 10, 4}));
	data.push_back(DensePoint(vector<double> { 10, 2}));
	data.push_back(DensePoint(vector<double> { 11, 3}));
	return data;
}

BOOST_AUTO_TEST_CASE(PreDeConTest)
{
	vector<DensePoint> points = loadDataMichal("");
	runPredecon<DensePoint>(points, 1.1, 3, 2, 0.0, 100.0);
	for (int i = 0; i < points.size(); ++i) {
		cout << points[i].ClId << ": ";
		points[i].print();
	}
}

BOOST_AUTO_TEST_SUITE_END()
