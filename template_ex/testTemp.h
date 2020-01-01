#pragma once

#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
template<typename T> struct myTraits;
template<typename _Scalar, int w, int h>
class myMatrix;

//template<typename _Scalar, int w, int h>
//struct myTraits<myMatrix<_Scalar, w, h>>
//{
//public:
//	enum
//	{
//		CompileWidth = w,
//		CompileHeight = h
//	};
//	//typedef _Scalar Scalar;
//};

template<typename Derived> class myMatBase;
//template<typename _Scalar, int w, int h>
//class myMatBase;

template<typename _Scalar, int w, int h>
class myMatrix : public myMatBase<myMatrix<_Scalar, w, h>>
{
public:
	//typedef _Scalar Scalar;
	//enum
	//{
	//	CompileWidth = myTraits< myMatrix<_Scalar, w, h>::CompileWidth

	//};

	myMatrix()
		:myMatBase<myMatrix<_Scalar, w, h>>()
	{
		ptr = new _Scalar[w*h];
		std::iota(ptr, ptr + w*h, 0);
	}
	

	template<typename Derived>
	friend std::ostream& operator<<(std::ostream &out, myMatBase<Derived> &rhs)
	{
		std::vector<Derived::Scalar> x = { 0, 1, 2 };
		//std::cout << x << "\n";
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j <w; j++)
			{
				out << rhs.ptr[i*w + j] << ",";
			}
			out << "\n";
		}
		return out;
	}
};

template<typename _Scalar, int w, int h>
class myMatBase<myMatrix<_Scalar, w, h>>
{
public:
	typedef _Scalar Scalar;
	enum
	{
		CompileWidth = w,
		CompileHeight = h
	};
	_Scalar *ptr;
	int getRows() { return CompileHeight; }
	int getCols() { return CompileWidth; }
};

template<typename Derived> 
class myMatBase
{
public:
	int getRows() { return CompileHeight; }
	int getCols() { return CompileWidth; }
};
//template<typename _Scalar, int w, int h> 
//class myMatBase
//{
//	//myMatBase()
//};

/** The type used to identify a matrix expression */
//struct myMatrixXpr {};
//template<typename Derived> class myMatrixBase;
//
//template<typename Derived>
//struct myxpr_base<Derived>
//{
//	typedef myxpr_base<Derived> type;
//};

//
//template<typename Derived>
//class myMatBase : public myxpr_base<Derived>::type
//{
//
//};