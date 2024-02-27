using namespace std;
#include<iostream>

//class Person {
//public:
//	//void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
//};
//
//class Student : public Person {
//public:
//	//void BuyTicket() { cout << "��Ʊ-���" << endl; }
//	virtual void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//// ��̬
//// ����1���麯������д -> �������������麯������ͬ(������������������)
//// ����2������ָ�������ȥ�����麯��
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
//	virtual void BuyTicket(int x = 100) { cout << "��Ʊ-ȫ��-->" << x << endl; }
//};
//
//class Student : public Person {
//public:
//	virtual void BuyTicket(int x = 50) { cout << "��Ʊ-���--> " << x << endl; }
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
////ֻ��������Student������������д��Person����������
////�����delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�������������
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
//	virtual void Drive() { cout << "Benz-����" << endl; }
//};


//class Car {
//public:
//	virtual void Drive() {}
//};
//
//class Benz :public Car {
//public:
//	virtual void DriveTest() override { cout << "Benz-����" << endl; }
//};
//
//int main()
//{
//	Benz b;
//	return 0;
//}

//// ��дʵ��

//class Person {
//public:
//	virtual ~Person() 
//	{ 
//		cout << "~Person()" << endl;
//	}
//
//	virtual void BuyTicket() { cout << "��Ʊ-ȫ��" << endl; }
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
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
//};
//
//class Children : public Person
//{
//public:
//	void BuyTicket() { cout << "��Ʊ-���" << endl; }
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
//	// ��̬����
//	p1->BuyTicket();
//	p2->BuyTicket();
//	p3->BuyTicket();
//
//	// ��ͨ����
//	Student s;
//	s.BuyTicket();
//	s.Person::BuyTicket();
//
//	return 0;
//}

// sizeof(Base)�Ƕ��٣�
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

// �������Ĵ��������������¸���
// 1.��������һ��������Deriveȥ�̳�Base
// 2.Derive����дFunc1
// 3.Base������һ���麯��Func2��һ����ͨ����Func3


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

