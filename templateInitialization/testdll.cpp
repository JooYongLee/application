// testdll.cpp : DLL ���� ���α׷��� ���� ������ �Լ��� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include "testdll.h"


// ������ ������ �����Դϴ�.
TESTDLL_API int ntestdll=0;

// ������ �Լ��� �����Դϴ�.
TESTDLL_API int fntestdll(void)
{
    return 42;
}

// ������ Ŭ������ �������Դϴ�.
// Ŭ���� ���Ǹ� ������ testdll.h�� �����Ͻʽÿ�.
//Ctestdll::Ctestdll()
//{
//	std::cout << __FUNCTION__ << std::endl;
//    return;
//}

template<class PointDerive>
double Body<PointDerive>::dWeight = 0.3;

double Ctestdll::dWeight = 0.3;


void Ctestdll::test_s(Eigen::MatrixXd &x)
{
	TestShow(x);
}
template<typename Derived>
void Ctestdll::TestShow(Eigen::PlainObjectBase<Derived> &mat)
{	
	std::cout << "method tempalte class:\n" <<mat << "\n\n";
}


