#pragma once
namespace yf
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);
		}

		// ��xӳ���λ��ǳ�1
		void set(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			_bits[i] |= (1 << j);
		}

		// ��xӳ���λ��ǳ�0
		void reset(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			_bits[i] &= ~(1 << j);
		}

		bool test(size_t x)
		{
			assert(x <= N);

			size_t i = x / 32;
			size_t j = x % 32;

			return _bits[i] & (1 << j);
		}
	private:
		vector<int> _bits;
	};

	void test_bitset()
	{
		bitset<100> bs1;
		bs1.set(50);
		bs1.set(30);
		bs1.set(90);

		for (size_t i = 0; i < 100; i++)
		{
			if (bs1.test(i))
			{
				cout << i << "->" << "��" << endl;
			}
			else
			{
				cout << i << "->" << "����" << endl;
			}
		}

		bs1.reset(90);
		bs1.set(91);

		cout << endl << endl;

		for (size_t i = 0; i < 100; i++)
		{
			if (bs1.test(i))
			{
				cout << i << "->" << "��" << endl;
			}
			else
			{
				cout << i << "->" << "����" << endl;
			}
		}

	}
}




