#pragma once

namespace Hash
{
	enum State
	{
		EMPTY,
		EXIST,
		DELETE
	};

	template<class K, class V>
	struct HashDate
	{
		pair<K, V> _kv;
		State _state = EMPTY;
	};

	template<class K, class V, class Hash>
	class HashTable
	{
	public:
			bool Insert(const pair<K, V> kv)
			{
				Hash hash;
				//查看是否需要扩容，超过size的0.7就进行扩容
				if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
				{
					size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
					HashTable<K, V> newht;
					newht._tables.resize(newsize);
					//遍历旧表映射到新表
					for (auto& date : _tables)
					{
						if (date._state == EXIST)
							newht.Insert(date._kv);
					}
					_tables.swap(newht._tables);
				}

				size_t hashi = kv.first % _tables.size();

				//线性探测
				size_t i = 1;
				size_t index = hashi;
				while (_tables[index]._state == EXIST)
				{
					index = hashi + i;
					index %= _tables.size();
					++i;
				}
				_tables[index]._kv = kv;
				_tables[index]._state = EXIST;
				++_n;
				return true;
			}

			HashDate<K, V>* find(const K& key)
			{
				if (_tables.size() == 0)
				{
					return false;
				}
				size_t hashi = key % _tables.size();

				//线性探测
				size_t i = 1;
				size_t index = hashi;
				while (_tables[index]._state == EXIST)
				{
					if (_tables[index]._state == EXIST
						&& _tables[index].first == key)
					{
						return &_tables[index];
					}
					index = hashi + i;
					index %= _tables.size();
					++i;

					//查找了一圈，证明表中的状态只有EXIST和DELET的状态
					if (index == hashi)
					{
						break;
					}
				}
				return nullptr;
			}

			bool Erase(const K& key)
			{
				HashDate<K, V>* ret = find(key);
				if (ret)
				{
					ret->_state = DELETE;
					--_n;
					return true;
				}
				else
				{
					return false;
				}
			}
	private:
		vector<HashDate<K, V>> _tables;
		size_t _n = 0; // 存储数据的个数

	};


	//void HashTableTest1()
	//{
	//	int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
	//	HashTable<int, int, HashFunc<int>> ht;
	//	for (auto e : a)
	//	{
	//		ht.Insert(make_pair(e, e));
	//	}
	//	ht.Insert(make_pair(15, 15));
	//}
}

template<class K>
struct HashFunc
{
	size_t operator()(const K& key)
	{
		return key;
	}
};


//特化
template<>
struct HashFunc<string>
{
	size_t operator()(const string& s)
	{
		size_t hash = 0;
		for (auto ch : s)
		{
			hash += ch;
			hash *= 31;
		}

		return hash;
	}
};

namespace HashBucket
{
	template<class K, class V>
	struct HashNode
	{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{}
	};

	template<class K, class V, class Hash = HashFunc<K>>
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		~HashTable()
		{
			for (auto& cur : _tables)
			{
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				cur = nullptr;
			}

		}
	public:
		size_t GetNextPrime(size_t prime)
		{
			const int PRIMECOUNT = 28;
			static const size_t primeList[PRIMECOUNT] =
			{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul,
		   25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul,
		   805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
			};
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}
			return primeList[i];
		}


		Node* Find(const K& key)
		{
			Hash hash;
			if (_tables.size() == 0)
			{
				return nullptr;
			}
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool Erase(const K& key)
		{
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (cur->_kv.first == key)
				{
					if (prev == nullptr)
					{
						_tables[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			return false;
		}
		bool Insert(const pair<K, V>& kv)
		{
			Hash hash;
			if (Find(kv.first))
			{
				return false;
			}
			//载荷因子为1
			if (_n == _tables.size())
			{
				//size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
				size_t newsize = GetNextPrime(_tables.size());
				vector<Node*> newht(newsize, nullptr);
				Node* cur = nullptr;
				for (auto cur : _tables)
				{
					while (cur)
					{
						Node* next = cur->_next;

						size_t hashi = hash(cur->_kv.first) % newht.size();

						//头插到新的表中
						cur->_next = newht[hashi];
						newht[hashi] = cur;

						cur = next;
					}
				}
				_tables.swap(newht);
			}

			//头插
			size_t hashi = hash(kv.first) % _tables.size();
			Node* newnode = new Node(kv);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			_n++;
			return true;
		}
		int MaxBucketSize()
		{
			int max = 0;
			for (int i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				int count = 0;
				while (cur)
				{
					count++;
					cur = cur->_next;
				}
				if (max < count) max = count;
			}
			return max;
		}

	private:
		vector<Node*> _tables;
		size_t _n = 0;
	};

	void HashBucketTest1()
	{
		int a[] = { 3, 33, 2, 13, 5, 12, 1002 };
		HashBucket :: HashTable<int, int> ht;
		for (auto e : a)
		{
			ht.Insert(make_pair(e, e));
		}
		ht.Insert(make_pair(15, 15));
		ht.Insert(make_pair(25, 15));
		ht.Insert(make_pair(35, 15));
		ht.Insert(make_pair(45, 15));

		ht.Erase(12);	
		ht.Erase(3);


	}

	void HashBucketTest2()
	{
		HashBucket::HashTable<string, string> ht;
		
		ht.Insert(make_pair("sort", "排序"));
		ht.Insert(make_pair("left", "左边"));
		ht.Insert(make_pair("right", "右边"));

	}
	void HashBucketTest3()
	{
		HashBucket::HashTable<int, int> ht;
		srand(time(0));
		int N = 1000;
		for (int i = 0; i < N; ++i)
		{
			int x = rand();
			ht.Insert(make_pair(x, x));
		}
		cout << ht.MaxBucketSize() << endl;
	}
}