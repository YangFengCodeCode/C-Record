#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>
using namespace std;

namespace yf
{
	class string
	{

	public:

		//构造
		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
			, _str(new char[_capacity + 1])
		{
			strcpy(_str, str);
			//初始化列表
		}

		/*string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];

			strcpy(_str, str);
		}*/

		//拷贝构造
		string(const string& s)
		{
			_size = s._size;
			_capacity = s._capacity;
			_str = new char[s._capacity + 1];
			strcpy(_str, s._str);
		}

		//赋值拷贝
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				strcpy(tmp, s._str);
				delete[] _str;

				_str = tmp;
				_size = s._size;
				_capacity = s._capacity;
			}

			return *this;
		}


		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}


		const char* c_str() const
		{
			return _str;
		}

		//[]
		const char& operator[](size_t pos) const
		{
			assert(pos <= _size);
			return _str[pos];
		}

		char& operator[](size_t pos)
		{
			assert(pos <= _size);
			return _str[pos];
		}

		//迭代器
		typedef char* itrator;
		typedef const char* const_itrator;

		itrator begin() 
		{
			return _str;
		}

		itrator end() 
		{
			return _str + _size;
		}

		const_itrator begin() const
		{
			return _str;
		}

		const_itrator end() const
		{
			return _str + _size;
		}


		//reserve
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n+1];
				strcpy(tmp, _str);
				delete[] _str;

				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		void insert(size_t pos, char ch)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			int end = _size;
			while (end >= (int)pos)// pos是size_t类型 如果不转换 end==-1时候 会隐形类型转换
			{
				_str[end + 1] = _str[end];
				--end;
			}

			_str[pos] = ch;
			_size++;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			int end = _size;
			while (end >= int(pos))
			{
				_str[end + len] = _str[end];
				--end;
			}

			strncpy(_str + pos, str, len);
			_size += len;
		}

		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);

			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
		}

		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos = 0)
		{
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}

			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			const char* ptr = strstr(_str + pos, str);
			if (ptr == nullptr)
			{
				return npos;
			}
			else
			{
				return ptr - _str;
			}
		}

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);
			size_t end = pos + len;
			if (len == npos || pos + len >= _size)
			{
				end = _size;
			}

			string str;
			str.reserve(end - pos);
			for (size_t i = pos; i < end; i++)
			{
				str += _str[i];
			}

			return str;
		}



	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		const static size_t npos = -1;
	};


	void test_string1()
	{
		string s1("hello string!");
		cout << s1.c_str() << endl;

		string s2(s1);
		cout << s2.c_str() << endl;

		string s3 = "hello world!";
		s1 = s3;
		cout << s1.c_str() << endl;
	}


	void test_string2()
	{
		string s1("hello string!");
		cout << s1[0] << s1[1] << endl;

		string::itrator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}

		cout << '\n';

		const string s2("hello world!");
		cout << s2[0] << s2[1] << endl;
		string::const_itrator itt = s2.begin();
		while (itt != s2.end())
		{
			cout << *itt << " ";
			++itt;
		}

	}

	void test_string3()
	{
		string s1("hello string!");
		s1.push_back('#');
		cout << s1.c_str() << endl;

		s1.append("hello world");
		cout << s1.c_str() << endl;

		s1.insert(1, '$');
		cout << s1.c_str() << endl;

		s1.insert(0, "yfyfyf");
		cout << s1.c_str() << endl;
	}
}