#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

class stack
{
public:
	/*stack(int n)
	{
		int* _a = (int*)malloc(sizeof(int) * n);
		_top = 0;
		_capacity = n;
	}*/

	stack(int n = 2)
		:_a((int*)malloc(sizeof(int)*n)),
		_top(0),
		_capacity(n)
	{
		if (_a == nullptr)
		{
			perror("malloc fail");
			exit(-1);
		}
	}

	void Print()
	{
		cout << "top: " << _top << "capacity: " << _capacity;
	}

	~stack()
	{
		free(_a);
		_a = nullptr;
		_top = _capacity = 0;
	}

private:
	int* _a;
	int _top;
	int _capacity;
};

class MyQueue
{
public:
	MyQueue(int n1 = 10, int n2 = 100)
		:_s1(n1),
		 _s2(n2)
	{
		//初始化列表
	}

private:
	stack _s1;
	stack _s2;
	int size = 0;
};

int main()
{
	/*stack st1;*/
	MyQueue s1;
	//st1.Print();
	return 0;
}



