#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

namespace xupt
{
	template<class T>
	struct list_node
	{
		list_node* _prev;
		list_node* _next;
		T _data;

		list_node(const T& x = T())
			:_prev(nullptr)
			,_next(nullptr)
			,_data(x)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct _list_iterator
	{
		typedef list_node<T>  node;
		typedef _list_iterator<T, Ref, Ptr>  self;
		node* _node;
		_list_iterator(node* n)
			:_node(n)
		{}
		Ref operator *()
		{
			return _node->_data;
		}

		Ptr operator ->()
		{
			return &_node->_data;
		}
		self& operator ++()
		{
			_node = _node->_next;
			return *this;
		}
		self& operator --()
		{
			_node = _node->_prev;
			return *this;
		}
		bool operator != (const self& s)
		{
			return _node != s._node;
		}
		bool operator == (const self& s)
		{
			return _node == s._node;
		}
	};

	template<class T> 
	struct list
	{
		typedef list_node<T> node;
		
	public:
		typedef _list_iterator<T, T&, T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}
		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_init();
			Iterator it = first;
			while (it != last)
			{
				push_back(*first);
				++it;
			}
		}

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		list(const list<T>& it)
		{
			//empty_init();
			//for (auto e : it)
			//{
			//	push_back(e);
			//}
			list<T> tmp(it.begin(), it.end());
			swap(tmp);
		}


		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		list<T>& operator = (list<T>& it)
		{
			swap(it);
			return *this;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}
		void push_back(const T& x)
		{
			//node* tail = _head->_prev;
			//node* new_node = new node(x);

			//tail->_next = new_node;
			//new_node->_prev = tail;
			//new_node->_next = _head;
			//_head->_prev = new_node;
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void insert(iterator pos, const T& x)
		{
			node* cur = pos._node;
			node* prev = cur->_prev;

			node* new_node = new node(x);

			prev->_next = new_node;
			new_node->_prev = prev;
			new_node->_next = cur;
			cur->_prev = new_node;
		}

		void pop_front()
		{
			erase(begin());
		}

		void pop_back()
		{
			erase(--end());
		}
		
		iterator erase(iterator pos)
		{
			assert(pos != end());
			node* prev = pos._node->_prev;
			node* next = pos._node->_next;

			prev->_next = next;
			next->_prev = prev;

			delete pos._node;

			return iterator(next);
		}

	private:
		node* _head;

	};

	template<class T>
	void print_list(const list<T> & l1)
	{
		list<int> :: const_iterator it = l1.begin();
		while (it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}



	void list_test1()
	{
		list<int> l1;
		l1.push_back(1);
		l1.push_back(2);
		l1.push_back(3);
		l1.push_back(4);
		l1.push_back(5);

		list<int> :: iterator it = l1.begin();
		while(it != l1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : l1)
		{
			cout << e << " ";
		}
		cout << endl;

		print_list(l1);
	}

	struct AA
	{
		int a1;
		int a2;

		AA(int a = 0, int b = 0)
			:a1(a)
			,a2(b)
		{}
	};

	void list_test2()
	{
		list<AA> t1;
		t1.push_back(AA(1, 2));
		t1.push_back(AA(2, 3));
		t1.push_back(AA(3, 4));


		list<AA> t2(t1.begin(), t1.end());
		list<AA> ::iterator it = t2.begin();
		while (it != t2.end())
		{
			cout << it->a1 << ':' << it->a2 << endl;
			++it;
		}
		t2 = t1;

		list<AA> ::iterator it2 = t2.begin();
		while (it2 != t2.end())
		{
			cout << it2->a1 << ':' << it2->a2 << endl;
			++it2;
		}
	}





};

