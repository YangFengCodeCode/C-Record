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


//1. ջ�ֽж�ջ--�Ǿ�̬�ֲ����� / �������� / ����ֵ�ȵȣ�ջ�����������ġ�
//2. �ڴ�ӳ����Ǹ�Ч��I / Oӳ�䷽ʽ������װ��һ������Ķ�̬�ڴ�⡣�û���ʹ��ϵͳ�ӿڴ����������ڴ棬�����̼�ͨ�š�
//3. �����ڳ�������ʱ��̬�ڴ���䣬���ǿ����������ġ�
//4. ���ݶ�--�洢ȫ�����ݺ;�̬���ݡ�
//5. �����--��ִ�еĴ��� / ֻ��������


//int main()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* p1 = new int;
//
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* p2 = new int(10);
//
//	// ��̬����3��int���͵Ŀռ�
//	int* p3 = new int[3];
//
//	//������ݳ�ʼ��
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
	// new/delete �� malloc/free��������� new/delete���ڡ��Զ������͡����˿��ռ仹����ù��캯������������
	A* p1 = (A*)malloc(sizeof(A));
	A* p2 = new A(1);
	free(p1);
	delete p2;

	// ���������Ǽ�����һ����
	A* p3 = (A*)malloc(sizeof(A) * 10);
	A* p4 = new A[10];
	free(p3);
	delete[] p4;

	//���ڴ���һ������ڵ� ����Ҳ����֮ǰ��Щ�鷳��
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);

    //�������̬�ڴ濪��
	//����1
	A aa1(1);
	A aa2(1);
	A aa3(1);
	A* p5 = new A[3]{ aa1, aa2, aa3 };

	//����2
	A* p6 = new A[3]{ A(2), A(2), A(2) };

	//����3 -->��������ת��
	A* p7 = new A[3]{ 3, 3, 3 };

	return 0;
}



