// testdll.cpp : DLL 응용 프로그램을 위해 내보낸 함수를 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include "testdll.h"


// 내보낸 변수의 예제입니다.
TESTDLL_API int ntestdll=0;

// 내보낸 함수의 예제입니다.
TESTDLL_API int fntestdll(void)
{
    return 42;
}

// 내보낸 클래스의 생성자입니다.
// 클래스 정의를 보려면 testdll.h를 참조하십시오.
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


