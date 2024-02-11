using namespace std;
#include<iostream>


//#define N 20
//
//template<class T>
//class Stack
//{
//private:
//	T _a[N];
//	int _top;
//};
//
//int main()
//{
//	Stack<int> st1;  // 10
//	Stack<int> st2;  // 20
//
//	return 0;
//}
////这样的做法会使st1空间浪费了


// 非类型模板参数，只能是整形常量
//template<class T, size_t N>
//class Stack
//{
//private:
//	T _a[N];
//	int _top;
//};
//
//int main()
//{
//	Stack<int, 10> st1;  // 10
//	Stack<int, 20> st2;  // 20
//
//
//	return 0;
//}


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	bool operator<(const Date& d)const
	{
		return (_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day);
	}
	bool operator>(const Date& d)const
	{
		return (_year > d._year) ||
			(_year == d._year && _month > d._month) ||
			(_year == d._year && _month == d._month && _day > d._day);
	}

	friend ostream& operator<<(ostream& _cout, const Date& d);
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

//
//// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl; // 可以比较，结果正确
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl; // 可以比较，结果正确
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 可以比较，结果错误
//	return 0;
//}



// 函数模板 -- 参数匹配
//template<class T>
//bool Less(T left, T right)
//{
//	return left < right;
//}
//
//// 对Less函数模板进行特化
//template<>
//bool Less<Date*>(Date* left, Date* right)
//{
//	return *left < *right;
//}
//int main()
//{
//	cout << Less(1, 2) << endl;
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 8);
//	cout << Less(d1, d2) << endl;
//	Date* p1 = &d1;
//	Date* p2 = &d2;
//	cout << Less(p1, p2) << endl; // 调用特化之后的版本，而不走模板生成了
//	return 0;
//}

//bool Less(Date* left, Date* right)
//{
//	return *left < *right;
//}



//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
//
//template<>
//class Data<int, char>
//{
//public:
//	Data() { cout << "Data<int, char>" << endl; }
//private:
//	int _d1;
//	char _d2;
//};
//
//// 偏特化1：特化部分参数
//template <class T1>
//class Data<T1, int>
//{
//public:
//	Data() { cout << "Data<T1, int>" << endl; }
//private:
//	T1 _d1;
//	int _d2;
//};
//
//void TestVector()
//{
//	Data<int, int> d1;
//	Data<int, char> d2;
//	Data<int, int> d3;
//}
//
//int main()
//{
//	TestVector();
//	return 0;
//}


//template<class T1, class T2>
//class Data
//{
//public:
//	Data() { cout << "Data<T1, T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
// 
////两个参数偏特化为指针类型
//template <typename T1, typename T2>
//class Data<T1*, T2*>
//{
//public:
//	Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//T1 _d1;
//T2 _d2;
//};
//
//
////两个参数偏特化为引用类型
//template <typename T1, typename T2>
//class Data<T1&, T2&>
//{
//public:
//	Data(const T1& d1, const T2& d2)
//		: _d1(d1)
//		, _d2(d2)
//	{
//		cout << "Data<T1&, T2&>" << endl;
//	}
//
//private:
//	const T1& _d1;
//	const T2& _d2;
//};
//void test2()
//{
//	Data<double, int> d1; // 调用特化的int版本
//	Data<int, double> d2; // 调用基础的模板 
//	Data<int*, int*> d3; // 调用特化的指针版本
//	Data<int&, int&> d4(1, 2); // 调用特化的指针版本
//}
//
//int main()
//{
//	test2();
//	return 0;
//}



//#include<vector>
//#include <algorithm>
//template<class T>
//struct Less
//{
//	bool operator()(const T& x, const T& y) const
//	{
//		return x < y;
//	}
//};
//
//// 对Less类模板按照指针方式特化
//template<>
//struct Less<Date*>
//{
//	bool operator()(Date* x, Date* y) const
//	{
//		return *x < *y;
//	}
//};
//
//int main()
//{
//	Date d1(2022, 7, 7);
//	Date d2(2022, 7, 6);
//	Date d3(2022, 7, 8);
//	vector<Date> v1;
//	v1.push_back(d1);
//	v1.push_back(d2);
//	v1.push_back(d3);
//	// 可以直接排序，结果是日期升序
//	sort(v1.begin(), v1.end(), Less<Date>());
//
//
//	vector<Date*> v2;
//	v2.push_back(&d1);
//	v2.push_back(&d2);
//	v2.push_back(&d3);
//	// 可以直接排序，结果错误日期还不是升序，而v2中放的地址是升序
//	// 此处需要在排序过程中，让sort比较v2中存放地址指向的日期对象
//	// 但是走Less模板，sort在排序时实际比较的是v2中指针的地址，因此无法达到预期
//	sort(v2.begin(), v2.end(), Less<Date*>());
//	return 0;
//}


#include"a.h"

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(1.0, 2.0) << endl;

	return 0;
}


