#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//// 全缺省
//void Func(int a = 10, int b = 20, int c = 30)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//    Func();
//    Func(1);
//    Func(1, 2);
//    Func(1, 2, 3);
//
//	return 0;
//}


//// 半缺省（缺省值只能从右往左给，必须是连续给）
//void Func(int a, int b =20, int c = 30)
//{
//    cout << "a = " << a << endl;
//    cout << "b = " << b << endl;
//    cout << "c = " << c << endl << endl;
//}
//
//int main()
//{
//    //Func();
//    Func(1);
//    Func(1, 2);
//    Func(1, 2, 3);
//
//    return 0;
//}



// 函数名相同  参数不同 返回值可同可不同
int Add(int left, int right)
{
	cout << left + right << endl;

	return left + right;
}

double Add(double left, double right)
{
	cout << "double Add(double left, double right)" << endl;

	return left + right;
}

// 参数个数不同
void f()
{
	cout << "f()" << endl;
}


void f(int a)
{
	cout << "f(int a) == "<< a << endl;
}

void f(int a, char b)
{
	cout << "f(int a,char b)" << endl;
}
void f(char b, int a)
{
	cout << "f(char b, int a)" << endl;
}


//int func()
//{
//	return 0;
//}
//
//double func()
//{
//	return 1.1;
//}

int main()
{
	Add(1, 2);
	Add(1.1, 2.2);
	//Add(1, 2.2);

	f();
	f(1);

	//func();

	return 0;
}


//1. 实际项目通常是由多个头文件和多个源文件构成，而通过C语言阶段学习的编译链接，我们
//可以知道，【当前a.cpp中调用了b.cpp中定义的Add函数时】，编译后链接前，a.o的目标
//文件中没有Add的函数地址，因为Add是在b.cpp中定义的，所以Add的地址在b.o中。那么
//怎么办呢？
//2. 所以链接阶段就是专门处理这种问题，链接器看到a.o调用Add，但是没有Add的地址，就
//会到b.o的符号表中找Add的地址，然后链接到一起。(老师要带同学们回顾一下)
//3. 那么链接时，面对Add函数，链接接器会使用哪个名字去找呢？这里每个编译器都有自己的
//函数名修饰规则。



//int main()
//{
//	int a = 1;
//	int b = a;
//
//	int& c = a;
//	int& d = a;
//	int& e = c;
//
//	cout << &a << endl;
//	cout << &c << endl;
//	cout << &d << endl;
//	cout << &e << endl;
//	cout << &b << endl;
//
//	return 0;
//}



// 传参数
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}

typedef struct SListNode
{
	struct SListNode* next;
	int val;
}SLTNode, * PSLTNode;

//void SListPushBack(PSLTNode& phead, int x)
void SListPushBack(SLTNode*& phead, int x)
{
	if (phead == NULL)
	{
		// ... 
		//phead = newnode;
	}
	else
	{
		// 找尾结点，再链接newnode
		// tail->next = newnode;
	}
}

int main()
{
	int a = 0, b = 2;
	Swap(&a, &b);
	Swap(a, b);

	//PSLTNode plist = NULL;
	SLTNode* plist = NULL;
	SListPushBack(plist, 1);
	SListPushBack(plist, 2);
	SListPushBack(plist, 3);


	return 0;
}
