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
//	string _name = "peter"; // ����
//	int _age = 18;  // ����
//};
//
////�̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���
////Student��Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿�
////�Կ��������ĸ��á�����Print���Կ�����Ա�����ĸ��á�
//class Student : public Person
//{
//public:
//	Student(int x)
//		:_stuid(x)
//	{}
//
//protected:
//	int _stuid; // ѧ��
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
//	int _jobid; // ����
//};



class Person
{
protected:
	void Print()
	{
		cout << _name << endl;
	}
	string _name; // ����
private:
	int _age; // ����
};


class Student : public Person
{
protected:
	int _stunum; // ѧ��
};

//class Student : protected Person
//{
//protected:
//	int _stunum; // ѧ��
//};
//
//class Student : private Person
//{
//protected:
//	int _stunum; // ѧ��
//};

int main()
{
	Student s;
	s.Print();
	return 0;
}