#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
//int Test()
//{
//	return 10;
//}
//int main()
//{
//	int a = 10;
//	auto b = a;
//	auto c = 'a';
//	auto d = Test();
//	auto e = &a;
//	auto& f = a;// &�ǲ���ʡ�Ե�
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	cout << typeid(f).name() << endl;
//	//auto k; �޷�ͨ�����룬ʹ��auto�������ʱ���������г�ʼ��
//	return 0;
//}


//int main()
//{
//    int x = 10;
//    auto a = &x;
//    auto* b = &x;
//    auto& c = x;
//    cout << typeid(a).name() << endl;
//    cout << typeid(b).name() << endl;
//    cout << typeid(c).name() << endl;
//    *a = 20;
//    *b = 30;
//    c = 40;
//    cout << *a << endl;
//    cout << *b << endl;
//    cout << c << endl;
//    return 0;
//}


//void TestAuto()
//{
//    auto a = 1, b = 2;
//    auto c = 3, d = 4.0;  // ���д�������ʧ�ܣ���Ϊc��d�ĳ�ʼ�����ʽ���Ͳ�ͬ
//}


//void TestAuto()
//{
//    int a[] = { 1,2,3 };
//    auto b[] = { 4��5��6 };//���д����Ǵ����
//}


//void TestFor()
//{
//    int array[] = { 1, 2, 3, 4, 5 };
//    // ����ȡ���������鸳ֵ��e
//	// �Զ��жϽ������Զ�++������
//    for (auto& e : array)
//        e *= 2;
//    for (auto e : array)
//        cout << e << " ";
//}
//
//int main()
//{
//    TestFor();
//}


//void TestFor(int array[])
//{
//    for (auto& e : array)
//        cout << e << endl;
//}



//void f(int)
//{
//	cout << "f(int)" << endl;
//}
//void f(int*)
//{
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(nullptr);
//	f((int*)NULL);
//	return 0;
//}


// C++����c����struct�������÷�
// structͬʱ����������
// 1�������������ͣ�Stack�������ͣ�����Ҫ��struct
// 2�������涨�庯��
//struct Stack
//{
//	int* a;
//	int top;
//	int capacity;
//
//	void Init()
//	{
//		a = 0;
//		top = 0;
//		capacity = 0;
//	}
//
//	void Push(int x)
//	{
//		//...
//	}
//};
//
//struct Queue
//{
//	// ...
//
//	void Init()
//	{
//
//	}
//};
//
//
//int main()
//{
//	Stack s1;//����Ҫstruct Stack s1
//	s1.Init();
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Push(4);
//
//	/*struct Stack s1;
//	StackInit(&s1);
//	StackPush(&s1, 1);
//	StackPush(&s1, 2);
//	StackPush(&s1, 3);*/
//
//	return 0;
//}
//


//class Date
//{
//public:
//	//����
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	// ����
//	int _year;
//	int _month;
//	int _day;
//};


// ���ǿ�������������ǲ��Ǻܽ�Ӳ��
//class Date
//{
//public:
//	void Init(int year)
//	{
//		// �����year�����ǳ�Ա���������Ǻ����βΣ�
//		year = year;
//	}
//private:
//	int year;
//};
//
//
//// ����һ�㶼��������
//class Date
//{
//public:
//	void Init(int year)
//	{
//		_year = year;
//	}
//private:
//	int _year;
//};
//// ��������
//class Date
//{
//public:
//	void Init(int year)
//	{
//		mYear = year;
//	}
//private:
//	int mYear;
//};
//// ������ʽҲ���Եģ���Ҫ������Ҫ��һ�㶼�ǼӸ�ǰ׺���ߺ�׺��ʶ���־���

//�������޶���˵����
//1. public���εĳ�Ա���������ֱ�ӱ�����
//2. protected��private���εĳ�Ա�����ⲻ��ֱ�ӱ�����(�˴�protected��private�����Ƶ�)
//3. ����Ȩ��������Ӹ÷����޶������ֵ�λ�ÿ�ʼֱ����һ�������޶�������ʱΪֹ
//4. �������û�з����޶�����������͵� } ���������
//5. class��Ĭ�Ϸ���Ȩ��Ϊprivate��structΪpublic(��ΪstructҪ����C)

//����Ͷ���׶Σ���Ҫ���о���ķ�װ���ԣ���ʲô�Ƿ�װ�أ�
//��װ�������ݺͲ������ݵķ��������л���ϣ����ض�������Ժ�ʵ��ϸ�ڣ������⹫���ӿ���
//�Ͷ�����н�����
//��װ��������һ�ֹ������û�������ʹ����


//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int  _age;
//};
//// ������Ҫָ��PrintPersonInfo������Person�������
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}


//// ���м��г�Ա���������г�Ա����
//class A1 {
//public:
//    void f1() {}
//private:
//    int _a;
//};
//
//// ���н��г�Ա����
//class A2 {
//public:
//    void f2() {}
//};
//
//// ����ʲô��û��---����
//class A3
//{};
//
//int main()
//{
//    cout << sizeof(A1) << endl;
//    cout << sizeof(A2) << endl;
//    cout << sizeof(A3) << endl;
//    return 0;
//}


//1. ��һ����Ա����ṹ��ƫ����Ϊ0�ĵ�ַ����
//2. ������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ����
//ע�⣺������ = ������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ��
//VS��Ĭ�ϵĶ�����Ϊ8
//3. �ṹ���ܴ�СΪ���������������б��������������Ĭ�϶������ȡ��С������������
//4. ���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ�����
//���С��������������������Ƕ�׽ṹ��Ķ�����������������
//�������⡿
//1. �ṹ����ô���룿 ΪʲôҪ�����ڴ���룿
//2. ����ýṹ�尴��ָ���Ķ���������ж��룿�ܷ���3��4��5�������ֽڶ��룿
//3. ʲô�Ǵ�С�ˣ���β���ĳ̨�����Ǵ�˻���С�ˣ���û��������Ҫ���Ǵ�С�˵ĳ���


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//	///*void Print(Date* this)
//	//{
//	//	cou*/t << this->_year << "-" << this->_month << "-" << this->_day << endl;
//	//}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	d1.Init(2023, 10, 7);
//	d2.Init(2022, 10, 7);
//
//	// ������ʾдthis���ʵ�κ��β�
//	d1.Print();
//	d2.Print();
//  
//	/*d1.Print(&d1); 
//	d2.Print(&d2);*/
//
//	return 0;
//}
//
//
////1. thisָ������ͣ������� * const������Ա�����У����ܸ�thisָ�븳ֵ��
////2. ֻ���ڡ���Ա���������ڲ�ʹ��
////3. thisָ�뱾�����ǡ���Ա���������βΣ���������ó�Ա����ʱ���������ַ��Ϊʵ�δ��ݸ�
////this�βΡ����Զ����в��洢thisָ�롣
////4. thisָ���ǡ���Ա��������һ��������ָ���βΣ�һ������ɱ�����ͨ��ecx�Ĵ����Զ���
////�ݣ�����Ҫ�û�����


typedef int DataType;
class Stack
{
public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}
		_capacity = 3;
		_size = 0;
	}
	void Push(DataType data)
	{
		CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	void Pop()
	{
		if (Empty())
			return;
		_size--;
	}
	DataType Top() { return _array[_size - 1]; }
	int Empty() { return 0 == _size; }
	int Size() { return _size; }
	void Destroy()
	{
		if (_array)
		{
			free(_array);
			_array = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	void CheckCapacity()
	{
		if (_size == _capacity)
		{
			int newcapacity = _capacity * 2;
			DataType* temp = (DataType*)realloc(_array, newcapacity *
				sizeof(DataType));
			if (temp == NULL)
			{
				perror("realloc����ռ�ʧ��!!!");
				return;
			}
			_array = temp;
			_capacity = newcapacity;
		}
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
int main()
{
	Stack s;
	s.Init();
	s.Push(1);
	s.Push(2);
	s.Push(3);
	s.Push(4);

	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Pop();
	s.Pop();
	printf("%d\n", s.Top());
	printf("%d\n", s.Size());
	s.Destroy();
	return 0;
}