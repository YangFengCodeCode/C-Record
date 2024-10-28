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
		// 这里是随意写的，假设输入_year为0，则结束
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
	string _name; // 名字
	int _id;
	// id
	Date _date;
	// 时间
	string _msg;  // 聊天信息
};

int main()
{
	// 结构信息序列化为字符串
	ChatInfo winfo = { "张三", 135246, { 2022, 4, 10 }, "晚上一起看电影吧"};
	ostringstream oss;
	oss << winfo._name << " " << winfo._id << " " << winfo._date << " "<< winfo._msg;
	string str = oss.str();
	cout << str << endl << endl;
	// 我们通过网络这个字符串发送给对象，实际开发中，信息相对更复杂，
    // 一般会选用Json、xml等方式进行更好的支持
    // 字符串解析成结构信息
	
	//反序列化
	ChatInfo rInfo;
	istringstream iss(str);
	iss >> rInfo._name >> rInfo._id >> rInfo._date >> rInfo._msg;
	cout << "-------------------------------------------------------"<< endl;
	cout << "姓名：" << rInfo._name << "(" << rInfo._id << ") ";
	cout << rInfo._date << endl;
	cout << rInfo._name << ":>" << rInfo._msg << endl;
	cout << "-------------------------------------------------------"
		<< endl;
	return 0;
}



//int main()
//{
//	stringstream sstream;
//	// 将多个字符串放入 sstream 中
//	sstream << "first" << " " << "string,";
//	sstream << " second string";
//	cout << "strResult is: " << sstream.str() << endl;
//
//	// 清空 sstream
//	sstream.str("");
//	sstream << "third string";
//	cout << "After clear, strResult is: " << sstream.str() << endl;
//	return 0;
//}




//int main()
//{
//	int a = 12345678;
//	string sa;
//	// 将一个整形变量转化为字符串，存储到string类对象中
//	stringstream s;
//	s << a;
//	s >> sa;
//	cout << sa << endl;
//	// clear()
//	// 注意多次转换时，必须使用clear将上次转换状态清空掉
//   // stringstreams在转换结尾时(即最后一个转换后),会将其内部状态设置为badbit
//	// 因此下一次转换是必须调用clear()将状态重置为goodbit才可以转换
//   // 但是clear()不会将stringstreams底层字符串清空掉
//   // s.str("");
//	// 将stringstream底层管理string对象设置成"", 
//   // 否则多次转换时，会将结果全部累积在底层string对象中
//	s.str("");
//	s.clear();
//	// 清空s, 不清空会转化失败
//	double d = 12.34;
//	s << d;
//	s >> sa;
//	string sValue;
//	sValue = s.str();
//	// str()方法：返回stringsteam中管理的string类型
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