using namespace std;
#include<iostream>

//void Test()
//{
//    int i = 1;
//    // ��ʽ����ת��
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    int* p = &i;
//    // ��ʾ��ǿ������ת��
//    int address = (int)p;
//    printf("%x, %d\n", p, address);
//}


//class A
//{
//public:
//	operator int()
//	{
//		return _a1 + _a2;
//	}
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//void Test()
//{
//	A aa;
//	int ii1 = aa;
//	int ii2 = (int)aa;
//
//
//
//	// �������Ĺ��캯����֧������������ʽת�����Զ�������
//	string s1 = "111111";
//	const string& s2 = "11111";
//
//	/*Drive d;
//	Base b = d;*/
//
//	/*Base b;
//	Base* ptr1 = &b;
//	int* ptr2 = (int*)ptr1;*/
//
//	/*Node* cur = head;
//	while (cur)
//	{
//
//	}*/
//
//	//int i = 1;
//	//// ��ʽ����ת��
//	//double d = i;
//	//printf("%d, %.2f\n", i, d);
//	//int* p = &i;
//
//	//// ��ʾ��ǿ������ת��
//	//int address = (int)p;
//	//char ch = i;
//
//	//printf("%p, %d\n", p, address);
//
//	
//	int i = 1;
//	int* p = &i;
//	//double dd = (double)p; -->�޷�ת��������֮��û�й���
//}
//
//
//int main()
//{
//	Test();
//
//	return 0;
//}



// ��ʽ����ת��
//void Insert(size_t pos, int x)
//{
//	//size_t end = _size;
//	int end = 10;
//	// �Ƚϵ�ʱ��end����ʽ����ת����size_t���ٱȽ�
//	while (end >= (int)pos)
//	{
//		cout << end <<"Ų��" << endl;
//		--end;
//	}
//}
//
//int main()
//{
//	Insert(3, 1);
//	Insert(0, 1);
//
//	return 0;
//}


//int main()
//{
//	// ����淶��������ǰ�Ļ�����
//	double d = 12.34;
//	int a1 = static_cast<int>(d);
//	cout << a1 << endl;
//
//	int a2 = d;
//	cout << a2 << endl;
//
//	return 0;
//}


//int main()
//{
//	double d = 12.34;
//	int a = static_cast<int>(d);
//	cout << a << endl;
//
//	// ��Ӧ������ǰ��ǿ������ת��
//	// int* p = static_cast<int*>(a); ����
//	int* p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//}

//
//int main()
//{
//	//const int a1 = 2; -->���� volatile  �����a1 ����2 
//	volatile const int a1 = 2;// volatile ָ�� a1 ����ʱ���ܷ����仯�ģ�ÿ��ʹ������ʱ������ i�ĵ�ַ�ж�ȡ
//
//	//int* p1 = (int*)&a1;
//	int* p1 = const_cast<int*>(&a1);
//	*p1 = 3;
//	cout << a1 << endl;
//	cout << *p1 << endl;
//
//	return 0;
//}



class A
{
public:
	virtual void f() {}

	int _a = 0;
};

class B : public A
{
public:
	int _b = 1;
};

void fun(A* pa)
{
	// ����ת������->��
	// paָ���������ת�����࣬�ǰ�ȫ��
	// paָ�������ת�����࣬�ǲ���ȫ�ģ�����Խ��ķ�������

	// ����ȫ
	//B* pb = (B*)pa;

	//  paָ���������ת�����࣬����ת��
	//  paָ�������ת�����࣬ת��ʧ��
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		cout << pb << endl;
		cout << pb->_a << endl;
		cout << pb->_b << endl;
	}
	else
	{
		cout << "ת��ʧ��" << endl;
	}
}

int main()
{
	A a;
	B b;

	fun(&a);
	fun(&b);

	return 0;
}


