#ifndef LOADER_H_
#define LOADER_H_

#include "commons.h"
#include "DensePoint.h"
#include "SparsePoint.h"

namespace loader
{
	vector<SparsePoint> loadDataSparse(string fileName);
	vector<DensePoint> loadDataDense(string fileName);
	vector<DensePoint> loadDataMarcin();
	vector<DensePoint> loadDataMichal();
}

#endif /* LOADER_H_ */
