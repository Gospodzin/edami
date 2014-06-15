#include "SparsePoint.h"

void SparsePoint::print()
{
	//string toPrint = "(";
	//for (vector<double>::iterator it = Coordinates.begin(); it != Coordinates.end(); ++it)
	//{
	//	ostringstream strs;
	//	strs << (*it);
	//	string str = strs.str();
	//	toPrint += str;
	//	toPrint += ",";
	//}
	//toPrint[toPrint.size() - 1] = ')';
	//toPrint = toPrint + "\tClId=" + to_string(ClId);
	//cout << toPrint << endl;
}

int SparsePoint::size() const
{
	return 0; //Coordinates.size();
}

//Point& DensePoint::getProjectionOntoNthAttr(int n)
//{
//	vector<double> coordsOfProjection(size(), 0.0);
//	coordsOfProjection[n] = Coordinates[n];
//	return DensePoint(coordsOfProjection);
//}

double& SparsePoint::operator[](int n)
{
	//return Coordinates[n];
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
	return 0;//inner_product(Coordinates.begin(), Coordinates.end(), ((DensePoint&)point).Coordinates.begin(), (double)0);
}
