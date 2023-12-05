#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

void Test1()
{
	vector<int> a;
	vector<int> b(4, 100);
	vector<int> c(b.begin(), b.end());
	vector<int> d(b);

	for (size_t i = 0; i < b.size(); i++)
	{
		cout << b[i] << ' ';
	}
	cout << endl;

	for (size_t i = 0; i < c.size(); i++)
	{
		cout << c[i] << ' ';
	}
	cout << endl;

	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;

	a = d;//¸³Öµ¿½±´
	for (size_t i = 0; i < d.size(); i++)
	{
		cout << d[i] << ' ';
	}

}


void Test2()
{
	string s("123456");
	vector<int> v(s.begin(), s.end());
	for (auto e : v)
	{
		cout << e << " ";
	}
}

void Test3()
{
	vector<int> v(4, 1);
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << ' ';
		++it;
	}
	cout << endl;

	const vector<int> vv(4, 10);
	vector<int>::const_iterator itt = vv.begin();
	while (itt != vv.end())
	{
		cout << *itt << ' ';
		++itt;
	}
	
}

void Test4()
{
	vector<int> v(5);
	vector<int>::reverse_iterator it = v.rbegin();
	int i = 1;
	while (it != v.rend())
	{
		*it += i;
		++it;
		++i;
	}
	for (auto e : v)
	{
		cout << e << ' ';
	}

}


void Test5()
{
	vector<int> v(5, 10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(2);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	v.resize(4, 1);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

}

void Test6()
{
	vector<int> v(5, 10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(1);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(50);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void Test7()
{
	vector<int> v(4, 100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(100);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.shrink_to_fit();
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}


void Test8()
{
	vector<int> a(5, 10);
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	a.assign(6, 1);
	for (auto e : a)
	{
		cout << e << ' ';
	}
	cout << endl;
	cout << a.size() << endl;
	cout << a.capacity() << endl;

	vector<int> b;
	b.assign(a.begin(), a.end() - 1);
	for (auto e : b)
	{
		cout << e << ' ';
	}
}


void Test9()
{
	vector<int> v(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	for (auto e : v)
	{
		cout << e << ' ';
	}
}

void Test10()
{
	vector<int> v(4, 10);
	v.insert(v.begin(), 100);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	v.insert(v.end(), 4, 100);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	string s("hello");
	s.insert(1 , "l");
	cout << s;

}

void Test11()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.erase(v.begin());
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	v.erase(v.begin(), v.begin()+2);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}


void Test12()
{
	vector<int> v1(4, 10);
	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;

	vector<int> v2(4, 1);
	v1.swap(v2);
	for (auto e : v1)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void Test13()
{
	vector<int> v(1, 4);
	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;

	v.clear();
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	for (auto e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
}

void Test14()
{
	vector<string> v;
	v.push_back("hello");
	v.push_back("world");

	cout << v[0] << endl;
	cout << v[1] << endl;

	cout << v[0][1] << endl;
	cout << v[0][2] << endl;
}

void Test15()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	
	cout << v[0] << endl;
	cout << v.at(0) << endl;	
}


void Test16()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	cout << v.front() << endl;
	cout << v.back() << endl;
}


void Test17()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(2);
	v.push_back(0);

	vector<int>::iterator pos = find(v.begin(), v.end(), 2);
	if (pos != v.end())
	{
		v.insert(pos, 300);
	}
	for (auto e : v)
	{
		cout << e << ' ';
	}

}
int main()
{
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();
	//Test12();
	//Test13();
	//Test14();
	//Test15();
	//Test16();
	Test17();
	return 0;
}



