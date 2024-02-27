using namespace std;
#include<iostream>
#include<string>
//
//
//class Person
//{
//public:
//    Person(const char* name = "peter")
//        : _name(name)
//    {
//        cout << "Person()" << endl;
//    }
//
//    Person(const Person& p)
//        : _name(p._name)
//    {
//        cout << "Person(const Person& p)" << endl;
//    }
//
//    Person& operator=(const Person& p)
//    {
//        cout << "Person operator=(const Person& p)" << endl;
//        if (this != &p)
//            _name = p._name;
//
//        return *this;
//    }
//
//    ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//protected:
//    string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//    Student(const char* name, int num)
//        : Person(name)
//        , _num(num)  
//    {
//        cout << "Student()" << endl;
//    }
//
//    Student(const Student& s)
//        : Person(s)
//        , _num(s._num)
//    {
//        cout << "Student(const Student& s)" << endl;
//    }
//
//    Student& operator = (const Student& s)
//    {
//        cout << "Student& operator= (const Student& s)" << endl;
//        if (this != &s)
//        {
//            Person::operator =(s);
//            _num = s._num;
//        }
//        return *this;
//    }
//
//    ~Student()
//    {
//        cout << "~Student()" << endl;
//    }
//protected:
//    int _num; //学号
//};
//  
//
// 
//void Test()
//{
//    Student s1("jack", 18);
//    Student s2(s1);
//    Student s3("rose", 17);
//    s1 = s3;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}


//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//	cout << s._stuNum << endl;
//}
//int main()
//{
//	Person p;
//	Student s;
//	Display(p, s);
//	return 0;
//}


//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//
//int Person::_count = 0;//类外初始化
//
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//
//int main()
//{
//	Student s1;
//	Student s2;
//	Student s3;
//	Graduate s4;
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}


//class Person
//{
//public:
//	string _name = "zzz"; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//
//int main()
//{
//	// 这样会有二义性无法明确知道访问的是哪一个
//	Assistant a;
//	//a._name = "peter";
//	
//	// 需要显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//
//	return 0;
//}  

//
//class Person
//{
//public:
//	string _name; // 姓名
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num; //学号
//};
//
//class Teacher : virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//int main()
//{
//	Assistant a;
//	a._name = "peter";
//	return 0;
//}


class A
{
public:
	int _a;
};
// class B : public A
class B : virtual public A
{
public:
	int _b;
};
// class C : public A
class C : virtual public A
{
public:
	int _c;
};
class D : public B, public C
{
public:
	int _d;
};
int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}


// Car和BMW Car和Benz构成is-a的关系
class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
};

class BMW : public Car {
public:
	void Drive() { cout << "好开-操控" << endl; }
};

class Benz : public Car {
public:
	void Drive() { cout << "好坐-舒适" << endl; }
};

// Tire和Car构成has-a的关系

class Tire {
protected:
	string _brand = "Michelin";  // 品牌
	size_t _size = 17;         // 尺寸

};

class Car {
protected:
	string _colour = "白色"; // 颜色
	string _num = "陕ABIT00"; // 车牌号
	Tire _t; // 轮胎
};