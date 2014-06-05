#include "Point.h"

Point::Point(vector<double> coordinates)
{
	this->coordinates = coordinates;
}

string Point::print()
{
	string toPrint = "(";
	for(vector<double>::iterator it = coordinates.begin(); it != coordinates.end(); ++it)
	{
		ostringstream strs;
		strs << (*it);
		string str = strs.str();
		toPrint += str;
		toPrint += ",";
	}
	toPrint[toPrint.size()-1] = ')';
	return toPrint;
}

int Point::getVariablesNumber()
{
	return coordinates.size();
}

double Point::getNthAttr(int n)
{
	return coordinates[n];
}

Point Point::getProjectionOntoNthAttr(int n)
{
	vector<double> coordsOfProjection(getVariablesNumber(), 0.0);
	coordsOfProjection[n] = coordinates[n];
	return Point(coordsOfProjection);
}
