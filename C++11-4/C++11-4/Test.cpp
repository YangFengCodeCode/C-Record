#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include <algorithm>
#include <functional>
#include<vector>


//int main()
//{
//	int array[] = { 4,1,8,5,3,7,0,9,2,6 };
//	// Ĭ�ϰ���С�ڱȽϣ��ų������������
//	std::sort(array, array + sizeof(array) / sizeof(array[0]));
//	for (auto e : array)
//	{
//		cout << e << " ";
//	}
//
//	cout << endl;
//	// �����Ҫ������Ҫ�ı�Ԫ�صıȽϹ���
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
//	string _name;  // ����
//	double _price; // �۸�
//	int _evaluate; // ����
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
//		return gl._price < gr._price;//����
//	}
//};
//
//struct ComparePriceGreater
//{
//	bool operator()(const Goods& gl, const Goods& gr)
//	{
//		return gl._price > gr._price;//����
//	}
//};
//
//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
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
//	// �ֲ���������������
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
	string _name;  // ����
	double _price; // �۸�
	int _evaluate; // ����

	Goods(const char* str, double price, int evaluate)
		:_name(str)
		, _price(price)
		, _evaluate(evaluate)
	{}
};

//int main()
//{
//	vector<Goods> v = { { "ƻ��", 2.1, 5 }, { "�㽶", 3, 4 }, { "����", 2.2,3 }, { "����", 1.5, 4 } };
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
//	// �˴��Ȳ�����ԭ�򣬵�lambda���ʽ�ײ�ʵ��ԭ����󣬴�Ҿ������
//    //f1 = f2;   ����ʧ��--->��ʾ�Ҳ���operator=()
//
//	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
//	auto f3(f2);
//	f3();
//
//	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
//	PF = f2;
//	PF();
//	return 0;
//}



//int main()
//{
//	int x = 1, y = 2;
//	// ÿ������һ��ֵ��x��
//	// ��ֵ��׽����׽�����ǵ�ǰ�Ķ���Ŀ���
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
//	// �����ò�׽
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
//	// ��ֵ��׽��ǰ������ж���
//	auto func1 = [=] {
//		return x + y * m - n;
//	};
//
//	cout << "x+y*m-n = " << func1() << endl;
//
//	// �����ò�׽��ǰ������ж���
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
//	// �����ò�׽��ǰ������ж���ĳЩ����ֵ��׽
//	auto func3 = [&, n] {
//		x++;
//		m++;
//		// n++;���� n��const���ε� 
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



////����ģ��
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
//	// ������
//	cout << useF(f, 11.11) << endl;
//
//	// ��������
//	cout << useF(Functor(), 11.11) << endl;
//
//	// lamber���ʽ
//	cout << useF([](double d)->double { return d / 4; }, 11.11) << endl;
//
//	return 0;
//}



#include <functional>
////����ģ��
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
//	// ����ָ��
//	function<double(double)> fc1 = f;
//	fc1(11.11);
//	cout << useF(fc1, 11.11) << endl;
//
//	// ��������
//	function<double(double)> fc2 = Functor();
//	fc2(11.11);
//	cout << useF(fc2, 11.11) << endl;
//
//	// lambda���ʽ
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
//	// ��ͨ����
//	function<int(int, int)> fc1 = f;
//	cout << fc1(1, 1) << endl;
//
//	// ��̬��Ա����
//	function<int(int, int)> fc2 = &Plus::plusi;
//	cout << fc2(1, 1) << endl;
//
//	// �Ǿ�̬��Ա����
//	// �Ǿ�̬��Ա������Ҫ�����ָ����߶���ȥ���е���
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
//	// ��������˳���˽�һ�£����岻��
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
	
	// ���������ĸ���
	// ĳЩ��������
	function<double(double, double)> fc4 = bind(&Plus::plusd, Plus(), placeholders::_1, placeholders::_2);
	cout << fc4(2, 3) << endl;

	function<double(double)> fc5 = bind(&Plus::plusd, Plus(), placeholders::_1, 20);
	cout << fc5(2) << endl;

	return 0;
}