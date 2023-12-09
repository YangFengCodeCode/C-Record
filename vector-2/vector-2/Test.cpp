#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include"vector.h"
#include<algorithm>

int main()
{
	//yf::Test1();
	//yf::Test2();
	//yf::Test3();
	yf::Test4();
	/*vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(10);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
	for (auto e : v)
	{
		cout << e << ' ';
	}*/
	vector<int> v1 = { 1,2,3,4,5 };
	vector<int> v2{ 1,2,3,4,5 };
	vector<int> v3({ 1,2,3 });

	sort(v1.begin(), v1.end()); // ÉýÐò
	sort(v1.begin(), v1.end(), greater<int>()); // ½µÐò

	
	return 0;
}