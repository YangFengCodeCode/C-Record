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
//	// һ��Ҫ���ʹ�ã���������δ����
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
	// ���캯���Զ�����
	A aa1;

	// A* p2 = new A(1);

	A* p1 = (A*)operator new(sizeof(A));
	// ������ô��ʾ���ù��캯��
	//p1->A(1);
	// ���ǿ����ö�λnew��ʾ���ù��캯��
	new(p1)A(1);

	// ��������������ʾ����
	p1->~A();
	operator delete(p1);

	return 0;
}


