#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

////1 正常的命名空间
//namespace yf
//{
//	// 命名空间中可以定义变量/函数/类型
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
////2. 命名空间可以嵌套
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
////3. 同一个工程中允许存在多个相同名称的命名空间,编译器最后会合成同一个命名空间中。
//// ps：一个工程中的test.h和上面test.cpp中两个N1会被合并成一个
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
// std C++官方库定义的命名空间
// 工程项目不要展开std，容易冲突
// 日常练习，为了方便，就可以展开
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
//// std C++官方库定义的命名空间 C++将标准库的定义实现都放到这个命名空间中
//// 工程项目不要展开std，容易冲突
//// 日常练习，为了方便，就可以展开
//int main()
//{
//	// << 流插入
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
//	//流提取
//	std::cin >> a >> b;
//	cout << a << endl << b << endl;
//	
//}

#include<iostream>
using namespace std;
void Fuc(int n = 0)// 0就是缺省值
{
	cout << n << endl;
}
int main()
{
	Fuc();// 没有传参时, 使用参数的缺省值
	Fuc(20);// 传参时, 使用指定的实参
	return 0;
}