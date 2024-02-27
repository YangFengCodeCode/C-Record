using namespace std;
#include<iostream>

//class Person {
//public:
//	//void BuyTicket() { cout << "买票-全价" << endl; }
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//class Student : public Person {
//public:
//	//void BuyTicket() { cout << "买票-半价" << endl; }
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//// 多态
//// 条件1：虚函数的重写 -> 父子类中两个虚函数，三同(函数名、参数、返回)
//// 条件2：父类指针或引用去调用虚函数
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}

//class Person {
//public:
//	virtual void BuyTicket(int x = 100) { cout << "买票-全价-->" << x << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket(int x = 50) { cout << "买票-半价--> " << x << endl; }
//};
//
//void Func(Person& p)
//{
//	p.BuyTicket();
//}
//
//int main()
//{
//	Person ps;
//	Student st;
//
//	Func(ps);
//	Func(st);
//
//	return 0;
//}
//
//class A {};
//class B : public A{};
//
//class Person {
//public:
//	virtual A* f() { 
//		cout << "A::f()" << endl;
//		return new A;
//	}
//};
//
//class Student : public Person {
//public:
//	virtual B* f() {
//		cout << "B::f()" << endl;
//		return new B;
//	}
//};
//
//int main()
//{
//	Person* p = new Student;
//	p->f();
//
//	return 0;
//}


//class Person {
//public:
//	virtual ~Person() { cout << "~Person()" << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual ~Student() { cout << "~Student()" << endl; }
//};
//
////只有派生类Student的析构函数重写了Person的析构函数
////下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。
//
//int main()
//{
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	delete p1;
//	delete p2;
//	return 0;
//}


//class Car
//{
//public:
//	virtual void Drive() final {}
//};
//
//class Benz :public Car
//{
//public:
//	virtual void Drive() { cout << "Benz-舒适" << endl; }
//};


//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	virtual void DriveTest() override { cout << "Benz-舒适" << endl; }
//};
//
//int main()
//{
//	Benz b;
//	return 0;
//}

//// 重写实现

//class Person {
//public:
//	virtual ~Person() 
//	{ 
//		cout << "~Person()" << endl;
//	}
//
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//
//
//class Student : public Person {
//public:
//	~Student()
//	{ 
//		cout << "~Student()" << endl;
//	}
//
//	void BuyTicket() { cout << "买票-半价" << endl; }
//};
//
//class Children : public Person
//{
//public:
//	void BuyTicket() { cout << "买票-免费" << endl; }
//};
//
//
//int main()
//{
//	//Person p;
//	//Student s;
//
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//	Person* p3 = new Children;
//
//	// 多态调用
//	p1->BuyTicket();
//	p2->BuyTicket();
//	p3->BuyTicket();
//
//	// 普通调用
//	Student s;
//	s.BuyTicket();
//	s.Person::BuyTicket();
//
//	return 0;
//}

// sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	Base b;
//	cout << sizeof(Base) << endl;
//	return 0;
//}

// 针对上面的代码我们做出以下改造
// 1.我们增加一个派生类Derive去继承Base
// 2.Derive中重写Func1
// 3.Base再增加一个虚函数Func2和一个普通函数Func3


class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}

	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}

	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
	char _ch = 'a';
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

void f(Base* ptr)
{
	ptr->Func1();
}

// vitual function table
int main()
{
	Base  bb;
	Derive dd;

	f(&bb);
	f(&dd);

	return 0;
}

