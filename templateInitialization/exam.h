#ifndef EXAM_H
#define EXAM_H

#include "testdll.h"


template TESTDLL_API void Ctestdll::TestShow<Eigen::Matrix<double, -1, -1, 0, -1, -1>>(\
	Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);

template TESTDLL_API double Body<Pose<double>>::dWeight;
template TESTDLL_API double Body<Pose<float>>::dWeight;
//<Eigen::Matrix<double, -1, -1, 0, -1, -1>>(\
//	Eigen::PlainObjectBase<Eigen::Matrix<double, -1, -1, 0, -1, -1>> &);

#endif //TTTT_H