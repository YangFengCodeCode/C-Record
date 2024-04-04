#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>


//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// 默认按照小于比较，排出来结果是升序
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	// 如果需要降序，需要改变元素的比较规则
//	std::sort(array, array + sizeof(array) / sizeof(array[0]), greater<int>());
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}



//
//struct Goods
//{
//	string _name;  // 名字
//	double _price; // 价格
//	int _evaluate; // 评价
//
//	Goods(const char* str, double price, int evaluate)
//		:_name(str)
//		, _price(price)
//		, _evaluate(evaluate)
//	{}
//};
//
//struct ComparePriceLess
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price < gr._price;//升序
//	}
//};
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;//降序
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), ComparePriceLess());
//	for (auto e : v)
//	{
//		cout << e._price << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end(), ComparePriceGreater());
//	for (auto e : v)
//	{
//		cout << e._price << " ";
//	}
//}


//int main()
//{
//	// 局部的匿名函数对象
//	//auto add = [](int a, int b)->int {return a + b; };
//	auto add = [](int a, int b) {return a + b; };
//	cout << add(1, 2) << endl;
//
//	auto swap1 = [](int& a, int& b){
//		int tmp = a;
//		a = b;
//		b = tmp;
//	};
//
//	int x = 1, y = 2;
//	swap1(x, y);
//	cout << "x: " << x << "  y: " << y << endl;
//
//	auto func1 = [] {
//		cout << "hello world" << endl;
//	};
//
//	func1();
//
//	return 0;
//}


struct Goods
{
	string _name;  // 名字
	double _price; // 价格
	int _evaluate; // 评价

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

//int main()
//{
//	vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2,3 }, { "菠萝", 1.5, 4 } };
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price < g2._price;} );
//	for (auto e : v)
//	{
//		cout << e._price << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._price > g2._price; });
//	for (auto e : v)
//	{
//		cout << e._price << " ";
//	}
//	cout << endl;
//
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate < g2._evaluate;});
//	sort(v.begin(), v.end(), [](const Goods& g1, const Goods& g2) {return g1._evaluate > g2._evaluate;});
//}



//void (*PF)();
//int main()
//{
//	auto f1 = [] {cout << "hello world" << endl; };
//	auto f2 = [] {cout << "hello world" << endl; };
//
//	// 此处先不解释原因，等lambda表达式底层实现原理看完后，大家就清楚了
//    //f1 = f2;   编译失败--->提示找不到operator=()
//
//	// 允许使用一个lambda表达式拷贝构造一个新的副本
//	auto f3(f2);
//	f3();
//
//	// 可以将lambda表达式赋值给相同类型的函数指针
//	PF = f2;
//	PF();
//	return 0;
//}



//int main()
//{
//	int x = 1, y = 2;
//	// 每次输入一个值跟x换
//	// 传值捕捉，捕捉到的是当前的对象的拷贝
//	auto swap1 = [x, y]()mutable {
//		int tmp = x;
//		cin >> x;
//		y = tmp;
//	};
//
//	swap1();
//	cout << "x: " << x << "  y: " << y << endl;
//
//	return 0;
//}


//int main()
//{
//	int x = 1, y = 2;
//
//	// 传引用捕捉
//	auto swap1 = [&x, &y]{
//		int tmp = x;
//		x = y;
//		y = tmp;
//	};
//
//	swap1();
//	cout <<"x: "<< x << " y: " << y << endl;
//
//	int m = 3, n = 4;
//	// 传值捕捉当前域的所有对象
//	auto func1 = [=] {
//		return x + y * m - n;
//	};
//
//	cout << "x+y*m-n = " << func1() << endl;
//
//	// 传引用捕捉当前域的所有对象
//	auto func2 = [&] {
//		x++;
//		m++;
//		return x + y * m - n;
//	};
//
//	cout << "x++, m++, x + y * m - n = " << func2() << endl;
//	cout << "x: " << x << endl;
//	cout << "m: " << m << endl;
//
//	// 传引用捕捉当前域的所有对象，某些对象传值捕捉
//	auto func3 = [&, n] {
//		x++;
//		m++;
//		// n++;不行 n是const修饰的 
//		return x + y * m - n;
//	};
//
//	cout << "x++, m++, x + y * m - n = " << func3() << endl;
//
//	cout << "x: " << x << endl;
//	cout << "m: " << m << endl;
//
//	return 0;
//}



////函数模板
//template<class F, class T>
//
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};

//int main()
//{
//	// 函数名
//	cout << useF(f, 11.11) << endl;
//
//	// 函数对象
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lamber表达式
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	return 0;
//}



#include <functional>
////函数模板
//template<class F, class T>
//
//T useF(F f, T x)
//{
//	static int count = 0;
//	cout << "count:" << ++count << endl;
//	cout << "count:" << &count << endl;
//
//	return f(x);
//}
//
//double f(double i)
//{
//	return i / 2;
//}
//
//struct Functor
//{
//	double operator()(double d)
//	{
//		return d / 3;
//	}
//};
//
//int main()
//{
//	// 函数指针
//	function<double(double)> fc1 = f;
//	fc1(11.11);
//	cout << useF(fc1, 11.11) << endl;
//
//	// 函数对象
//	function<double(double)> fc2 = Functor();
//	fc2(11.11);
//	cout << useF(fc2, 11.11) << endl;
//
//	// lambda表达式
//	function<double(double)> fc3 = [](double d)->double { return d / 4; };
//	fc3(11.11);
//	cout << useF(fc3, 11.11) << endl;
//
//	return 0;
//}

//
//int f(int a, int b)
//{
//	return a + b;
//}
//
//class Plus
//{
//public:
//	static int plusi(int a, int b)
//	{
//		return a + b;
//	}
//
//	double plusd(double a, double b)
//	{
//		return a + b;
//	}
//};
//
//int main()
//{
//	// 普通函数
//	function<int(int, int)> fc1 = f;
//	cout << fc1(1, 1) << endl;
//
//	// 静态成员函数
//	function<int(int, int)> fc2 = &Plus::plusi;
//	cout << fc2(1, 1) << endl;
//
//	// 非静态成员函数
//	// 非静态成员函数需要对象的指针或者对象去进行调用
//	/*Plus plus;
//	function<double(Plus*, double, double)> fc3 = &Plus::plusd;
//	cout << fc3(&plus, 1, 1) << endl;*/
//
//	function<double(Plus, double, double)> fc3 = &Plus::plusd;
//	cout << fc3(Plus(), 1, 1) << endl;
//
//	return 0;
//}

//
//int Sub(int a, int b)
//{
//	return a - b;
//}
//
//int main()
//{
//	// 调整参数顺序，了解一下，意义不大
//	int x = 10, y = 20;
//	cout << Sub(x, y) << endl;
//
//	auto f1 = bind(Sub, placeholders::_2, placeholders::_1);
//	cout << f1(x, y) << endl;
//
//	return 0;
//}



class Plus
{
public:
	static int plusi(int a, int b)
	{
		return a + b;
	}

	double plusd(double a, double b)
	{
		return a - b;
	}
};

int main()
{
	
	// 调整参数的个数
	// 某些参数绑死
	function<double(double, double)> fc4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	cout << fc4(2, 3) << endl;

	function<double(double)> fc5 = bind(&Plus::plusd, Plus(), placeholders::_1, 20);
	cout << fc5(2) << endl;

	return 0;
}