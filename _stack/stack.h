#pragma once
#include<iostream>
#include<vector>
#include<list>
using namespace std;

namespace xupt
{

	template<class T, class Container = vector<int>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		const T top()
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



	void stack_test1()
	{
		stack<int> st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(5);

		while (!st.empty())
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
}
