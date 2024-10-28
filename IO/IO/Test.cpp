#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>

#include<sstream>

class Date
{
	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
public:
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{}
	operator bool()
	{
		// ����������д�ģ���������_yearΪ0�������
		if (_year == 0)
			return false;
		else
			return true;
	}
private:
	int _year;
	int _month;
	int _day;
};
istream& operator >> (istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}
ostream& operator << (ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}


struct ChatInfo
{
	string _name; // ����
	int _id;
	// id
	Date _date;
	// ʱ��
	string _msg;  // ������Ϣ
};

int main()
{
	// �ṹ��Ϣ���л�Ϊ�ַ���
	ChatInfo winfo = { "����", 135246, { 2022, 4, 10 }, "����һ�𿴵�Ӱ��"};
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " "<< winfo._msg;
	string str = oss.str();
	cout << str << endl << endl;
	// ����ͨ����������ַ������͸�����ʵ�ʿ����У���Ϣ��Ը����ӣ�
    // һ���ѡ��Json��xml�ȷ�ʽ���и��õ�֧��
    // �ַ��������ɽṹ��Ϣ
	
	//�����л�
	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
	cout << "-------------------------------------------------------"<< endl;
	cout << "������" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;
	cout << "-------------------------------------------------------"
		<< endl;
	return 0;
}



//int main()
//{
//	stringstream sstream;
//	// ������ַ������� sstream ��
//	sstream << "first" << " " << "string,";
//	sstream << " second string";
//	cout << "strResult is: " << sstream.str() << endl;
//
//	// ��� sstream
//	sstream.str("");
//	sstream << "third string";
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//	return 0;
//}




//int main()
//{
//	int a = 12345678;
//	string sa;
//	// ��һ�����α���ת��Ϊ�ַ������洢��string�������
//	stringstream s;
//	s << a;
//	s >> sa;
//	cout << sa << endl;
//	// clear()
//	// ע����ת��ʱ������ʹ��clear���ϴ�ת��״̬��յ�
//   // stringstreams��ת����βʱ(�����һ��ת����),�Ὣ���ڲ�״̬����Ϊbadbit
//	// �����һ��ת���Ǳ������clear()��״̬����Ϊgoodbit�ſ���ת��
//   // ����clear()���Ὣstringstreams�ײ��ַ�����յ�
//   // s.str("");
//	// ��stringstream�ײ����string�������ó�"", 
//   // ������ת��ʱ���Ὣ���ȫ���ۻ��ڵײ�string������
//	s.str("");
//	s.clear();
//	// ���s, ����ջ�ת��ʧ��
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str();
//	// str()����������stringsteam�й����string����
//	cout << sValue << endl;
//	return 0;
//}




//int main()
//{
//	int n = 123456789;
//	char s1[32];
//	_itoa(n, s1, 10);
//	cout << s1 << endl;
//
//
//	char s2[32];
//	sprintf(s2, "%d", n);
//	cout << s1 << endl;
//
//	char s3[32];
//	sprintf(s3, "%f", n);
//
//	return 0;
//}