#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
//int globalVar = 1;
//static int staticGlobalVar = 1;
//void Test()
//{
//	static int staticVar = 1;
//	int localVar = 1;
//	int num1[10] = { 1, 2, 3, 4 };
//	char char2[] = "abcd";
//	const char* pChar3 = "abcd";
//	int* ptr1 = (int*)malloc(sizeof(int) * 4);
//	int* ptr2 = (int*)calloc(4, sizeof(int));
//	int* ptr3 = (int*)realloc(ptr2, sizeof(int) * 4);
//	free(ptr1);
//	free(ptr3);
//}


//1. 栈又叫堆栈--非静态局部变量 / 函数参数 / 返回值等等，栈是向下增长的。
//2. 内存映射段是高效的I / O映射方式，用于装载一个共享的动态内存库。用户可使用系统接口创建共享共享内存，做进程间通信。
//3. 堆用于程序运行时动态内存分配，堆是可以上增长的。
//4. 数据段--存储全局数据和静态数据。
//5. 代码段--可执行的代码 / 只读常量。


//int main()
//{
//	// 动态申请一个int类型的空间
//	int* p1 = new int;
//
//	// 动态申请一个int类型的空间并初始化为10
//	int* p2 = new int(10);
//
//	// 动态申请3个int类型的空间
//	int* p3 = new int[3];
//
//	//多个数据初始化
//	int* p4 = new int[3]{1, 2, 3};
//
//	delete p1;
//	delete p2;
//	delete[] p3;
//	delete[] p4;
//
//
//	return 0;
//}


class A
{
public:
	A(int a = 0)
		: _a(a)
	{
		cout << "A():" << this << endl;
	}
	~A()
	{
		cout << "~A():" << this << endl;
	}
private:
	int _a;
};

class stack
{
	A 
};
struct ListNode
{
	int _val;
	ListNode* _next;

	ListNode(int val)
		:_val(val)
		, _next(nullptr)
	{

	}
};

int main()
{
	// new/delete 和 malloc/free最大区别是 new/delete对于【自定义类型】除了开空间还会调用构造函数和析构函数
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// 内置类型是几乎是一样的
	A* p3 = (A*)malloc(sizeof(A) * 10);
	A* p4 = new A[10];
	free(p3);
	delete[] p4;

	//对于创建一个链表节点 我们也不像之前那些麻烦了
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

    //多个对象动态内存开辟
	//方法1
	A aa1(1);
	A aa2(1);
	A aa3(1);
	A* p5 = new A[3]{ aa1, aa2, aa3 };

	//方法2
	A* p6 = new A[3]{ A(2), A(2), A(2) };

	//方法3 -->隐形类型转换
	A* p7 = new A[3]{ 3, 3, 3 };

	return 0;
}



