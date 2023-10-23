#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_capacity = _top = 0;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//
////值拷贝浅拷贝
//void func1(Date d)
//{
//	d.Print();
//}
//
//void func2(Stack st)
//{
//	//...
//}
//
//int main()
//{
//	Date d1(2023, 10, 22);
//	func1(d1);
//
//	Stack st1;
//	func2(st1);
//
//	return 0;
//}


//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // Date(const Date& d)--> 错误写法：编译报错，会引发无穷递归
//    Date(const Date& d)   
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1;
//    Date d2(d1);//把d1拷贝给d1
//    return 0;
//}



//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    // Date(const Date d)--> 错误写法：编译报错，会引发无穷递归
//    Date(const Date& d) 
//    {
//        _year = d._year;
//        _month = d._month;
//        _day = d._day;
//    }
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//int main()
//{
//    Date d1;
//    Date d2(d1);//将d1拷贝给d2
//    return 0;
//}




//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//
//		_a = (int*)malloc(sizeof(int) * capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//		}
//
//		_capacity = capacity;
//		_top = 0;
//	}
//
//	// Stack st2(st1);
//	Stack(const Stack& stt)
//	{
//		cout << "	Stack(Stack& stt)" << endl;
//		// 深拷贝
//		_a = (int*)malloc(sizeof(int) * stt._capacity);
//		if (_a == nullptr)
//		{
//			perror("malloc fail");
//			exit(-1);
//		}
//		memcpy(_a, stt._a, sizeof(int) * stt._top);
//		_top = stt._top;
//		_capacity = stt._capacity;
//	}
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		free(_a);
//		_capacity = _top = 0;
//		_a = nullptr;
//	}
//
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//class MyQueue
//{
//	Stack _pushst;
//	Stack _popst;
//	int _size = 0;
//};
//
//
//
//void func2(Stack st)
//{
//	//...
//}
//
//
//int main()
//{
//	// Date 和 MyQueue 默认生成拷贝就可以用
//	// 1、内置类型成员完成值拷贝
//	// 2、自定义类型成员调用这个成员的拷贝构造
//	// Stack需要自己写拷贝构造，完成深拷贝。
//	// 顺序表、链表、二叉树等等的类，都需要深拷贝
//
//	Stack st1;
//	func2(st1);
//	Stack st2(st1);
//
//	MyQueue q1;
//	MyQueue q2(q1);
//
//	return 0;
//}




//class Date
//{
//public:
//    Date(int year = 1900, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    bool operator==(const Date& dd2)// this 指向d1  dd2是d2的别名
//    {
//        return _year == dd2._year//如果成员变量不是共有的那就访问不到了
//            && _month == dd2._month
//            && _day == dd2._day;
//    }
//    private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//
//void Test2()
//{
//    Date d1(2018, 9, 26);
//    Date d2(2018, 9, 27);
//    /*cout << operator>(d1, d2) << endl;
//      cout << operator==(d1, d2) << endl;*/
//    cout << (d1 == d2) << endl;
//}
//
//int main()
//{
//    Test2();
//    return 0;
//}

#include<assert.h>



//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	//int GetYear();
//
//	bool operator==(const Date& y)
//	{
//		return _year == y._year
//			&& _month == y._month
//			&& _day == y._day;
//	}
//
//	bool operator>(const Date& y)
//	{
//		if (_year > y._year)
//		{
//			return true;
//		}
//		else if (_year == y._year && _month > y._month)
//		{
//			return true;
//		}
//		else if (_year == y._year && _month == y._month && _day > y._day)
//		{
//			return true;
//		}
//
//		return false;
//	}
//
//	// d1 - d2
//	int operator-(const Date& d)
//	{
//		// ...
//		return 0;
//	}
//
//	int GetMonthDay(int year, int month)
//	{
//		assert(year >= 1 && month >= 1 && month <= 12);
//
//		int monthArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31 };
//
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//			return 29;
//
//		return monthArray[month];
//	}
//
//	// d1 += 100
//	Date& operator+=(int day)
//	{
//		_day += day;
//		while (_day > GetMonthDay(_year, _month))
//		{
//			_day -= GetMonthDay(_year, _month);
//
//			++_month;
//
//			if (_month == 13)
//			{
//				_year++;
//				_month = 1;
//			}
//		}
//
//		return *this;
//	}
//
//	// d1 + 50
//	/*Date operator+(int day)
//	{
//		Date tmp(*this);
//
//		tmp._day += day;
//		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
//		{
//			tmp._day -= GetMonthDay(tmp._year, tmp._month);
//
//			++tmp._month;
//
//			if (tmp._month == 13)
//			{
//				tmp._year++;
//				tmp._month = 1;
//			}
//		}
//
//		return tmp;
//	}*/
//
//	Date operator+(int day)
//	{
//		Date tmp(*this);
//		tmp += day;
//
//		return tmp;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2023, 10, 22);
//
//	bool ret1 = d1 > d2;  // d1.operator>(d2) -> d1.operator>(&d1, d2)
//	bool ret2 = d1 == d2; // d1.operator==(d2) -> d1.operator==(&d1, d2)
//
//	Date ret3 = d1 - d2;
//	ret3.Print();
//
//	d2 += 50;
//	d2.Print();
//
//	Date ret4 = d1 + 50;
//	d1.Print();
//	ret4.Print();
//
//	return 0;
//}



class Date

{

public:

	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{

		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		int day = days[month];

		if (month == 2

			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))

		{

			day += 1;

		}

		return day;

	}



	// 全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1)

	{

		if (year < 1900

			|| month < 1 || month > 12

			|| day < 1 || day > GetMonthDay(year, month))

		{

			cout << "非法日期" << endl;

		}



		_year = year;

		_month = month;

		_day = day;

	}



  // 拷贝构造函数
  // d2(d1)

	Date(const Date& d)

	{

		this->_year = d._year;

		_month = d._month;

		_day = d._day;

	}



  // 赋值运算符重载
  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		if (this != &d)
		{

			this->_year = d._year;

			this->_month = d._month;

			this->_day = d._day;
		}
		return *this;
	}



	// 析构函数
	~Date()
	{

		// 清理工作

	}


    void Print()

	{

		cout << _year << "-" << _month << "-" << _day << endl;

	}


  // 日期+=天数

  // d1 += 10

  // d1 += -10

	Date& operator+=(int day)

	{

		if (day < 0)

		{

			return *this -= -day;

		}

		_day += day;

		while (_day > GetMonthDay(_year, _month))
		{
        	_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month == 13)
			{
				_year++;
				_month = 1;
			}
		}
		return *this;

	}

  // 日期+天数
  // d + 10

	Date operator+(int day)
	{
		Date ret(*this);
		ret += day;
		return ret;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}



	// 日期-=天数
    // d -= 100
    // d -= -100
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}

		return *this;
	}


  // 前置++
  // ++d -> d.operator++(&d)
	Date& operator++()
	{
		*this += 1;
		return *this;
	}


  // 后置++
  // d++ -> d.operator++(&d, 0)

	Date operator++(int)
	{
		Date ret(*this);
		*this += 1;
		return ret;
	}



	// 后置--
	Date operator--(int)
	{
	    Date ret(*this);
		*this -= 1;
		return ret;
	}



	// 前置--
	Date& operator--()
	{
		*this -= 1;
	    return *this;
	}



	// d1 > d2
	// >运算符重载

	bool operator>(const Date& d)
	{
		if (_year > d._year)
		{
			return true;
		}

		else if (_year == d._year)
		{
			if (_month > d._month)
			{
				return true;
			}
			else if (_month == d._month)
			{
				if (_day > d._day)
				{
					return true;
				}
			}
		}

	    return false;
	}



	// ==运算符重载

	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}



	// 下面复用上面两个的实现
	// >=运算符重载

	bool operator >= (const Date& d)
	{
		return *this > d || *this == d;
	}



	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}


	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}



	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}


	// d1 - d2
    // 日期-日期 返回天数
	int operator-(const Date& d)
	{
		int flag = 1;
		Date max = *this;
		Date min = d;
		if (*this < d)
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int day = 0;
		while (min < max)
		{
			++(min);
			++day;
		}
		return day * flag;
	}

private:
	int _year;
	int _month;
	int _day;

};