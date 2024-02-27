#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<map>
#include<set>


//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{}
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{}
//};


void test_set1()
{
	// 排序+去重
	set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(1);

	set<int>::iterator it = s.begin();
	//找不到返回s.end()
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator pos = s.find(5);
	//找不到返回s.end()
	if (pos != s.end())
	{
		cout << "找到了" << endl;
		s.erase(pos);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 在就删除，不在就不做任何处理
	s.erase(3);
	s.erase(30);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 这个值在，找到有效位置，再进行删除
	//pos = s.find(5);
	//s.erase(pos);

	//count--> 返回该元素个数 有返回1 没有返回0
	if (s.count(5))
	{
		cout << "在" << endl;
	}
	else
	{
		cout << "不在" << endl;
	}
}

void test_set2()
{
	// 排序+去重
	set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(4);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;


	auto start = s.lower_bound(3);  // 返回 >=val 的值
	cout << *start << endl;

	auto finish = s.upper_bound(5);  // 返回 >val 的值
	cout << *finish << endl;

	//找 [3, 5]区间的数
	while (start != finish)
	{
		cout << *start << " ";
		++start;
	}
	cout << endl;

	start = s.lower_bound(3);
	//删除[3, 5]区间的数字
	s.erase(start, finish);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// 排序
	multiset<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(1);
	s.insert(1);
	s.insert(5);
	s.insert(1);
	s.insert(1);
	s.insert(2);
	s.insert(7);
	s.insert(10);


	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//count 返回该value的个数
	cout << s.count(5) << endl;
	cout << s.count(1) << endl;

	it = s.find(5);
	while (it != s.end() && *it == 5)
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


void test_map1()
{
	map<string, string> dict;
	dict.insert(pair<string, string>("sort", "排序"));

	//pair<string, string> kv("string", "字符串");
	pair<string, string> kv = { "string", "字符串" };
	dict.insert(kv);

	// C++11 多参数隐式类型转换(构造函数)
	dict.insert({ "apple", "苹果" });

	// C++98
	dict.insert(make_pair("sort", "排序"));

	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		//cout << (*it).first << (*it).second << endl;
		cout << it->first << it->second << endl;
		++it;
	}
	cout << endl;

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void test_map2()
{
	// key相同，value不同，不会插入也不会更新
	map<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));

	dict["left"]; // 插入
	cout << dict["sort"] << endl; // 查找

	dict["sort"] = "xxx"; // 修改
	dict["right"] = "右边"; // 插入+修改

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void test_map3()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
"苹果", "香蕉", "苹果", "西瓜", "香蕉", "草莓" };
	map<string, int> countMap;
	//统计个数

	//方法1
	//for (auto& e : arr)
	//{
	//	map<string, int>::iterator it = countMap.find(e);
	//	if (it != countMap.end())
	//	{
	//		it->second++;
	//	}
	//	else
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//}


	////方法2
	//for (auto& e : arr)
	//{
	//	pair<map<string, int>::iterator, bool> ret;
	//	ret = countMap.insert(make_pair(e, 1));

	//	// 已经存在了
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

	//方法3
	for (auto& e : arr)
	{
		countMap[e]++;
	}

	for (auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}


void test_map4()
{
	multimap<string, string> dict;
	dict.insert(make_pair("sort", "排序"));
	dict.insert(make_pair("string", "字符串"));
	dict.insert(make_pair("sort", "xxx"));
	dict.insert(make_pair("sort", "排序"));

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}
int main()
{
	/*test_set1();*/
	/*test_set2();*/
	/*test_set3();*/
	/*test_map1();*/
	/*test_map3();*/
	test_map4();
	return 0;
}





