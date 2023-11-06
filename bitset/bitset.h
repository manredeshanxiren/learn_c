#pragma once



namespace xupt
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bit = vector<char>(N / 8 + 1);
		}

		void reset(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			_bit[i] &= ~(1 << j);
		}

		void set(size_t x)
		{
			size_t i = x / 8; // 计算x在第i个char内
			size_t j = x % 8;// 计算x在char的第j个位置
			_bit[i] |= (1 << j);
		}

		bool test(size_t x)
		{
			size_t i = x / 8;
			size_t j = x % 8;
			return _bit[i] & (1 << j);
		}

	private:
		vector<char> _bit;
	};


	template<size_t N>
	class twobit
	{
	public:
		void set(int x)
		{
			//00
			if (set1.test(x) == false && set2.test(x) == false)
			{
				set2.set(x);
			}
			//01
			else if (set1.test(x) == false && set2.test(x) == true)
			{
				set2.reset(x);
				set1.set(x);
			}
			//10
			else if (set1.test(x) == true && set2.test(x) == false)
			{
				set2.set(x);
			}
		}
		void Print()
		{
			for (int i = 0; i < N; ++i)
			{
				if ((set1.test(i) == true && set2.test(i) == false) || (set1.test(i) == false && set2.test(i) == true))
					cout << i << " ";
			}
		}

	public:
		bitset<N> set1;
		bitset<N> set2;
	};

	void twobittest()
	{
		int a[] = { 3, 45,12, 12, 43,55,12,67,98,67,35,86 };
		twobit<100> set;
		for (auto& i : a)
		{
			set.set(i);
		}
		set.Print();
	}



	struct BKDRHash
	{
		size_t operator()(const string& s)
		{
			// BKDR
			size_t value = 0;
			for (auto ch : s)
			{
				value *= 31;
				value += ch;
			}
			return value;
		}
	};


	struct APHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 0;
			for (long i = 0; i < s.size(); i++)
			{
				if ((i & 1) == 0)
				{
					hash ^= ((hash << 7) ^ s[i] ^ (hash >> 3));
				}
				else
				{
					hash ^= (~((hash << 11) ^ s[i] ^ (hash >> 5)));
				}
			}
			return hash;
		}
	};
	struct DJBHash
	{
		size_t operator()(const string& s)
		{
			size_t hash = 5381;
			for (auto ch : s)
			{
				hash += (hash << 5) + ch;
			}
			return hash;
		}
	};


	//N为最大可以存储的数的数量
	template<size_t N, class K = string,
	class Hash1 = BKDRHash,
	class Hash2 = APHash,
	class Hash3 = DJBHash>
	class BloomFilter
	{
		void set(const K& key)
		{
			size_t hash1 = Hash1()(key) % N;
			_bs.set(hash1);
			size_t hash2 = Hash2()(key) % N;
			_bs.set(hash2);
			size_t hash3 = Hash3()(key) % N;
			_bs.set(hash3);
		}


		bool test(const K& key)
		{
			size_t hash1 = Hash1()(key) % N;
			if (!_bs.test(hash1))
			{
				return false;
			}
			size_t hash2 = Hash2()(key) % N;
			if (!_bs.test(hash2))
			{
				return false;
			}
			size_t hash3 = Hash3()(key) % N;
			if (!_bs.test(hash3))
			{
				return false;
			}
			//一个不确定的true
			return true;
		}

	private: 
		bitset<N> _bs;
	};

	void testBloomFilter()
	{
		BloomFilter<100> BF;


	}

}