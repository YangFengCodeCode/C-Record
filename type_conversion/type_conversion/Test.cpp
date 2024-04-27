using namespace std;
#include<iostream>

//void Test()
//{
//    int i = 1;
//    // 隐式类型转换
//    double d = i;
//    printf("%d, %.2f\n", i, d);
//
//    int* p = &i;
//    // 显示的强制类型转换
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
//	// 单参数的构造函数，支持内置类型隐式转换成自定义类型
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
//	//// 隐式类型转换
//	//double d = i;
//	//printf("%d, %.2f\n", i, d);
//	//int* p = &i;
//
//	//// 显示的强制类型转换
//	//int address = (int)p;
//	//char ch = i;
//
//	//printf("%p, %d\n", p, address);
//
//	
//	int i = 1;
//	int* p = &i;
//	//double dd = (double)p; -->无法转换，他们之间没有关联
//}
//
//
//int main()
//{
//	Test();
//
//	return 0;
//}



// 隐式类型转换
//void Insert(size_t pos, int x)
//{
//	//size_t end = _size;
//	int end = 10;
//	// 比较的时候end会隐式类型转换成size_t，再比较
//	while (end >= (int)pos)
//	{
//		cout << end <<"挪走" << endl;
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
//	// 建议规范，但是以前的还能用
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
//	// 对应的是以前的强制类型转换
//	// int* p = static_cast<int*>(a); 报错
//	int* p = reinterpret_cast<int*>(a);
//	cout << p << endl;
//}

//
//int main()
//{
//	//const int a1 = 2; -->不加 volatile  最后结果a1 还是2 
//	volatile const int a1 = 2;// volatile 指出 a1 是随时可能发生变化的，每次使用它的时候必须从 i的地址中读取
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
	// 向下转换：父->子
	// pa指向子类对象，转回子类，是安全的
	// pa指向父类对象，转回子类，是不安全的，存在越界的风险问题

	// 不安全
	//B* pb = (B*)pa;

	//  pa指向子类对象，转回子类，正常转换
	//  pa指向父类对象，转回子类，转换失败
	B* pb = dynamic_cast<B*>(pa);
	if (pb)
	{
		cout << pb << endl;
		cout << pb->_a << endl;
		cout << pb->_b << endl;
	}
	else
	{
		cout << "转换失败" << endl;
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


