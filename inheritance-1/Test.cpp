#include<iostream>
using namespace std;

//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // 姓名
//	int _age = 18;  // 年龄
//};
//
////继承后父类的Person的成员（成员函数+成员变量）都会变成子类的一部分。这里体现出了
////Student和Teacher复用了Person的成员。下面我们使用监视窗口查看Student和Teacher对象，可
////以看到变量的复用。调用Print可以看到成员函数的复用。
//class Student : public Person
//{
//public:
//	Student(int x)
//		:_stuid(x)
//	{}
//
//protected:
//	int _stuid; // 学号
//};
//
//class Teacher : public Person
//{
//public:
//	Teacher(int x)
//		:_jobid(x)
//	{}
//
//protected:
//	int _jobid; // 工号
//};



class Person
{
protected:
	void Print()
	{
		cout << _name << endl;
	}
	string _name; // 姓名
private:
	int _age; // 年龄
};


class Student : public Person
{
protected:
	int _stunum; // 学号
};

//class Student : protected Person
//{
//protected:
//	int _stunum; // 学号
//};
//
//class Student : private Person
//{
//protected:
//	int _stunum; // 学号
//};

int main()
{
	Student s;
	s.Print();
	return 0;
}