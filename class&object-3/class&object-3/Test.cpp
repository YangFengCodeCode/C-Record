#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;



//int _scount = 0;
//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A& t) { ++_scount; }
//	~A() {}
//private:
//};
//
//A func()
//{
//	A aa;
//	return aa;
//}
//
//int main()
//{
//	A aa;
//	func();
//	cout << _scount << endl;
//	return 0;
//}
// 
// 
//namespace yf
//{
//	int count = 0;
//}
//
//class A
//{
//public:
//	A() { ++yf::count; }
//	A(const A& t) { ++yf::count; }
//	~A() {}
//private:
//};
//
//A func()
//{
//	A aa;
//	return aa;//传值返回, 调用拷贝构造
//}
//
//int main()
//{
//	A aa;
//	func();
//	cout << yf::count << endl;
//	return 0;
//}



//class A
//{
//public:
//	A() { ++_scount; }
//	A(const A & t) { ++_scount; }
//	~A() { --_scount; }
//	int GetACount() { return _scount; }
//private:
//	//类里声明
//	static int _scount;
//};
//
////类外定义
//int A::_scount = 0;
//
//A func()
//{
//	A aa;
//	return aa;//传值返回, 调用拷贝构造
//}
//
//void TestA()
//{
//	func();
//	func();
//	func();
//	A aa;
//	cout << aa.GetACount() - 1 << endl;
//}
//
//int main()
//{
//	TestA();
//	return 0;
//}
//


//#include<iostream>
//using namespace std;
//
//
//class A
//{
//public:
//    A() { ++_scount; }
//    A(const A& t) { ++_scount; }
//    ~A() {}
//
//    //静态成员函数 特点--> 没有this指针
//    static int GetCount()
//    {
//        return _scount;
//    }
//private:
//    //类里声明
//    static int _scount;//属于整个类 属于这个类的所有对象 每次调用_scount的时候都会调用同一个_scount
//};
//
////类外定义
//int A::_scount = 0;
//
//A func()
//{
//	A aa;
//	return aa;//传值返回, 调用拷贝构造
//}
//
//void TestA()
//{
//    func();
//    
// //   //没有创建对象 访问不了成员函数
// //   //方法1 
// //   A aa;//有名对象
//	//cout << aa.GetCount()-1 << endl;//为了调用而创建的，所以要-1
//
// //   //方法2
// //   A(); // 这种写法叫做匿名对象，生命周期只在这一行
//	//cout << A().GetCount() - 1 << endl;
//
//    cout << A::GetCount() << endl;
//    cout << A().GetCount() << endl;
//
//}
//
//
//int main()
//{
//    TestA();
//    return 0;
//}


//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//ostream& operator<<(ostream& _cout, const Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	_cin >> d._month;
//	_cin >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//	return 0;
//}


//1 友元函数可访问类的私有和保护成员，但不是类的成员函数
//2 友元函数不能用const修饰
//3 友元函数可以在类定义的任何地方声明，不受类访问限定符限制
//4 一个函数可以是多个类的友元函数
//5 友元函数的调用与普通函数的调用原理相同


//class Sum
//{
//public:
//    Sum()
//    {
//        _ret += _i;
//        ++_i;
//    }
//
//    static int GetRet()
//    {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//
//int Sum::_i = 1;
//int Sum::_ret = 0;
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        Sum arr[n];
//
//        return Sum::GetRet();
//    }
//};

//class A
//{
//public:
//	A(int a, int b = 2)
//		:_a(a),
//		_b(b)
//	{}
//
//	/*A(int* p)
//	{}*/
//private:
//	int _a = 0;
//	int _b = 0;
//};
//
//
//int main()
//{
//	A aa1(1);
//	A aa2(2);
//	//强制类型转换
//	A aa3 = 3;
//	const A& ra = 3;
//}



//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//
//	Date d1(2023, 11, 2);
//	Date d2 = (2023, 11, 3); //逗号表达式--> 等价于 Date d2 = 3;
//	Date d3 = 2023;
//
//	// C++11
//	Date d4 = { 2023, 11, 2 };
//	const Date& d5 = { 2023, 11, 2 };
//
//	return 0;
//}



//class A
//{
//private:
//	int h;
//public:
//	// A和B关系
//	// B就是一个普通类，只是受A的类域和访问限定符限制,本质相当于被封装了一下
//	// B天生就是A的友元
//	class B 
//	{
//	public:
//		void func()
//		{
//			A aa;
//			// B天生就是A的友元
//			aa.h++;
//		}
//	private:
//		int _b;
//	};
//
//};
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	A aa;
//	A::B bb;
//
//	return 0;
//}




//class A
//{
//public:
//	A(int a = 1)
//		:_a(a)
//	{}
//private:
//	int _a = 0;
//	int _b = 0;
//};
// 
//int main()
//{
//	A aa1(1);   // 构造
//
//	// 一个已经存在的对象拷贝初始化另一个要创建的对象，就是拷贝构造
//	// 他们两是等价的
//	A aa2(aa1);  // 拷贝构造
//
//	A aa3 = aa1; // 拷贝构造 
//
//	// 两个已经存在的对象拷贝，赋值拷贝
//	aa2 = aa3;
//
//
//	return 0;
//}



// 扩展：一些构造时的优化，不同的编译器可能会不同（了解一下）
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;

		if (this != &aa)
		{
			_a = aa._a;
		}

		return *this;
	}

	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};

A func()
{
	A aa;
	return aa;
}
int main()
{
	A aa2;
	aa2 = func();
	return 0;
}
