#include "SparsePoint.h"

void SparsePoint::print()
{
	for (int i = 0; i < Coordinates.size(); ++i) {
		cout << "id: " << Coordinates[i].Id << endl;
		cout << "value: " << Coordinates[i].Value << endl;
	}
}

int SparsePoint::size() const
{
	Coordinates.size();

	return -1;
}

//Point& DensePoint::getProjectionOntoNthAttr(int n)
//{
//	vector<double> coordsOfProjection(size(), 0.0);
//	coordsOfProjection[n] = Coordinates[n];
//	return DensePoint(coordsOfProjection);
//}

double& SparsePoint::operator[](int n)
{
	for (int i = 0; i < Coordinates.size(); ++i) {
		if(Coordinates[i].Id == n)
			return Coordinates[i].Value;
	}
}

bool SparsePoint::operator==(Point& other){
	//if (size() != other.size())
	//	return false;
	//for (unsigned i = 0; i < size(); ++i) {
	//	if (Coordinates[i] != other[i])
	//		return false;
	//}
	return true;
}

void SparsePoint::normalize()
{
	//double length = sqrt(inner_product(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), double(0)));
	//transform(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), [length](double val) -> double {return val / length; });
}

void SparsePoint::calcSquareLength()
{
	//Ref.SquareLen = dotProd(*this);
}

double SparsePoint::dotProd(Point& point)
{
	SparsePoint& sparsePoint = (SparsePoint&)point;
	return 0;//inner_product(Coordinates.begin(), Coordinates.end(), ((DensePoint&)point).Coordinates.begin(), (double)0);
}
