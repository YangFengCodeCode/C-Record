#pragma once
#include<assert.h>

namespace yf
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}

		//析构函数
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		//拷贝构造
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			memcpy(_start, v._start, v.size()*sizeof(T));
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}


		//swap
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		//赋值拷贝
		vector<T>& operator=(vector<T> v)
		{
			swap(v);
			return *this;
		}


		//迭代器
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		//reserve
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t old = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, size() * sizeof(T));
					delete[] _start;
				}
				_start = tmp;
				_finish = _start + old;
				_endofstorage = _start + n;
			}
		}


		//resize
		void resize(size_t n, T val = T())
		{
			if (n > capacity())
			{
				reserve(n);
				memset(_finish, val, (n-size())*sizeof(T));
				_finish = _start + n;
			}
			else if (n >= size() && n <= capacity())
			{
				for (int i = 0; i < n - size(); i++)
				{
					_start[size() + i] = val;
				}
				_finish = _start + n;
			}

			else
			{
				vector<T>::iterator pos = _start + n;
				while (pos != end())
				{
					erase(pos);
				}
			}
		}



		//push_back
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newcapacity);
			}

		    *_finish = x;
			_finish++;
		}


		//pop_back
		void pop_back()
		{
			assert(size() > 0);
			--_finish;
		}

		//insert
		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			memmove(pos + 1, pos, sizeof(T) * (_finish - pos));
			*pos = x;
			_finish++;
		}

		//erase
		void erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			memmove(pos, pos + 1, sizeof(T) * (_finish - pos - 1));
			_finish--;
		}

		//[]
		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}




		size_t size() const
		{
			return _finish - _start;
		}


		size_t capacity() const
		{
			return _endofstorage - _start;
		}


	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};


	void Test1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			it++;
		}
	}

	void Test2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			it++;
		}
		cout << endl;

		v.insert(v.end(), 100);
		for (auto e : v)
		{
			cout << e << ' ';
		}
	}


	void Test3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << ' ';
			it++;
		}
		cout << endl;

		v.erase(v.begin());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << ' ';
		}
	}


	void Test4()
	{
		vector<int> v;
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
		}
		cout << endl;


		v.resize(8);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		for (auto e : v)
		{
			cout << e << ' ';
		}
		cout << endl;

		v.resize(9, 100);
		cout << v.size() << endl;
		cout << v.capacity() << endl;
		for (auto e : v)
		{
			cout << e << ' ';
		}
	}
}
