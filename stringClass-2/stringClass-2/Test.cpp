#define _CRT_SECURE_NO_WARNINGS 1

using namespace std;
#include<iostream>
#include<string.h>

//void func(const string& s)
//{
//	string::const_reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	string s1("hello world");
//	string::reverse_iterator it1 = s1.rbegin();
//	while (it1 != s1.rend())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	func(s1);
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//
//	return 0;
//}



//int main()
//{
//	string s1("hello world");
//	// iterator用法像指针
//	string::iterator it = s1.begin();
//	while (it != s1.end())// s.end()指向'\0'
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//左闭右开区间
//	cout << s1 << endl;
//
//	const string s2("hello world");
//	s1[0] = 'x';
//	//s2[0] = 'x' --> error
//	cout << s1 << endl;
//
//	//遍历s2
//	string::const_iterator itt = s2.begin();
//	while (itt != s2.end())
//	{
//		cout << *itt << " ";
//		++itt;
//	}
//}
//


//#include<vector>
//#include<list>
//int main()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	vector<int>::iterator vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	reverse(v.begin(), v.end());
//
//	vit = v.begin();
//	while (vit != v.end())
//	{
//		cout << *vit << " ";
//		++vit;
//	}
//	cout << endl;
//
//	list<double> lt;
//	lt.push_back(1.1);
//	lt.push_back(2.1);
//	lt.push_back(3.1);
//	lt.push_back(4.1);
//	list<double>::iterator lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//
//	reverse(lt.begin(), lt.end());
//	lit = lt.begin();
//	while (lit != lt.end())
//	{
//		cout << *lit << " ";
//		++lit;
//	}
//	cout << endl;
//}


//void func(const string& s)
//{
//	string::const_reverse_iterator it = s.rbegin();
//	while (it != s.rend())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	string s1("hello world");
//	string::reverse_iterator it1 = s1.rbegin();
//	while (it1 != s1.rend())
//	{
//		cout << *it1 << " ";
//		++it1;
//	}
//	cout << endl;
//	func(s1);
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	for (auto e : s1)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}


//int main()
//{
//	try
//	{
//		string s1;
//		string s2("hello world");
//
//		// 实践中没有参考和使用的价值
//		cout << s1.max_size() << endl;
//		cout << s2.max_size() << endl;
//		s1.reserve(s1.max_size());
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//int main()
//{
//	string str("Test string");
//	cout << "size: " << str.size() << "\n";
//	cout << "length: " << str.length() << "\n";
//	cout << "capacity: " << str.capacity() << "\n";
//	cout << "max_size: " << str.max_size() << "\n";
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1.capacity() << endl;
//	s1.reserve(500);
//	cout << s1.capacity() << endl;
//
//	string s2("hello worldxxxxxxxxxxxxx");
//	cout << s2.capacity() << endl;
//	s2.reserve(10);
//	cout << s2.capacity() << endl;
//	
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << '\n' << endl;
//
//	// > capacity --> 扩容+尾插
//	//s1.resize(100);
//	s1.resize(100, 'x');
//	cout << s1.size() << endl;
//	cout << s1.capacity() << endl;
//	cout << s1 << '\n' <<  endl;
//
//	// size < n < capacity  -> 尾插
//	string s2("hello world");
//	cout << s2.size() << endl;
//	cout << s2.capacity() << endl;
//	cout << s2 << endl;
//	s2.resize(12);
//	cout << s2.size() << endl;
//	cout << s2.capacity() << '\n' << endl;
//
//	// n < size -> 删除数据，保留前n个
//	string s3("hello world");
//	cout << s3.size() << endl;
//	cout << s3.capacity() << endl;
//	cout << s3 << endl;
//	s3.resize(5);
//	cout << s3 << endl;
//	cout << s3.size() << endl;
//	cout << s3.capacity()<< '\n' << endl;
//
//	string s5;
//	s5.resize(100, '#');
//	cout << s5 << endl;
//
//	return 0;
//}

//int main()
//{
//	try
//	{
//		string s1("hello world");
//		cout << s1.at(10) << endl;
//		cout << s1.at(11) << endl;	
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	s1.push_back('#');
//	cout << s1 << endl;
//	return 0;
//}
////输出 hello#

//int main()
//{
//	string s1("hello");
//	s1.push_back(' ');
//	s1.append("world");
//	cout << s1 << endl;
//
//	string s2 = "xxxx";
//	s2.append(s1);
//	cout << s2 << endl;
//
//	s2.append(++s1.begin(), --s1.end());
//	cout << s2 << endl;
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	string s2("world");
//	s1 += ' ';
//	s1 += s2;
//	cout << s1 << endl;
//}

//int main()
//{
//	string s1 = "hello world";
//	cout << s1;
//}

int main()
{
	string s1; //空字符串
	string s2("hello world");// 构造string类对象

	string s3(10, 'x');//包含n个字符

	string s4 = s2;//拷贝构造
	string s5(s2);//拷贝构造

	string s6 = "hello string";
	const string& s7 = "hello const string";
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s4 << endl;
	cout << s6 << endl;
	cout << s7 << endl;

	//这些类是可以改变的
	s1 = s2;
	cout << s1 << endl;

	s1 = "world";
	cout << s1 << endl;

	s1 = 'x';
	cout << s1 << endl;

	return 0;
}
