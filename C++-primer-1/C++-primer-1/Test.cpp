#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

////1 �����������ռ�
//namespace yf
//{
//	// �����ռ��п��Զ������/����/����
//	int rand = 0;
//
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//
//	struct Node
//	{
//		struct Node* next;
//		int val;
//	};
//}
//
////2. �����ռ����Ƕ��
//// test.cpp
//namespace N1
//{
//	int a;
//	int b;
//	int Add(int left, int right)
//	{
//		return left + right;
//	}
//	namespace N2
//	{
//		int c;
//		int d;
//		int Sub(int left, int right)
//		{
//			return left - right;
//		}
//	}
//}
////3. ͬһ��������������ڶ����ͬ���Ƶ������ռ�,����������ϳ�ͬһ�������ռ��С�
//// ps��һ�������е�test.h������test.cpp������N1�ᱻ�ϲ���һ��
//// test.h
//namespace N1
//{
//	int Mul(int left, int right)
//	{
//		return left * right;
//	}
//}


//namespace yf
//{
//	int rand = 10;
//}
//
//int main()
//{
//	printf("%d\n", yf::rand);
//	return 0;
//}

//namespace yf
//{
//	int b = 20;
//	int a = 10;
//}
//using yf::b;
//int main()
//{
//	printf("%d\n", yf::a);
//	printf("%d\n", b);
//	return 0;
//}
//


//namespace yf
//{
//    int a = 10;
//    int b = 20;
//    int Add(int left, int right)
//    {
//        return left + right;
//    }
//
//}
//using namespace yf;
//int main()
//{
//    printf("%d\n", a);
//    printf("%d\n", b);
//    int ret = Add(10, 20);
//    printf("%d", ret);
//    return 0;
//}


//namespace yf
//{
//	int a = 10;
//	namespace yyf
//	{
//		int b = 20;
//	}
//}
//
//int main()
//{
//	printf("%d\n", yf::a);
//	printf("%d\n", yf::yyf::b);
//}


//using namespace std;
// std C++�ٷ��ⶨ��������ռ�
// ������Ŀ��Ҫչ��std�����׳�ͻ
// �ճ���ϰ��Ϊ�˷��㣬�Ϳ���չ��
//#include<iostream>
//using namespace std;
//typedef struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//}ST;
//
//int main()
//{
//	ST s;
//	StackInit(&s);
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//// std C++�ٷ��ⶨ��������ռ� C++����׼��Ķ���ʵ�ֶ��ŵ���������ռ���
//// ������Ŀ��Ҫչ��std�����׳�ͻ
//// �ճ���ϰ��Ϊ�˷��㣬�Ϳ���չ��
//int main()
//{
//	// << ������
//	cout << "Hello world\n";
//
//	int a = 10;
//	double b = 11.1;
//	//std::cout << a << "\n";
//	//std::cout << b << "\n";
//
//	cout << a << "\n"<< b << '\n';
//	cout << a << endl << b << endl;
//	return 0;
//}


//#include<iostream>
//
//using std::cout;
//using std::endl;
//int main()
//{
//	cout << "hello world" << endl;
//
//	int a = 10;
//	double b = 5.20;
//	cout << a << endl << b << endl;
//	
//	//����ȡ
//	std::cin >> a >> b;
//	cout << a << endl << b << endl;
//	
//}

#include<iostream>
using namespace std;
void Fuc(int n = 0)// 0����ȱʡֵ
{
	cout << n << endl;
}
int main()
{
	Fuc();// û�д���ʱ, ʹ�ò�����ȱʡֵ
	Fuc(20);// ����ʱ, ʹ��ָ����ʵ��
	return 0;
}