#pragma once

#include "RBTree.h"

namespace xupt
{

	template<class K, class V>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K&  operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT> :: iterator iterator;

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key, V()));
			return ret->first->second;
		}

		pair<iterator, bool> Insert(const pair<const K, V>& kv)
		{
			return _t.Insert(kv);
		}




	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};


	void Test_map1()
	{
		map<int, int> m;

		m.Insert(make_pair(1 , 1));
		m.Insert(make_pair(2 , 1));
		m.Insert(make_pair(3 , 1));
	}


}
