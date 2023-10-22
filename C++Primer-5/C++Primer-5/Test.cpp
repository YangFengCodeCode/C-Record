#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//	void Print()
//	{
//		cout << "Print()" << endl;
//	}
//private:
//	int _a;
//};
//int main()
//{
//	A* p = nullptr;
//	p->Print();
//	return 0;
//}


//// 1.下面程序编译运行结果是？ A、编译报错 B、运行崩溃 C、正常运行
//class A
//{
//public:
//    void PrintA()
//    {
//        cout << _a << endl;// this->_a  这个this 就是nullptr
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->PrintA();
//    return 0;
//}
//// B 运行崩溃(可能版本不同的vs 有差别)


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
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
//	// 忘记初始化？
//	Date d1;
//	d1.Print();
//
//	Date d2;
//	d2.Init(2022, 7, 6);
//	d2.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	// 够成函数重载，但是无参调用存在歧义，不能同时存在
//	Date()
//	{
//		_year = 1;
//		_month = 1;
//		_day = 1;
//	}
//
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	/*Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//void Init(int year, int month, int day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
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
//	Date d1;//
//	//// Date d1(); 函数声明 这是不行的
//	d1.Print();
//
//	Date d2(2023, 10, 19);
//	d2.Print();
//
//	/*Date d3(2023, 10);
//	d3.Print();*/
//
//	return 0;
//}



//class Date
//{
//public:
//    /*
//    // 如果用户显式定义了构造函数，编译器将不再生成
//    Date(int year, int month, int day)
//    {
//    _year = year;
//    _month = month;
//    _day = day;
//    }
//    */
//
//    void Print()
//    {
//        cout << _year << "-" << _month << "-" << _day << endl;
//    }
//
//private:
//    int _year;
//    int _month;
//    int _day;
//};
//
//int main()
//{
//    // 将Date类中构造函数屏蔽后，代码可以通过编译，因为编译器生成了一个无参的默认构造函数
//    // 将Date类中构造函数放开，代码编译失败，因为一旦显式定义任何构造函数，编译器将不再生成
//    // 无参构造函数，放开后报错：error C2512: “Date”: 没有合适的默认构造函数可用
//    Date d1;
//    d1.Print();
//    return 0;
//}


//class Date
//{
//private:
//    int _year = 1;
//    int _month = 1;
//    int _day = 1;
//};
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
//private:
//	int* _a;
//	int _capacity;
//	int _top;
//};
//
//// 两个栈实现一个队列
//class MyQueue
//{
//private:
//	Stack _pushst;
//	Stack _popst;
//	int _size = 1;
//};
//
//int main()
//{
//	Date d1;
//
//	Stack st1;
//
//	MyQueue mq;
//
//	return 0;
//}


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
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	~Date()
//	{
//		// Date严格来说，不需要写析构函数
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day ;
//};

class Stack
{
public:
	Stack(size_t capacity = 3)
	{
		cout << "Stack(size_t capacity = 3)" << endl;

		_a = (int*)malloc(sizeof(int) * capacity);
		if (nullptr == _a)
		{
			perror("malloc申请空间失败!!!");
		}

		_capacity = capacity;
		_top = 0;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		free(_a);
		_capacity = _top = 0;
		_a = nullptr;
	}

private:
	int* _a;
	int _capacity;
	int _top;
};

class MyQueue
{
	// 默认生成析构函数，行为跟构造类似
	// 内置类型成员不做处理
	// 自定义类型成员会去调用他的析构
private:
	Stack _pushst;
	Stack _popst;
	int _size = 1;
};

int main()
{
	//Stack st1;
	MyQueue mq;

	return 0;
}