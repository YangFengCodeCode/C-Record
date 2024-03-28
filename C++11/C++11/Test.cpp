#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<list>

//struct Point
//{
//	int _x;
//	int _y;
//};
//
//
//int main()
//{
//	int x1 = 1;
//	int x2{ 2 };
//	int array1[]{ 1, 2, 3, 4, 5 };
//	int array2[5]{ 0 };
//	Point p{ 1, 2 };
//
//	// C++11中列表初始化也可以适用于new表达式中
//	int* pa = new int[4] { 0 };
//	return 0;
//}


//class Date
//{
//public:
//	Date(int year, int month, int day)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//		cout << "Date(int year, int month, int day)" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1(2022, 1, 1); // old style
//
//	// C++11支持的列表初始化，这里会调用构造函数初始化
//	// 构造 + 拷贝构造 -> 优化，直接构造
//	Date d3 = { 2022, 1, 3 };
//	Date d2{ 2022, 1, 2 };
//
//	Date* darr1 = new Date[3]{ d1,d2,d3 };
//	Date* darr2 = new Date[3]{ { 2024, 3, 23 } ,{ 2024, 3, 23 } ,{ 2024, 3, 23 } };
//	
//	Date* darr3 = new Date(2023,3,34);
//	Date* darr4 = new Date{ 2023, 3, 34 };
//	return 0;
//}


//int main()
//{
//	vector<int> v = { 0, 2, 3, 4, 5 };
//	for (auto e : v)
//	{
//		cout << e << ' ';
//	}
//
//	cout << endl;
//	list<int> lt = { 0, 1, 2, 3, 100, 200 };
//	for (auto e : lt)
//	{
//		cout << e << ' ';
//	}
//
//	return 0;
//}


//int main()
//{
//	// the type of il is an initializer_list 
//	auto il = { 10, 20, 30 };
//	cout << typeid(il).name() << endl;
//	return 0;
//}


#include<map>

template <class T1, class T2>
struct pair
{
	// pair<const char*, const char*> kv3("sort", "排序");
	pair(const T1& t1, const T2& t2)
		:first(t1)
		, second(t2)
	{}

	// 	pair<const string, string> kv4(kv3);
	template<class U, class V>
	pair(const pair<U, V>& kv)
		: first(kv.first)
		, second(kv.second)
	{}

private:
	T1 first;
	T2 second;
};


namespace yf
{
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		vector(initializer_list<T> l)
		{
			_start = new T[l.size()];
			_finish = _start + l.size();
			_endofstorage = _start + l.size();
			iterator vit = _start;
			typename initializer_list<T>::iterator lit = l.begin();
			while (lit != l.end())
			{
				*vit++ = *lit++;
			}
		}

		vector<T>& operator=(initializer_list<T> l) {
			vector<T> tmp(l);
			std::swap(_start, tmp._start);
			std::swap(_finish, tmp._finish);
			std::swap(_endofstorage, tmp._endofstorage);
			return *this;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
}

//int main()
//{
//	vector<int> v = { 1,2,3,4 };
//
//	//  pair<string, string> kv1("sort", "排序");
//	//	pair<string, string> kv2("string", "字符串");
//	//	map<string, string> dict1 = { kv1, kv2 };
//
//	// 这里{"sort", "排序"}会先初始化构造一个pair对象
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//	for (auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//
//	cout << endl;
//	// 使用大括号对容器赋值
//	v = { 10, 20, 30 };
//	for (auto e : v)
//	{
//		cout << e << ' ';
//	}
//	return 0;
//}


//int main()
//{
//	int i = 10;
//	auto p = &i;
//	auto pf = strcpy;
//	cout << typeid(p).name() << endl;
//	cout << typeid(pf).name() << endl;
//	map<string, string> dict = { {"sort", "排序"}, {"insert", "插入"} };
//
//	//map<string, string>::iterator it = dict.begin();
//	auto it = dict.begin();
//	return 0;
//}



// decltype的一些使用使用场景
//template<class T1, class T2>
//void F(T1 t1, T2 t2)
//{
//	decltype(t1 * t2) ret;
//	cout << typeid(ret).name() << endl;
//}
//int main()
//{
//	const int x = 1;
//	double y = 2.2;
//	decltype(x * y) ret; // ret的类型是double
//	decltype(&x) p;      // p的类型是int*
//	cout << typeid(ret).name() << endl;
//	cout << typeid(p).name() << endl;
//	F(1, 'a');
//	return 0;
//}



//int& func2()
//{
//	static int x = 0;
//	return x;
//}
//
//int main()
//{
//	// 以下的p、b、c、*p, func2()返回值 都是左值
//	int* p = new int(0);
//	int b = 1;
//	const int c = 2;
//	
//	const int* ptr1 = &c;
//	int* ptr2 = &func2();
//
//	printf("%p %p\n", ptr1, ptr2);
//
//	// 左值引用就是给左值取别名
//	int*& rp = p;
//	int& rb = b;
//	const int& rc = c;
//	int& pvalue = *p;
//
//	return 0;
//}


//int func1()
//{
//	static int x = 0;
//	return x;
//}
//
//int main()
//{	
//	double x = 1.1, y = 2.2;
//	double& r1 = x;
//
//	// 以下几个都是常见的右值
//	10;
//	x + y;
//	func1();
//
//	// 以下几个都是对右值的右值引用
//	int&& rr1 = 10;
//	double&& rr2 = x + y;
//	double&& rr3 = fmin(x, y);
//
//	return 0;
//}


//int func1()
//{
//	static int x = 0;
//	return x;
//}
//
//int main()
//{
//	// 左值引用能否给右值取别名 不能
//	// 但是const左值引用可以
//	const int& r1 = func1();
//	const int& r2 = 10;
//
//	// 右值引用能否给左值取别名 不能
//	// 但是右值引用可以给move以后的左值可以
//	int x = 0;
//	int&& rr1 = move(x);
//
//	return 0;
//}



//int main()
//{
//	double x = 1.1, y = 2.2;
//	int&& rr1 = 10;
//	const double&& rr2 = x + y;
//	rr1 = 20;
//	printf("%p\n", &rr1);
//	//rr2 = 5.5;  // 报错
//	return 0;
//}

#include<string>
#include<assert.h>

namespace yf
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// 拷贝构造 -- 左值
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- 深拷贝" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// 移动构造 -- 右值(将亡值)
		string(string&& s)
		{
			cout << "string(string&& s) -- 移动拷贝" << endl;
			swap(s);
		}

		// 赋值重载
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // 不包含最后做标识的\0
	};


	yf::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		yf::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

int main()
{
	yf::string ret = yf::to_string(-1234);
	return 0;
}


//void func1(yf::string s)
//{}
//void func2(const bit::string& s)
//{}
//int main()
//{
//	yf::string s1("hello world");
//	// func1和func2的调用我们可以看到左值引用做参数减少了拷贝，提高效率的使用场景和价值
//	func1(s1);
//	func2(s1);
//	// string operator+=(char ch) 传值返回存在深拷贝
//	// string& operator+=(char ch) 传左值引用没有拷贝提高了效率
//	s1 += '!';
//	return 0;
//}