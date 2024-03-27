#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<assert.h>
#include<bitset>
using namespace std;
#include"bit_set.h"





#include<bitset>
template<size_t N>
class two_bit_set
{
public:
	void set(size_t x)
	{
		// 00 -> 01
		if (_bs1.test(x) == false
			&& _bs2.test(x) == false)
		{
			_bs2.set(x);
		}
		else if (_bs1.test(x) == false
			&& _bs2.test(x) == true)
		{
			// 01 -> 10
			_bs1.set(x);
			_bs2.reset(x);
		}
	}

	//int test(size_t x)
	//{
	//	if (_bs1.test(x) == false
	//		&& _bs2.test(x) == false)
	//	{
	//		return 0;
	//	}
	//	else if (_bs1.test(x) == false
	//		&& _bs2.test(x) == true)
	//	{
	//		return 1;
	//	}
	//	else
	//	{
	//		return 2; // 2次及以上
	//	}
	//}
	bool test(size_t x)
	{
		if (_bs1.test(x) == false
			&& _bs2.test(x) == true)
		{
			return true;
		}

		return false;
	}
private:
	bitset<N> _bs1;
	bitset<N> _bs2;
};


int main()
{
	//yf::test_bitset();
	int a1[] = { 5,7,9,2,5,99,5,5,7,5,3,9,2,55,1,5,6 };
	int a2[] = { 5,3,5,99,6,99,33,66 };

	bitset<100> bs1;
	bitset<100> bs2;

	for (auto e : a1)
	{
		bs1.set(e);
	}

	for (auto e : a2)
	{
		bs2.set(e);
	}

	for (size_t i = 0; i < 100; i++)
	{
		if (bs1.test(i) && bs2.test(i))
		{
			cout << i << endl;
		}
	}
	return 0;
}