#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//// ר�Ŵ���int�ļӷ�����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
//// ͨ�üӷ�����
//template<class T1, class T2>
//T1 Add(T1 left, T2 right)
//{
//	return left + right;
//}
//void Test()
//{
//	Add(1, 2); // ��Ǻ���ģ��������ȫƥ�䣬����Ҫ����ģ��ʵ����
//	Add(1, 2.0); // ģ�庯���������ɸ���ƥ��İ汾������������ʵ�����ɸ���ƥ���Add��
//}


//// ��ͨ����
//int Add(int left, int right)
//{
//	return left + right;
//}
//
////����ģ��
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
//
//int main()
//{
//	// ƥ�����ԭ��
//	// 1������ƥ�������£����ֳɵľͳ��ֳ�
//	// 2��û�оͽ��ͳ�
//	// 3���и����ʾͳԸ����ʵģ�����Ҫ�Լ�����
//	cout << Add(1, 2) << endl;
//	cout << Add(1.1, 2.2) << endl;
// 
//	return 0;
//}

//int main()
//{
//	// ��ͨ�ࣺ����->����
//	// ��ģ��ʵ�������ࣺ�����������ͣ�����<��������> ���������������
//	// ��ʾʵ����
//	Stack<int> st1; // Stack<int> �� ��st1������
//	Stack<double> st2;
//
//	// ��ʾʵ���������Ͳ�ͬ�����Ǿ��ǲ�ͬ����
//	//st1 = st2 --> error
//
//
//	return 0;
//}


//int main()
//{
//	string s1; //���ַ���
//	string s2("hello world");// ����string�����
//
//	string s3(10, 'x');//����n���ַ�
//
//	string s4 = s2;//��������
//	string s5(s2);//��������
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s4 << endl;
//
//	//��Щ���ǿ��Ըı��
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
//	//����Դ�ַ�����ʼ�±굽�����±� 
//	string s5(s2, 1, 6);
//	cout << s5 << endl;
//	
//	//��s5һ�� ֻ�ǿ���Դ�ַ�����ʼ�±굽'\0'֮ǰֹͣ
//	string s6(s2, 2);
//	cout << s6 << endl;
//	
//	//��s5һ�� ֻ�ǽ����±�ԶԶ�������ַ������� ���ǵ�'\0'�ͽ���
//	string s7(s2, 1, 100);
//	cout << s7 << endl;
//	
//	//string (const char* s, size_t n)
//	//��Դ�ַ�����һ���ַ���ʼ һֱ����n���ַ�
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


// �����ͷ���
//int main()
//{
//	//operator [] 
//	string s1("hello world");
//	for (size_t i = 0; i < s1.size(); i++)
//	{
//		cout << s1[i] << " ";
//		//�ײ�������-->cout << s1.operator[](i) << " "
//	}
//	cout << endl;
//	s1[0] = 'x';
//	cout << s1 << endl;
//}


//int main()
//{
//	string s1("hello world");
//	// iterator�÷���ָ��
//	string::iterator it = s1.begin();
//	while (it != s1.end())// s.end()ָ��'\0'
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//����ҿ�����
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
//	// iterator�÷���ָ��
//	string::iterator it = s1.begin();
//	while (it != s1.end())// s.end()ָ��'\0'
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	reverse(s1.begin(), s1.end());//����ҿ�����
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
//	//����s2
//	string::const_iterator it = s2.begin();
//	while (it != s2.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//}