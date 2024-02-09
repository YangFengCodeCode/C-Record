using namespace std;
#include<iostream>
#include<vector>

namespace yf
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};



	template<class T, class Container = vector<T>, class Compare = less<T>>//传less就是默认大堆
	class priority_queue
	{
	public:
		void adjust_up(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void adjust_down(int parent)
		{
			int child = parent * 2 + 1;
			Compare com;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child+1]))
				{
					++child;
				}

				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);

			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();

			adjust_down(0);
		}

		const T& top()
		{
			return _con[0];
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};
}


int main()
{
	yf::priority_queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	while (!q.empty())
	{
		cout << q.top() << ' ';
		q.pop();
	}
	cout << endl;

	yf::priority_queue<int, vector<int>, greater<int>> q2;
	q2.push(1);
	q2.push(2);
	q2.push(3);
	q2.push(4);

	while (!q2.empty())
	{
		cout << q2.top() << ' ';
		q2.pop();
	}

	return 0;
}