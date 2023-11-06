#pragma once

#include"Hash.h"



namespace xupt
{

	template<class K, class V, class Hash = HashFunc<K>>
	class unordered_map
	{

	public:
		struct MapKeyOfT
		{
		public:
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};

	public:
		typedef typename HashBucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::iterator iterator;
		typedef typename HashBucket::HashTable<K, pair<const K, V>, MapKeyOfT, Hash>::const_iterator const_iterator;
		

	public:
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

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = insert(make_pair(key, V()));
			return ret.first->second;
		}

		pair<iterator, bool> insert(const pair<const K, V>& kv)
		{
			return _ht.Insert(kv);
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
		HashBucket:: HashTable<K, pair<const K, V>, MapKeyOfT, Hash> _ht;
	};

	void test_unordered_map()
	{
		unordered_map<int, int> ht;
		ht.insert(make_pair(1, 1));
		ht.insert(make_pair(2, 2));
		ht.insert(make_pair(3, 3));
		auto it = ht.begin();
		while (it != ht.end())
		{
			cout << it->first << ':' << it->second << " ";
			++it;
		}
		cout << endl;
		for (auto& m : ht)
		{
			cout << m.first << " ";
		}
	}

	void test_unordered_map2()
	{
		string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };
		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		for (auto& kv : countMap)
		{
			cout << kv.first << ":" << kv.second << endl;
		}
	}
	void test_unordered_map3()
	{
		string arr[] = { "Î÷¹Ï", "Î÷¹Ï", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Æ»¹û", "Î÷¹Ï", "Æ»¹û", "Ïã½¶", "Æ»¹û", "Ïã½¶", "Àæ" };
		unordered_map<string, int> countMap;
		for (auto& e : arr)
		{
			countMap[e]++;
		}

		unordered_map<string, int> ::iterator it = countMap.begin();
		while (it != countMap.end())
		{
			cout << it->first << ":" << it->second << endl;
			++it;
		}
	}
}