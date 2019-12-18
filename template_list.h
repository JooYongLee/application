#pragma once
#include <iostream>

using namespace std;

/*
https://www.codeproject.com/Articles/48575/How-to-define-a-template-class-in-a-h-file-and-imp
*/

template<class T>
class TestTemp
{

public:

	TestTemp();
	void SetValue(T obj_i);
	T Getalue();

private:

	T m_Obj;
};

template<typename T>
void template_test_func(T x);
#include "template_ex.h"