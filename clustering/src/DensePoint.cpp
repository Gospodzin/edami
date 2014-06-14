#include "DensePoint.h"

void DensePoint::print()
{
	string toPrint = "(";
	for (vector<double>::iterator it = Coordinates.begin(); it != Coordinates.end(); ++it)
	{
		ostringstream strs;
		strs << (*it);
		string str = strs.str();
		toPrint += str;
		toPrint += ",";
	}
	toPrint[toPrint.size() - 1] = ')';
	cout << toPrint << endl;
}

int DensePoint::size() const
{
	return Coordinates.size();
}

Point DensePoint::getProjectionOntoNthAttr(int n)
{
	vector<double> coordsOfProjection(size(), 0.0);
	coordsOfProjection[n] = Coordinates[n];
	return DensePoint(coordsOfProjection);
}

double& DensePoint::operator[](int n)
{
	return Coordinates[n];
}

bool DensePoint::operator==(const Point& other){
	if (size() != other.size())
		return false;
	for (unsigned i = 0; i < size(); ++i) {
		if (Coordinates[i] != other[i])
			return false;
	}
	return true;
}

void DensePoint::normalize()
{
	double length = sqrt(inner_product(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), double(0)));
	transform(Coordinates.begin(), Coordinates.end(), Coordinates.begin(), [length](double val) -> double {return val / length; });
}

double DensePoint::dotProd(DensePoint& point)
{
	return inner_product(Coordinates.begin(), Coordinates.end(), point.Coordinates.begin(), (double)0);
}
