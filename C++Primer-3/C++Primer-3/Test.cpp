#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//int Add(int a, int b)
//{
//	return a + b;
//}
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int ret = Add(a, b);
//	printf("%d", ret);
//	return 0;
//}



//int main()
//{
//	int a = 0;
//
//	// ���ñ����ʼ��
//	// int& b; ���Ǵ����
//
//	int& c = a;
//	int d = 1;
//
//	// c���d�ı���������d��ֵ��c��--��d��ֵ��c
//	c = d;
//
//	// һ����������ж�����������Ա�������ȡ����
//	int& e = a;
//	int& f = e;
//
//	return 0;
//}



//void TestConstRef()
//{
//    const int a = 10;
//
//    //int& ra = a;   // ��������ʱ�����aΪ���� Ȩ�޲��ܷŴ�
//    const int& ra = a;
//
//    // int& b = 10; // ��������ʱ�����bΪ����
//    const int& b = 10;
//
//    double d = 12.34;
//    const double& rrd = d;//Ȩ�޿�����С
//
//    //int& rd = d; // ��������ʱ��������Ͳ�ͬ
//    const int& rd = d;//������const�� ����������������
//
//    int i = 1;
//    double j = i;
//    const double& rj = i;
//}

#include<iostream>
using namespace std;
//void Swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 1;
//	int b = 2;
//	Swap(a, b);
//	cout << a << ' ' << b << endl;
//}


//int& Count()
//{
//	int n = 0;
//	n++;
//
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	cout << ret << endl;
//
//	return 0;
//}


// ���˺��������򣬷��ض���������ˣ����������÷��أ��������ǲ�ȷ��
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;
//
//	Add(3, 4);
//
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}


//int& Add(int a, int b)
//{
//	static int c = a + b;//��̬���� ֻ����һ�γ�ʼֵ
//	return c;
//}
//
//
//int main()
//{
//	int& ret = Add(1, 2);
//	cout << "Add(1, 2) is :" << ret << endl;
//
//	Add(3, 4);
//
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}



//typedef struct SeqList
//{
//	int a[100];
//	int size;
//}SL;
//
////void SLModify(SL* ps, int pos, int x)
////{
////	//...
////	assert(ps);
////	assert(pos < ps->size);
////	ps->a[pos] = x;
////}
//
////����������ֵ�������޸ķ��ض���
//int& SLat(SL* ps, int pos)
//{
//	assert(ps);
//	assert(pos < ps->size);
//	
//	return ps->a[pos];
//}
//
//int main()
//{
//	SL s;
//	//...
//
//	SLat(&s, 3) = 10;
//
//	// ÿ��λ�õ�ֵ++
//	for (size_t i = 0; i < s.size; i++)
//	{
//		SLat(&s, i)++;
//	}
//
//	return 0;
//}



//int& Add(int a, int b)
//{
//    int c = a + b;
//    return c;
//}
//int main()
//{
//    int& ret = Add(1, 2);
//    Add(3, 4);
//    cout << "Add(1, 2) is :" << ret << endl;
//    return 0;
//}
//


//int& Count(int n)
//{
//	n++;
//
//	return n;
//}
//
//int main()
//{
//	int& ret = Count(1);
//	cout << ret << endl;
//
//	cout << ret << endl;
//
//	return 0;
//}



//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//}


//#include <time.h>
//struct A { int a[10000]; };
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestReturnByRefOrValue();
//}


//int main()
//{
//	int a = 10;
//
//	// b�Ƿ񿪿ռ�? -- > û��
//	int& b = a;
//
//	// ptr���˿ռ�
//	int* ptr = &a;
//
//	char ch = 'x';
//	char& r = ch;
//	cout << sizeof(r) << endl;
//	return 0;
//}
//
//
//




//#define ADD(x, y) ((x) + (y))
//
//// ���ȱ��
//// 1�����׳����﷨ϸ�ڶ�
//// 2�����ܵ���
//// 3��û�����Ͱ�ȫ�ļ��
//
//int main()
//{
//	//�滻��
//	int ret1 = ADD(2, 3)*5; // ��(2)+(3))*5
//	cout << ret1 << endl;
//	return 0;
//}




// ���Ե���
// Ч�ʸߣ���չ��
// ��д���﷨��
inline int Add(int x, int y)
{
	int c = x + y;
	return c;
}

int main()
{
	int ret1 = Add(1, 2);
	// �ŵ㣺���ý���ջ֡�����Ч��
	cout << ret1 << endl;
	return 0;
}