#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//// ����ģ��
//// ģ���ʵ����
//template<typename T>
//void Swap(T& left, T& right)
//{
//	T temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//
//	// �����ǲ���ͬһ������
//	Swap(a, b);
//	Swap(c, d);
//
//	cout << a <<' '<< b << endl;
//	cout << c <<' '<< d << endl;
//	return 0;
//}


// ģ������﷨ �����ƺ�����������������������βζ���ģ����������������
//template<class X, class Y>
//void func(const X& x, const Y& y)
//{
//	cout << x <<' '<< y << endl;
//}
//
//int main()
//{
//	//����ʵ����
//	//������������ �Ƴ�ģ����������� ���ɶ��ڵĺ���
//	func(1, 2);
//	func(1.1, 2.2);
//	func(1.1, 2);
//	return 0;
//}
//

//template<class T>
//T Add(const T& left, const T& right)
//{
//	return left + right;
//}
//int main()
//{
//	//����1 ǿ��ת��
//	cout << Add(1, (int)2.2) << endl;
//
//	//��ʾʵ����
//	cout << Add<int>(1, 2.2) << endl;
//	cout << Add<double>(1, 2.2) << endl;
//	return 0;
//}


//template<class T>
//T* f(int n)
//{
//	T* p = new T[n];
//	return p;
//}
//
//int main()
//{
//	//ֻ����ʾʵ����
//	double* p = f<double>(10);
//}


// ��ģ��
template<class T>
class Stack
{
public:
	Stack(int capacity = 4)
	{
		cout << "Stack(int capacity = 4)" << endl;

		_a = new T[capacity];
		_top = 0;
		_capacity = capacity;
	}

	~Stack()
	{
		cout << "~Stack()" << endl;

		delete[] _a;
		_a = nullptr;
		_top = 0;
		_capacity = 0;
	}
private:
	T* _a;
	int  _top;
	int  _capacity;
};

int main()
{
	// ��ʾʵ����
	Stack<int> st1;  // int
	Stack<double> st2;  // double

	//vector<int> v1;
	//vector<int> v2;

	//list<int> lt;
	//stack<double> st;

	return 0;
}



