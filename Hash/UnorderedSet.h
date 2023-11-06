#pragma once


#include"Hash.h"



namespace xupt
{

	template<class K, class Hash = HashFunc<K>>
	class unordered_set
	{
	public:
		struct SetKeyOfT
		{
		public:
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename HashBucket::HashTable<K, K, SetKeyOfT, Hash> ::const_iterator iterator;
		typedef typename HashBucket::HashTable<K, K, SetKeyOfT, Hash> ::const_iterator const_iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}
		pair<iterator, bool>  insert(const K& key)
		{
			return _ht.Insert(key);
		}

		iterator find()
		{
			return _ht.Find();
		}

		bool erase()
		{
			return _ht.Erase();
		}
	



	private:
		HashBucket :: HashTable<K, K, SetKeyOfT, Hash> _ht;
	};

	void test_unordered_set()
	{
		unordered_set<int> ht;
		ht.insert(1);
		ht.insert(2);
		ht.insert(3);
		unordered_set<int> ::const_iterator it = ht.begin();
		while (it != ht.end())
		{
			cout << *it << endl;
			++it;
		}
		cout << endl;
	}
}