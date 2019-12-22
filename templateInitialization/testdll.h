#pragma once
// 다음 ifdef 블록은 DLL에서 내보내기하는 작업을 쉽게 해 주는 매크로를 만드는 
// 표준 방식입니다. 이 DLL에 들어 있는 파일은 모두 명령줄에 정의된 _EXPORTS 기호로
// 컴파일되며, 다른 프로젝트에서는 이 기호를 정의할 수 없습니다.
// 이렇게 하면 소스 파일에 이 파일이 들어 있는 다른 모든 프로젝트에서는 
// TESTDLL_API 함수를 DLL에서 가져오는 것으로 보고, 이 DLL은
// 이 DLL은 해당 매크로로 정의된 기호가 내보내지는 것으로 봅니다.
#include <Eigen/Eigen>
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

// 이 클래스는 testdll.dll에서 내보낸 것입니다.

template<typename T>
class TESTDLL_API Pose
{
public:
	Pose() = default;
	Pose(T _x, T _y)
		:x(_x),
		y(_y) {}
	T x;
	T y;
};

template<class PointDerive>
class TESTDLL_API Body 
{
public:
	Body() = default;
	~Body() = default;
	void show();
	static double dWeight;
};
class TESTDLL_API Ctestdll 
{
public:
	Ctestdll(void)		
	{
		mX = new Eigen::MatrixXd;
		mY = new Eigen::MatrixXi;
	}
	~Ctestdll()
	{
		delete mX;
		delete mY;
	}
	void test_s(Eigen::MatrixXd &x);
	template<typename Derived>
	void TestShow(Eigen::PlainObjectBase<Derived> &mat);
	// TODO: 여기에 메서드를 추가합니다.
	Eigen::MatrixXd *mX;
	Eigen::MatrixXi *mY;
	static double dWeight;
};


//template void foo::bar<double>(const double);
extern TESTDLL_API int ntestdll;

TESTDLL_API int fntestdll(void);

#ifdef TESTDLL_EXPORTS
#include "../testdll/exam.h"
#endif 