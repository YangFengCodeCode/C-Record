#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;


class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_a = new int[capacity];
		_top = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		delete[] _a;
		_a = nullptr;
		_top = 0;
		_capacity = 0;
	}
private:
	int* _a;
	int  _top;
	int  _capacity;
};


//class A
//{
//public:
//	A(int a = 0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//
//private:
//	int _a;
//};


//int main()
//{
//	A* p4 = new A[10];
//	delete p4;
//	return 0;
//}
//int main()
//{
//	
//	Stack* p1 = new Stack;
//	delete p1;
//
//	Stack* p2 = (Stack*)operator new(sizeof(Stack));
//	operator delete(p2);
//
//	Stack* p3 = new Stack[10];
//	delete[] p3;
//	// new/delete  new[]/delete[]  malloc/free
//	// 一定要配对使用，否则结果是未定义
//
//	return 0;
//}



class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}

	~A()
	{
		cout << "~A():" << this << endl;
	}

private:
	int _a;
};


int main()
{
	// 构造函数自动调用
	A aa1;

	// A* p2 = new A(1);

	A* p1 = (A*)operator new(sizeof(A));
	// 不能这么显示调用构造函数
	//p1->A(1);
	// 但是可以用定位new显示调用构造函数
	new(p1)A(1);

	// 析构函数可以显示调用
	p1->~A();
	operator delete(p1);

	return 0;
}


