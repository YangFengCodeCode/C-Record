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
//	return aa;//��ֵ����, ���ÿ�������
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
//	//��������
//	static int _scount;
//};
//
////���ⶨ��
//int A::_scount = 0;
//
//A func()
//{
//	A aa;
//	return aa;//��ֵ����, ���ÿ�������
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
//    //��̬��Ա���� �ص�--> û��thisָ��
//    static int GetCount()
//    {
//        return _scount;
//    }
//private:
//    //��������
//    static int _scount;//���������� �������������ж��� ÿ�ε���_scount��ʱ�򶼻����ͬһ��_scount
//};
//
////���ⶨ��
//int A::_scount = 0;
//
//A func()
//{
//	A aa;
//	return aa;//��ֵ����, ���ÿ�������
//}
//
//void TestA()
//{
//    func();
//    
// //   //û�д������� ���ʲ��˳�Ա����
// //   //����1 
// //   A aa;//��������
//	//cout << aa.GetCount()-1 << endl;//Ϊ�˵��ö������ģ�����Ҫ-1
//
// //   //����2
// //   A(); // ����д����������������������ֻ����һ��
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


//1 ��Ԫ�����ɷ������˽�кͱ�����Ա����������ĳ�Ա����
//2 ��Ԫ����������const����
//3 ��Ԫ�����������ඨ����κεط�����������������޶�������
//4 һ�����������Ƕ�������Ԫ����
//5 ��Ԫ�����ĵ�������ͨ�����ĵ���ԭ����ͬ


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
//	//ǿ������ת��
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
//	Date d2 = (2023, 11, 3); //���ű��ʽ--> �ȼ��� Date d2 = 3;
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
//	// A��B��ϵ
//	// B����һ����ͨ�ֻ࣬����A������ͷ����޶�������,�����൱�ڱ���װ��һ��
//	// B��������A����Ԫ
//	class B 
//	{
//	public:
//		void func()
//		{
//			A aa;
//			// B��������A����Ԫ
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
//	A aa1(1);   // ����
//
//	// һ���Ѿ����ڵĶ��󿽱���ʼ����һ��Ҫ�����Ķ��󣬾��ǿ�������
//	// �������ǵȼ۵�
//	A aa2(aa1);  // ��������
//
//	A aa3 = aa1; // �������� 
//
//	// �����Ѿ����ڵĶ��󿽱�����ֵ����
//	aa2 = aa3;
//
//
//	return 0;
//}



// ��չ��һЩ����ʱ���Ż�����ͬ�ı��������ܻ᲻ͬ���˽�һ�£�
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
