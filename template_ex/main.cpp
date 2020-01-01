#include "testTemp.h"
#include <iostream>


template <typename Derived>
void test(myMatBase<Derived> & x)
{
	Derived::Scalar y = 10;
	std::cout << x;
	std::cout << "\n" << x.getRows() << "X" << x.getCols()  << "\n";
}
class myCalss
{
public:
	myCalss()
		:member(Yosi)
	{}
	enum TestMember {
		Yosi = 0,
		Grando,
		Season
	};

	enum TestMember member;
};
void main()
{
	myMatrix<int, 4, 2> x;
	test(x);
	//myCalss x, y;
	//std::cout << x.member;

}