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
	return 	Coordinates.size();
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
	SparsePoint& sparseOther = (SparsePoint&)other;

	if (Coordinates.size() != sparseOther.Coordinates.size())
		return false;

	for (int i = 0; i < Coordinates.size(); i++)
	{
		if (Coordinates[i].Id != sparseOther.Coordinates[i].Id || Coordinates[i].Value != sparseOther.Coordinates[i].Value)
		{
			return false;
		}
	}

	return true;
}

void SparsePoint::normalize()
{
	double length = sqrt(dotProd(*this));
	for_each(Coordinates.begin(), Coordinates.end(), [length](SparsePair& pair){pair.Value /= length; });
}

void SparsePoint::calcSquareLength()
{
	this->Ref.SquareLen = dotProd(*this);
}

double SparsePoint::dotProd(Point& point)
{
	SparsePoint& a = (SparsePoint&)*this;
	SparsePoint& b = (SparsePoint&)point;
	
	double dotProd = 0;

	int offsetA = 0;
	int offsetB = 0;

	while (offsetA < a.Coordinates.size() && offsetB < b.Coordinates.size())
	{
		if (a.Coordinates[offsetA].Id > b.Coordinates[offsetB].Id)
		{
			++offsetB;
		}
		else if (a.Coordinates[offsetA].Id < b.Coordinates[offsetB].Id)
		{
			++offsetA;
		}
		else 
		{
			dotProd += a.Coordinates[offsetA].Value *  b.Coordinates[offsetB].Value;
		}
	}

	return dotProd;
}
