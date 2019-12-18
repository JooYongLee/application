#include "stdafx.h"
#include "template_list.h"



template <class T>
TestTemp<T>::TestTemp()
{
}
template <class T>
void TestTemp<T>::SetValue(T obj_i)
{
	m_Obj = obj_i;
}
template <class T>

T TestTemp<T>::Getalue()
{
	return m_Obj;
}

template<typename T>
void template_test_func(T x)
{
	T y = x;
	std::cout << y << "\n";
}

