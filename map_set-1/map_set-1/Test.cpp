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
	// ����+ȥ��
	set<int> s;
	s.insert(5);
	s.insert(1);
	s.insert(6);
	s.insert(3);
	s.insert(4);
	s.insert(5);
	s.insert(1);

	set<int>::iterator it = s.begin();
	//�Ҳ�������s.end()
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::iterator pos = s.find(5);
	//�Ҳ�������s.end()
	if (pos != s.end())
	{
		cout << "�ҵ���" << endl;
		s.erase(pos);
	}

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// �ھ�ɾ�������ھͲ����κδ���
	s.erase(3);
	s.erase(30);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ���ֵ�ڣ��ҵ���Чλ�ã��ٽ���ɾ��
	//pos = s.find(5);
	//s.erase(pos);

	//count--> ���ظ�Ԫ�ظ��� �з���1 û�з���0
	if (s.count(5))
	{
		cout << "��" << endl;
	}
	else
	{
		cout << "����" << endl;
	}
}

void test_set2()
{
	// ����+ȥ��
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


	auto start = s.lower_bound(3);  // ���� >=val ��ֵ
	cout << *start << endl;

	auto finish = s.upper_bound(5);  // ���� >val ��ֵ
	cout << *finish << endl;

	//�� [3, 5]�������
	while (start != finish)
	{
		cout << *start << " ";
		++start;
	}
	cout << endl;

	start = s.lower_bound(3);
	//ɾ��[3, 5]���������
	s.erase(start, finish);
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// ����
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

	//count ���ظ�value�ĸ���
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
	dict.insert(pair<string, string>("sort", "����"));

	//pair<string, string> kv("string", "�ַ���");
	pair<string, string> kv = { "string", "�ַ���" };
	dict.insert(kv);

	// C++11 �������ʽ����ת��(���캯��)
	dict.insert({ "apple", "ƻ��" });

	// C++98
	dict.insert(make_pair("sort", "����"));

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
	// key��ͬ��value��ͬ���������Ҳ�������
	map<string, string> dict;
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));

	dict["left"]; // ����
	cout << dict["sort"] << endl; // ����

	dict["sort"] = "xxx"; // �޸�
	dict["right"] = "�ұ�"; // ����+�޸�

	for (auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	cout << endl;
}

void test_map3()
{
	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����",
"ƻ��", "�㽶", "ƻ��", "����", "�㽶", "��ݮ" };
	map<string, int> countMap;
	//ͳ�Ƹ���

	//����1
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


	////����2
	//for (auto& e : arr)
	//{
	//	pair<map<string, int>::iterator, bool> ret;
	//	ret = countMap.insert(make_pair(e, 1));

	//	// �Ѿ�������
	//	if (ret.second == false)
	//	{
	//		ret.first->second++;
	//	}
	//}

	//����3
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
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("sort", "xxx"));
	dict.insert(make_pair("sort", "����"));

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





