#include "DensePoint.h"

#include <iterator>
#include <iostream>

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
	toPrint = toPrint + "\tClId=" + to_string(ClId);
	cout << toPrint << endl;
}

string DensePoint::toString(){
	string toPrint = "(";
		for (vector<double>::iterator it = Coordinates.begin(); it != Coordinates.end(); ++it)
		{
			ostringstream strs;
			strs << (*it);
			string str = strs.str();
			toPrint += str;
			toPrint += ",";
		}
		toPrint[toPrint.size()-1] = ')';
		toPrint = toPrint + "\tcluster Id = " + to_string(ClId) + " subspace pref: ";

		std::ostringstream oss;

		  if (!SubspacePreferenceVector.empty())
		  {
		    // Convert all but the last element to avoid a trailing ","
		    copy(SubspacePreferenceVector.begin(), SubspacePreferenceVector.end()-1,
		        ostream_iterator<int>(oss, ","));

		    // Now add the last element with no delimiter
		    oss << SubspacePreferenceVector.back();
		  }

		toPrint +=oss.str();
		return toPrint;
}

int DensePoint::size() const
{
	return Coordinates.size();
}

//Point& DensePoint::getProjectionOntoNthAttr(int n)
//{
//	vector<double> coordsOfProjection(size(), 0.0);
//	coordsOfProjection[n] = Coordinates[n];
//	return DensePoint(coordsOfProjection);
//}

double& DensePoint::operator[](int n)
{
	return Coordinates[n];
}

bool DensePoint::operator==(Point& other){
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

void DensePoint::calcSquareLength()
{
	Ref.SquareLen = dotProd(*this);
}

double DensePoint::dotProd(Point& point)
{
	return inner_product(Coordinates.begin(), Coordinates.end(), ((DensePoint&)point).Coordinates.begin(), (double)0);
}
