#pragma once

#include<vector>
#include<iostream>
using namespace std;

namespace xupt
{
	template<class T>
	struct less
	{
		bool operator()(T& a, T& b)
		{
			return a < b;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(T& a, T& b)
		{
			return a > b;
		}
	};


	template <class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue()
			:_con()
		{}

		template<class Iterator>
		priority_queue(Iterator first, Iterator last)
			: _con(first, last)
		{
			for (int root = (_con.size() - 1) / 2; root >= 0; --root)
			{
				AdjustDown(root);
			}
		}

		void push(const T & x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);
		}
		size_t size()
		{
			return _con.size();
		}

		void pop()
		{
			if (_con.empty())
				return;
			swap(_con.front(), _con.back());
			_con.pop_back();
			AdjustDown(0);
		}

		bool empty()
		{
			return _con.empty();
		}

		T& top()
		{
			return _con.back();
		}
	private:
		void AdjustUp(int child)
		{
			Compare _com;
			int parent = (child - 1) >> 1;
			while (child)
			{
				//小堆
				//if (_con[child] < _con[parent])
				if(_com(_con[child], _con[parent]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
				}
				else
				{
					return;
				}
			}
		}

		void AdjustDown(int parent)
		{
			Compare _com;
			//小堆
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				//找到两个孩子节点之中较小的那个
				//if (child + 1 < _con.size() && _con[child] > _con[child + 1])
				if (child + 1 < _con.size() && _com(_con[child], _con[child + 1]))
				{
					child += 1;
				}
				//if (_con[parent] > _con[child])
				if(_com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					return;
				}
			}
		}

	private:
		Container _con;
	};



	void Testpriority_queue()
	{
		priority_queue<int> pq;
		pq.push(1);
		pq.push(2);
		pq.push(3);
		pq.push(4);
		while (pq.size() > 0)
		{
			cout << pq.top() << " ";
			pq.pop();
		}
	}

}
