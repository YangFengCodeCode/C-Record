#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<list>
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

		// 拷贝赋值
		// s2 = tmp
		string& operator=(const string& s)
		{
			cout << "string& operator=(const string& s) -- 深拷贝" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// 移动赋值
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- 移动拷贝" << endl;
			swap(s);

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
		size_t _capacity = 0; 
	};
}



void Fun(int& x) { cout << "左值引用" << endl; }
void Fun(const int& x) { cout << "const 左值引用" << endl; }
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }

template<typename T>
void PerfectForward(T&& t)
{
	Fun(forward<T>(t));
}

//int main()
//{
//	PerfectForward(10);           // 右值
//	int a;
//	PerfectForward(a);            // 左值
//	PerfectForward(std::move(a)); // 右值
//	const int b = 8;
//	PerfectForward(b);      // const 左值
//	PerfectForward(std::move(b)); // const 右值
//	return 0;
//}



template<class T>
struct ListNode
{
	ListNode* _next = nullptr;
	ListNode* _prev = nullptr;
	T _data;
};
template<class T>
class List
{
	typedef ListNode<T> Node;
public:
	List()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	void PushBack(T&& x)
	{
		//Insert(_head, x);
		Insert(_head, std::forward<T>(x));
	}
	void PushFront(T&& x)
	{
		//Insert(_head->_next, x);
		Insert(_head->_next, std::forward<T>(x));
	}
	void Insert(Node* pos, T&& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = std::forward<T>(x); // 关键位置
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x; // 关键位置
		// prev newnode pos
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
private:
	Node* _head;
};



//class Person
//{
//public:
//	Person(const char* name = "", int age = 0)
//		:_name(name)
//		, _age(age)
//	{}
//
//	Person(const Person& p)
//		:_name(p._name)
//		, _age(p._age)
//	{}
//
//	Person(Person&& p) = default;
//	Person& operator=(Person&& p) = default;
//
//
//	/*Person(const Person& p)
//	:_name(p._name)
//	,_age(p._age)
//	{}*/
//
//	/*Person& operator=(const Person& p)
//	{
//	if(this != &p)
//	{
//	_name = p._name;
//	_age = p._age;
//	}
//	return *this;
//	}*/
//
//	/*~Person()
//	{}*/
//
//private:
//	yf::string _name;
//	int _age;
//};
//
//int main()
//{
//	Person s1;
//	Person s2 = s1;// 拷贝构造
//	Person s3 = move(s1);// 移动构造
//	Person s4;
//	s4 = move(s2);//移动赋值
//	return 0;
//}



class Person
{
public:
	Person(const char* name = "", int age = 0)
		:_name(name)
		, _age(age)
	{}

	Person(const Person& p) = delete;

	Person(Person&& p) = default;
	Person& operator=(Person&& p) = default;

private:
	yf::string _name;
	int _age;
};
//
//int main()
//{
//	Person s1;
//	//Person s2 = s1; -->拷贝构造 已经删除
//	Person s3 = move(s1);// 移动构造
//	s1 = move(s3);//移动赋值
//	return 0;
//}




// Args是一个模板参数包，args是一个函数形参参数包
// 声明一个参数包Args...args，这个参数包中可以包含0到任意个模板参数。
//template <class ...Args>
//void ShowList(Args... args)
//{}



// 递归终止函数
template <class T>
void ShowList(const T& t)
{
	cout << t << endl;
}
// 展开函数
template <class T, class ...Args>
void ShowList(T value, Args... args)
{
	cout << value << " ";
	ShowList(args...);
}




#include"list.h"
int main()
{
	std::list<yf::string> lt1;

	yf::string s1("xxxx");
	lt1.push_back(s1);
	lt1.push_back(move(s1));
	cout << "=============================================" << endl;

	yf::string s2("xxxx");
	lt1.emplace_back(s2);
	lt1.emplace_back(move(s2));
	cout << "=============================================" << endl;

	lt1.push_back("xxxx");
	lt1.emplace_back("xxxx");
	cout << "=============================================" << endl;

	std::list<pair<yf::string, yf::string>> lt2;
	pair<yf::string, yf::string> kv1("xxxx", "yyyy");
	lt2.push_back(kv1);
	lt2.push_back(move(kv1));
	cout << "=============================================" << endl;

	pair<yf::string, yf::string> kv2("xxxx", "yyyy");
	lt2.emplace_back(kv2);
	lt2.emplace_back(move(kv2));
	cout << "=============================================" << endl;

	lt2.emplace_back("xxxx", "yyyy");
	cout << "=============================================" << endl;


	return 0;
}


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
//
//	Date(const Date& d)
//		:_year(d._year)
//		, _month(d._month)
//		, _day(d._day)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//private:
//	int _year = 1;
//	int _month = 1;
//	int _day = 1;
//};
//
//int main()
//{
//	std::list<Date> lt1;
//	lt1.push_back({ 2024,3,30 });
//
//	// 不支持
//	//lt1.emplace_back({ 2024,3,30 });
//
//	// 推荐
//	lt1.emplace_back(2024, 3, 30);
//
//	cout << endl;
//	Date d1(2023, 1, 1);
//	lt1.push_back(d1);
//	lt1.emplace_back(d1);
//
//	cout << endl;
//	lt1.push_back(Date(2023, 1, 1));
//	lt1.emplace_back(Date(2023, 1, 1));
//
//
//	return 0;
//}