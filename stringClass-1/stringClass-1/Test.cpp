#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//// 专门处理int的加法函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// 通用加法函数
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // 与非函数模板类型完全匹配，不需要函数模板实例化
//	Add(1, 2.0); // 模板函数可以生成更加匹配的版本，编译器根据实参生成更加匹配的Add函
//}


//// 普通函数
//int Add(int left, int right)
//{
//	return left + right;
//}
//
////函数模板
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// 匹配调用原则：
//	// 1、合适匹配的情况下，有现成的就吃现成
//	// 2、没有就将就吃
//	// 3、有更合适就吃更合适的，哪怕要自己现做
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
// 
//	return 0;
//}

//int main()
//{
//	// 普通类：类名->类型
//	// 类模板实例化的类：类名不是类型，类名<数据类型> 才是整个类的类型
//	// 显示实例化
//	Stack<int> st1; // Stack<int> 是 类st1的类型
//	Stack<double> st2;
//
//	// 显示实例化的类型不同，他们就是不同的类
//	//st1 = st2 --> error
//
//
//	return 0;
//}


//int main()
//{
//	string s1; //空字符串
//	string s2("hello world");// 构造string类对象
//
//	string s3(10, 'x');//包含n个字符
//
//	string s4 = s2;//拷贝构造
//	string s5(s2);//拷贝构造
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s4 << endl;
//
//	//这些类是可以改变的
//	s1 = s2;
//	cout << s1 << endl;
//
//	s1 = "world";
//	cout << s1 << endl;
//
//	s1 = 'x';
//	cout << s1 << endl;
//
//	return 0;
//}

//int main()
//{
//	string s2("hello world");
//
//	//string (const string& str, size_t pos, size_t len = npos)
//	//拷贝源字符串开始下标到结束下标 
//	string s5(s2, 1, 6);
//	cout << s5 << endl;
//	
//	//与s5一样 只是拷贝源字符串开始下标到'\0'之前停止
//	string s6(s2, 2);
//	cout << s6 << endl;
//	
//	//与s5一样 只是结束下标远远大于了字符串长度 但是到'\0'就结束
//	string s7(s2, 1, 100);
//	cout << s7 << endl;
//	
//	//string (const char* s, size_t n)
//	//从源字符串第一个字符开始 一直到第n个字符
//	string s8("hello world", 5);
//	cout << s8 << endl;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1.size() << endl;
//	cout << s1.length() << endl;
//
//	return 0;
//}


// 遍历和访问
//int main()
//{
//	//operator [] 
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//		//底层是这样-->cout << s1.operator[](i) << " "
//	}
//	cout << endl;
//	s1[0] = 'x';
//	cout << s1 << endl;
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
//}

#include<vector>
#include<list>
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	vector<int>::iterator vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
	
	reverse(v.begin(), v.end());
	
	vit = v.begin();
	while (vit != v.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
	
	list<double> lt;
	lt.push_back(1.1);
	lt.push_back(2.1);
	lt.push_back(3.1);
	lt.push_back(4.1);
	list<double>::iterator lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
	
	reverse(lt.begin(), lt.end());
	lit = lt.begin();
	while (lit != lt.end())
	{
		cout << *lit << " ";
		++lit;
	}
	cout << endl;
}


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
//}

//int main()
//{
//	string s1("hello world");
//	const string s2("hello world");
//	s1[0] = 'x';
//	//s2[0] = 'x' --> error
//	cout << s1 << endl;
//
//	//遍历s2
//	string::const_iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}