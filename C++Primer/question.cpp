// CPPLearn.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>
//#include "Sales_item.h"
#include <string>
#include <exception>
#include <stdexcept>
#include <new>
#include <initializer_list>
#include <cstdlib>
using namespace std;

string(*func())[10];

int main()
{
	string (*a)[10];
	a = func();
	for (auto i = 0; i < 10; ++i)
		cout << a[0][i];
	return 0;
}

string(*func())[10]
{
	string (*a)[10]{{"123"}};
	return a;
}