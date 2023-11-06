#pragma once

#pragma once
#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

namespace xupt
{

	template<class T, class Container = deque<int>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		const T& front()
		{
			return _con.front();
		}
		const T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}
		bool empty()
		{
			return _con.empty();
		}
	private:
		Container _con;
	};

	void queue_test1()
	{
		queue<int> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(5);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
	}


}
