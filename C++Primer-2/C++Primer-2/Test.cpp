#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

//// ȫȱʡ
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


//// ��ȱʡ��ȱʡֵֻ�ܴ������������������������
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



// ��������ͬ  ������ͬ ����ֵ��ͬ�ɲ�ͬ
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

// ����������ͬ
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


//1. ʵ����Ŀͨ�����ɶ��ͷ�ļ��Ͷ��Դ�ļ����ɣ���ͨ��C���Խ׶�ѧϰ�ı������ӣ�����
//����֪��������ǰa.cpp�е�����b.cpp�ж����Add����ʱ�������������ǰ��a.o��Ŀ��
//�ļ���û��Add�ĺ�����ַ����ΪAdd����b.cpp�ж���ģ�����Add�ĵ�ַ��b.o�С���ô
//��ô���أ�
//2. �������ӽ׶ξ���ר�Ŵ����������⣬����������a.o����Add������û��Add�ĵ�ַ����
//�ᵽb.o�ķ��ű�����Add�ĵ�ַ��Ȼ�����ӵ�һ��(��ʦҪ��ͬѧ�ǻع�һ��)
//3. ��ô����ʱ�����Add���������ӽ�����ʹ���ĸ�����ȥ���أ�����ÿ�������������Լ���
//���������ι���



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



// ������
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
		// ��β��㣬������newnode
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
