#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
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


//// 1.�������������н���ǣ� A�����뱨�� B�����б��� C����������
//class A
//{
//public:
//    void PrintA()
//    {
//        cout << _a << endl;// this->_a  ���this ����nullptr
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
//// B ���б���(���ܰ汾��ͬ��vs �в��)


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
//	// ���ǳ�ʼ����
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
//	// ���ɺ������أ������޲ε��ô������壬����ͬʱ����
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
//	//// Date d1(); �������� ���ǲ��е�
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
//    // ����û���ʽ�����˹��캯��������������������
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
//    // ��Date���й��캯�����κ󣬴������ͨ�����룬��Ϊ������������һ���޲ε�Ĭ�Ϲ��캯��
//    // ��Date���й��캯���ſ����������ʧ�ܣ���Ϊһ����ʽ�����κι��캯��������������������
//    // �޲ι��캯�����ſ��󱨴�error C2512: ��Date��: û�к��ʵ�Ĭ�Ϲ��캯������
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
//			perror("malloc����ռ�ʧ��!!!");
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
//// ����ջʵ��һ������
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
//		// Date�ϸ���˵������Ҫд��������
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
			perror("malloc����ռ�ʧ��!!!");
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
	// Ĭ������������������Ϊ����������
	// �������ͳ�Ա��������
	// �Զ������ͳ�Ա��ȥ������������
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