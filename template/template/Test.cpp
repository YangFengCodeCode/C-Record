#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//// 函数模板
//// 模板的实例化
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	// 调用是不是同一个函数
//	Swap(a, b);
//	Swap(c, d);
//
//	cout << a <<' '<< b << endl;
//	cout << c <<' '<< d << endl;
//	return 0;
//}


// 模板参数语法 很类似函数参数，函数参数定义的形参对象，模板参数定义的是类型
//template<class X, class Y>
//void func(const X& x, const Y& y)
//{
//	cout << x <<' '<< y << endl;
//}
//
//int main()
//{
//	//推演实例化
//	//函数参数传递 推出模板参数的类型 生成对于的函数
//	func(1, 2);
//	func(1.1, 2.2);
//	func(1.1, 2);
//	return 0;
//}
//

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	//方法1 强制转换
//	cout << Add(1, (int)2.2) << endl;
//
//	//显示实例化
//	cout << Add<int>(1, 2.2) << endl;
//	cout << Add<double>(1, 2.2) << endl;
//	return 0;
//}


//template<class T>
//T* f(int n)
//{
//	T* p = new T[n];
//	return p;
//}
//
//int main()
//{
//	//只能显示实例化
//	double* p = f<double>(10);
//}


// 类模板
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_a = new T[capacity];
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
	T* _a;
	int  _top;
	int  _capacity;
};

int main()
{
	// 显示实例化
	Stack<int> st1;  // int
	Stack<double> st2;  // double

	//vector<int> v1;
	//vector<int> v2;

	//list<int> lt;
	//stack<double> st;

	return 0;
}



