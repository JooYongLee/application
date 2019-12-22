// test_dll_example.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
//typedef ige::FileLogger::e_logType::LOG_ERROR dbuge;
//using debuge = ige::FileLogger::e_logType::LOG_ERROR;
#include "log_example.h"
//#include "testdll.h"
#include "../testdll/testdll.h"
#include <chrono>
#include <numeric>
#include <iostream>

using namespace std;
using namespace Eigen;


#include "TickTock.h"




//namespace plog
//{
//	Record& operator<<(Record& record, const Point& pt) // Implement a stream operator for our type.
//	{
//		return record << "(" << pt.x << ";" << pt.y << ")";
//	}
//}


class TestClass
{
public:
	TestClass() = default;
	~TestClass() = default;

	template<typename Derived>
	void showme(MatrixBase<Derived> &mat)
	{
//		Matrix<typename Derived::Scalar, Dynamic, Dynamic > ss = mat;
		//Map<Matrix<typename Derived::Scalar, Dynamic, Dynamic >> ss(mat.data(), mat.size(), 1);
		//cout <<"daat" << mat.data();
		cout << "size-->" << mat.size();
		//cout << "--------->\n" << ss << "\n\n";
		//(mat.data(), mat.rows(), mat.cols);
		//std::cout << ss << "\n";
		std::cout << mat.rows() << "X" << mat.cols() << "\n";
		std::cout << mat << "\n\n";
	}
};


//static plog::ConsoleAppender<plog::TxtFormatter> consoleAppender;
template<typename Derived>
//void TestMatrix(MatrixXd &mat)
void TestMatrix(MatrixBase<Derived> &mat)
{
	std::cout << mat << "\n";
}
int main()
{
	//example_plog();
	//TestTemp<double> x;
	////int xxx = 10;
	////template_test_func(xxx);
	////double yy = 20.0;
	////template_test_func(yy);
	//x.SetValue(10);
	//LOG_ERROR << "--------->" << x.Getalue() <<"----------------\n";
	//get_ticktock()->Start("Log시작");
	//get_ticktock()->ChangeUnit(CMeasureTick::MICRO);
	//
	//get_ticktock()->End("Log시작");

	Ctestdll test;
	MatrixXd x = MatrixXd::Random(5, 5);
	std::cout << "src :\n" << x << "\n\n";
	test.TestShow(x);
	//test.test_s(x);
	cout << "------>" << Ctestdll::dWeight << "\n";

	Body<Pose<float>> y;
	cout << "weight template static variable:" << y.dWeight <<"\n";
    return 0;
}

