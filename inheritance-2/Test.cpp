using namespace std;
#include<iostream>
#include<string>

//class Person
//{
//public:
//	void Print()
//	{
//		cout << _name << endl;
//	}
//protected:
//	string _name = "zhang san"; // ����
//	int _id = 1;
//};
//
//class Student : public Person
//{
//protected:
//	int _stunum; // ѧ��
//	int _id = 2;
//};
//
//
//int main()
//{
//	Student s;
//	s.Print();
//	return 0;
//}


//class Person
//{
//protected:
//    string _name; // ����
//    string _sex;  // �Ա�
//    int _age; // ����
//};
//
//class Student : public Person
//{
//public:
//    int _No; // ѧ��
//};
//
//void Test()
//{
//    Student sobj;
//    // 1.���������Ը�ֵ���������/ָ��/����
//    Person pobj = sobj;
//    Person* pp = &sobj;
//    Person& rp = sobj;// �������⴦�� ��Ҫ�� const
//
//    //2.��������ܸ�ֵ�����������
//    //sobj = pobj;
//
//    // 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//    pp = &sobj;
//    Student * ps1 = (Student*)pp; // �������ת��ʱ���Եġ�
//    ps1->_No = 10;
//
//    pp = &pobj;
//    Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
//    ps2->_No = 10;
//}
//
//int main()
//{
//    Test();
//    return 0;
//}


// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
//class Person
//{
//protected:
//	string _name = "yangfeng"; // ����
//	int _num = 111;   // ���֤��
//};
//class Student : public Person
//{
//public:
//	void Print()
//	{
//		cout << " ����:" << _name << endl;
//		cout << " ���֤��:" << Person::_num << endl;
//		cout << " ѧ��:" << _num << endl;
//	}
//protected:
//	int _num = 999; // ѧ��
//};
//
//int main()
//{
//	Student s1;
//	s1.Print();
//	return 0;
//}


// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};

class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};

