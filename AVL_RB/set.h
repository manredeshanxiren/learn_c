#pragma once


#include "RBTree.h"

namespace xupt
{

	template<class K>
	class set
	{
	public:
		
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:

		typedef typename RBTree<K, K, SetKeyOfT> :: const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT> :: const_iterator const_iterator;


		pair<iterator, bool> Insert(const K& key)
		{
			return _t.Insert(key);
		}

		iterator begin()
		{
			return _t.begin();
		}

		iterator end()
		{
			return _t.end();
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};


	void Test_set1()
	{
		int a[] = { 16, 3, 7, 11, 9, 26,18,14,15 };
		set<int> s;
		for (auto e : a)
		{
			s.Insert(e);
		}
		//s.Insert(1);
		//s.Insert(2);
		//s.Insert(3);

		set<int> ::iterator cur = s.begin();
		while (cur != s.end())
		{
			cout << *cur << " ";
			++cur;
		}
		cout << endl;
	}


}

