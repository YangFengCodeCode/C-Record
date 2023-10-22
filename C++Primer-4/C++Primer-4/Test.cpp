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
//	auto& f = a;// &是不能省略的
//	cout << typeid(b).name() << endl;
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//	cout << typeid(e).name() << endl;
//	cout << typeid(f).name() << endl;
//	//auto k; 无法通过编译，使用auto定义变量时必须对其进行初始化
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
//    auto c = 3, d = 4.0;  // 该行代码会编译失败，因为c和d的初始化表达式类型不同
//}


//void TestAuto()
//{
//    int a[] = { 1,2,3 };
//    auto b[] = { 4，5，6 };//此行代码是错误的
//}


//void TestFor()
//{
//    int array[] = { 1, 2, 3, 4, 5 };
//    // 依次取数组中数组赋值给e
//	// 自动判断结束，自动++往后走
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


// C++兼容c语言struct的所有用法
// struct同时升级成了类
// 1、类名就是类型，Stack就是类型，不需要加struct
// 2、类里面定义函数
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
//	Stack s1;//不需要struct Stack s1
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
//	//定义
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	// 声明
//	int _year;
//	int _month;
//	int _day;
//};


// 我们看看这个函数，是不是很僵硬？
//class Date
//{
//public:
//	void Init(int year)
//	{
//		// 这里的year到底是成员变量，还是函数形参？
//		year = year;
//	}
//private:
//	int year;
//};
//
//
//// 所以一般都建议这样
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
//// 或者这样
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
//// 其他方式也可以的，主要看环境要求。一般都是加个前缀或者后缀标识区分就行

//【访问限定符说明】
//1. public修饰的成员在类外可以直接被访问
//2. protected和private修饰的成员在类外不能直接被访问(此处protected和private是类似的)
//3. 访问权限作用域从该访问限定符出现的位置开始直到下一个访问限定符出现时为止
//4. 如果后面没有访问限定符，作用域就到 } 即类结束。
//5. class的默认访问权限为private，struct为public(因为struct要兼容C)

//在类和对象阶段，主要是研究类的封装特性，那什么是封装呢？
//封装：将数据和操作数据的方法进行有机结合，隐藏对象的属性和实现细节，仅对外公开接口来
//和对象进行交互。
//封装本质上是一种管理，让用户更方便使用类


//class Person
//{
//public:
//	void PrintPersonInfo();
//private:
//	char _name[20];
//	char _gender[3];
//	int  _age;
//};
//// 这里需要指定PrintPersonInfo是属于Person这个类域
//void Person::PrintPersonInfo()
//{
//	cout << _name << " " << _gender << " " << _age << endl;
//}


//// 类中既有成员变量，又有成员函数
//class A1 {
//public:
//    void f1() {}
//private:
//    int _a;
//};
//
//// 类中仅有成员函数
//class A2 {
//public:
//    void f2() {}
//};
//
//// 类中什么都没有---空类
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


//1. 第一个成员在与结构体偏移量为0的地址处。
//2. 其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处。
//注意：对齐数 = 编译器默认的一个对齐数 与 该成员大小的较小值。
//VS中默认的对齐数为8
//3. 结构体总大小为：最大对齐数（所有变量类型最大者与默认对齐参数取最小）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整
//体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
//【面试题】
//1. 结构体怎么对齐？ 为什么要进行内存对齐？
//2. 如何让结构体按照指定的对齐参数进行对齐？能否按照3、4、5即任意字节对齐？
//3. 什么是大小端？如何测试某台机器是大端还是小端，有没有遇到过要考虑大小端的场景


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
//	// 不能显示写this相关实参和形参
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
////1. this指针的类型：类类型 * const，即成员函数中，不能给this指针赋值。
////2. 只能在“成员函数”的内部使用
////3. this指针本质上是“成员函数”的形参，当对象调用成员函数时，将对象地址作为实参传递给
////this形参。所以对象中不存储this指针。
////4. this指针是“成员函数”第一个隐含的指针形参，一般情况由编译器通过ecx寄存器自动传
////递，不需要用户传递


typedef int DataType;
class Stack
{
public:
	void Init()
	{
		_array = (DataType*)malloc(sizeof(DataType) * 3);
		if (NULL == _array)
		{
			perror("malloc申请空间失败!!!");
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
				perror("realloc申请空间失败!!!");
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