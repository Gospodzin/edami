#include "DensePoint.h"

void DensePoint::print()
{
	string toPrint = "(";
	for (vector<double>::iterator it = coordinates.begin(); it != coordinates.end(); ++it)
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

int DensePoint::getAttrsNumber()
{
	return coordinates.size();
}

double DensePoint::getNthAttr(int n)
{
	return coordinates[n];
}

Point DensePoint::getProjectionOntoNthAttr(int n)
{
	vector<double> coordsOfProjection(getAttrsNumber(), 0.0);
	coordsOfProjection[n] = coordinates[n];
	return Point(coordsOfProjection);
}

bool DensePoint::operator==(const Point& other){
	if (coordinates.size() != other.coordinates.size())
		return false;
	for (unsigned i = 0; i < coordinates.size(); ++i) {
		if (coordinates[i] != other.coordinates[i])
			return false;
	}
	return true;
}
