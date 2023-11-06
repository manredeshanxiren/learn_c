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
				//�鿴�Ƿ���Ҫ���ݣ�����size��0.7�ͽ�������
				if (_tables.size() == 0 || _n * 10 / _tables.size() >= 7)
				{
					size_t newsize = _tables.size() == 0 ? 10 : _tables.size() * 2;
					HashTable<K, V> newht;
					newht._tables.resize(newsize);
					//�����ɱ�ӳ�䵽�±�
					for (auto& date : _tables)
					{
						if (date._state == EXIST)
							newht.Insert(date._kv);
					}
					_tables.swap(newht._tables);
				}

				size_t hashi = kv.first % _tables.size();

				//����̽��
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

				//����̽��
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

					//������һȦ��֤�����е�״ֻ̬��EXIST��DELET��״̬
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
		size_t _n = 0; // �洢���ݵĸ���

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


//�ػ�
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
	template<class T>
	struct HashNode
	{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	//ǰ������
	template<class K, class T, class KeyOfT, class Hash>
	class HashTable;

	template<class K, class T, class Ref, class Ptr, class KeyOfT ,class Hash>
	struct _HashIterator
	{
		typedef HashNode<T> Node;
		typedef HashTable<K, T, KeyOfT, Hash> HT;
		typedef _HashIterator<K, T, Ref, Ptr, KeyOfT, Hash> Self;
		typedef _HashIterator<K, T, T&, T*, KeyOfT, Hash> Iterator;

		Node* _node;
		//ѡ��const��Ϊ������const������
		const HT*  _ht;


		//����
		//�����const��ͬ���ĵ�������const������
		_HashIterator(Node* node, const HT* ht)
			:_node(node)
			, _ht(ht)
		{}

		//��������
		//const���������ǹ���
		//��ͨ�������ǿ�������
		_HashIterator(const Iterator& it)
			:_node(it._node)
			, _ht(it._ht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}
		
		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}


		Self& operator++()
		{
			KeyOfT kot;
			Hash hash;
			//��ǰ��Ͱ��û����
			if (_node->_next != nullptr)
			{
				_node = _node->_next;
			}
			else
			{
				//�ù�ϣ���������ǰ��λ��
				size_t hashi = hash(kot(_node->_data)) % _ht->_tables.size();
				hashi++;
				while (hashi < _ht->_tables.size())
				{
					//����ҵ���ǰͰ����ֵ��Ͱ
					if (_ht->_tables[hashi])
					{
						_node = _ht->_tables[hashi];
						break;
					}
					//����Ļ�����Ѱ��
					else
					{
						hashi++;
					}
				}
				//������껹û���ҵ��Ǿ���û��������
				if (hashi == _ht->_tables.size())
				{
					_node = nullptr;
				}
			}
			return *this;
		}

	};



	template<class K, class T, class KeyOfT, class Hash>
	class HashTable
	{

		template<class K, class T, class Ref, class Ptr, class KeyOfT, class Hash>
		friend struct _HashIterator;

		typedef HashNode<T> Node;
	public:
		typedef _HashIterator<K, T, T&, T*, KeyOfT, Hash> iterator;
		typedef _HashIterator<K, T, const T&, const T*, KeyOfT, Hash> const_iterator;

		iterator begin()
		{
			//����Ҫ����hash�����ҵ���һ�����ڵ�����
			Node* cur = nullptr;
			for (int i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				if (cur)
				{
					break;
				}
			}
			//���õ������Ĺ��캯��
			return iterator(cur, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}


		const_iterator begin() const
		{
			//����Ҫ����hash�����ҵ���һ�����ڵ�����
			Node* cur = nullptr;
			for (int i = 0; i < _tables.size(); ++i)
			{
				cur = _tables[i];
				if (cur)
				{
					break;
				}
			}
			//���õ������Ĺ��캯��
			return const_iterator(cur, this);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}
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


		iterator Find(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			if (_tables.size() == 0)
			{
				return end();
			}
			size_t hashi = hash(key) % _tables.size();
			Node* cur = _tables[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
					return iterator(cur, this);
				cur = cur->_next;
			}
			return end();
		}

		bool Erase(const K& key)
		{
			KeyOfT kot;
			Hash hash;
			size_t hashi = hash(key) % _tables.size();
			Node* prev = nullptr;
			Node* cur = _tables[hashi];

			while (cur)
			{
				if (kot(cur) == key)
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
		pair<iterator, bool> Insert(const T & data)
		{
			KeyOfT kot;
			Hash hash;
			iterator it = Find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}
			//�غ�����Ϊ1
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

						size_t hashi = hash(kot(cur->_data)) % newht.size();

						//ͷ�嵽�µı���
						cur->_next = newht[hashi];
						newht[hashi] = cur;

						cur = next;
					}
				}
				_tables.swap(newht);
			}

			//ͷ��
			size_t hashi = hash(kot(data)) % _tables.size();
			Node* newnode = new Node(data);
			newnode->_next = _tables[hashi];
			_tables[hashi] = newnode;
			_n++;
			return make_pair(iterator(newnode, this), true);
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
}