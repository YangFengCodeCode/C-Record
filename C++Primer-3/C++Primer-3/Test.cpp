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
//	// 引用必须初始化
//	// int& b; 这是错误的
//
//	int& c = a;
//	int d = 1;
//
//	// c变成d的别名？还是d赋值给c？--把d赋值给c
//	c = d;
//
//	// 一个对象可以有多个别名，可以别名继续取别名
//	int& e = a;
//	int& f = e;
//
//	return 0;
//}



//void TestConstRef()
//{
//    const int a = 10;
//
//    //int& ra = a;   // 该语句编译时会出错，a为常量 权限不能放大
//    const int& ra = a;
//
//    // int& b = 10; // 该语句编译时会出错，b为常量
//    const int& b = 10;
//
//    double d = 12.34;
//    const double& rrd = d;//权限可以缩小
//
//    //int& rd = d; // 该语句编译时会出错，类型不同
//    const int& rd = d;//加了了const后 可以隐形类型提升
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


// 出了函数作用域，返回对象就销毁了，不能用引用返回，否则结果是不确定
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
//	static int c = a + b;//静态变量 只接受一次初始值
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
////引用做返回值：可以修改返回对象
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
//	// 每个位置的值++
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
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
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
//// 值返回
//A TestFunc1() { return a; }
//// 引用返回
//A& TestFunc2() { return a; }
//void TestReturnByRefOrValue()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
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
//	// b是否开空间? -- > 没有
//	int& b = a;
//
//	// ptr开了空间
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
//// 宏的缺点
//// 1、容易出错，语法细节多
//// 2、不能调试
//// 3、没有类型安全的检查
//
//int main()
//{
//	//替换看
//	int ret1 = ADD(2, 3)*5; // （(2)+(3))*5
//	cout << ret1 << endl;
//	return 0;
//}




// 可以调试
// 效率高，会展开
// 好写，语法简单
inline int Add(int x, int y)
{
	int c = x + y;
	return c;
}

int main()
{
	int ret1 = Add(1, 2);
	// 优点：不用建立栈帧，提高效率
	cout << ret1 << endl;
	return 0;
}