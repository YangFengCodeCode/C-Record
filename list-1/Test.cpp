using namespace std;
#include<iostream>
#include<list>
#include<vector>
#include<string>

//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(3);
//	lt.push_back(4);
//	lt.push_back(5);
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.splice(lt.end(), lt, find(lt.begin(), lt.end(), 2));
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//
//	return 0;
//}


//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(2);
//	lt.push_back(4);
//	lt.push_back(5);
//	cout << lt.size() << endl;
//
//	lt.remove(2);
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	cout << lt.size() << endl;
//	return 0;
//}


//int main()
//{
//	list<int> lt;
//	lt.push_back(1);
//	lt.push_back(1);
//	lt.push_back(2);
//	lt.push_back(4);
//	lt.push_back(2);
//	lt.push_back(2);
//	lt.push_back(4);
//	lt.push_back(3);
//
//	lt.push_back(5);
//
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	lt.sort();//ĞèÒªÏÈÅÅĞò
//	lt.unique();
//	for (auto e : lt)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//
//	return 0;
//}

int main()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);


	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	lt.reverse();

	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	return 0;
}