#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<assert.h>
#include<string>


void func(const int& i)//�ȿ��Խ�����ֵ�ֿ��Խ�����ֵ
{
	cout << "void func(const int& i)" << endl;
}

void func(int&& i)//ֻ�ܽ�����ֵ
{
	cout << "void func(int&& i)" << endl;
}


namespace yf
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// �������� -- ��ֵ
		string(const string& s)
			:_str(nullptr)
		{
			cout << "string(const string& s) -- ���" << endl;

			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// �ƶ����� -- ��ֵ(����ֵ)
		string(string&& s)
		{
			cout << "string(string&& s) -- �ƶ�����" << endl;
			swap(s);
		}

		// ��ֵ����
		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- �ƶ���ֵ" << endl;
			swap(s);

			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str = nullptr;
		size_t _size = 0;
		size_t _capacity = 0; // �������������ʶ��\0
	};


	yf::string to_string(int value)
	{
		bool flag = true;
		if (value < 0)
		{
			flag = false;
			value = 0 - value;
		}

		yf::string str;
		while (value > 0)
		{
			int x = value % 10;
			value /= 10;

			str += ('0' + x);
		}

		if (flag == false)
		{
			str += '-';
		}

		std::reverse(str.begin(), str.end());
		return str;
	}
}

//int main()
//{
//	yf::string ret;//����
//	ret = yf::to_string(-1234);//��ֵ
//	return 0;
//}



//
//int main()
//{
//	int a = 0;
//	func(a);//aΪ��ֵ
//	func(10);//10Ϊ��ֵ
//
//	return 0;
//}



#include<list>
#include"list.h"

int main()
{
	yf::list<yf::string> lt;
	yf::string s1("11111");
	lt.push_back(s1);
	cout << "---------" << endl;

	lt.push_back(yf::string("2222"));
	cout << "---------" << endl;

	lt.push_back("2222");
	cout << "---------" << endl;

	return 0;
}