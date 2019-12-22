#pragma once
// ���� ifdef ����� DLL���� ���������ϴ� �۾��� ���� �� �ִ� ��ũ�θ� ����� 
// ǥ�� ����Դϴ�. �� DLL�� ��� �ִ� ������ ��� ����ٿ� ���ǵ� _EXPORTS ��ȣ��
// �����ϵǸ�, �ٸ� ������Ʈ������ �� ��ȣ�� ������ �� �����ϴ�.
// �̷��� �ϸ� �ҽ� ���Ͽ� �� ������ ��� �ִ� �ٸ� ��� ������Ʈ������ 
// TESTDLL_API �Լ��� DLL���� �������� ������ ����, �� DLL��
// �� DLL�� �ش� ��ũ�η� ���ǵ� ��ȣ�� ���������� ������ ���ϴ�.
#include <Eigen/Eigen>
#ifdef TESTDLL_EXPORTS
#define TESTDLL_API __declspec(dllexport)
#else
#define TESTDLL_API __declspec(dllimport)
#endif

// �� Ŭ������ testdll.dll���� ������ ���Դϴ�.

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
	// TODO: ���⿡ �޼��带 �߰��մϴ�.
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