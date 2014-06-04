#include "stdafx.h"

int main ()
{
  Point p1, p2;

  p1.coordinates.push_back(1.0);
  p1.coordinates.push_back(2.0);
  p1.coordinates.push_back(3.0);

  p2.coordinates.push_back(2.0);
  p2.coordinates.push_back(3.0);
  p2.coordinates.push_back(4.0);

  double dist = euclideanDistance(p1,p2);
  if( abs(dist-sqrt(3)) < 0.0001 )
  	std::cout << "euclideanDistance is OK" << std::endl;
  else
  	std::cout << "ERROR in euclideanDistance" << std::endl;
}