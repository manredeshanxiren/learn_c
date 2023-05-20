#pragma once
#include<assert.h>
#include<iostream>

using namespace std;
namespace xupt
{
	template <class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef  const T* const_iterator;

		//vector()
		//	:_start(nullptr)
		//	, _finish(nullptr)
		//	, _end_of_storage(nullptr)
		//{}

		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		
		vector()
		{}


		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; ++i)
			{
				push_back(val);
			}
		}


		vector(const vector <T>&  v)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();

			//vector<T> tmp(v.begin(), v.end());
			//swap(tmp);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~vector()
		{
			delete []_start;
			_finish = _end_of_storage = nullptr;
		}


		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		size_t size() const
		{
			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];

				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
					reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				//解决扩容后pos会失效的情况
				pos = _start + len;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = val;
			++_finish;
			return pos;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			iterator end = pos + 1;
			while (end !=  _finish)
			{
				*(end - 1) = *end;
				++end;
			}
			--_finish;
		}
		
		void push_back(const T& x)
		{
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}

			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		bool empty()
		{
			return _start == _finish;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}


		vector <T>& operator = (vector<T>& v)
		{
			_start = new T [v.capacity()];
			for (size_t i = 0; i < v.size(); ++i)
			{
				_start[i] = v._start[i];
			}
			
			_finish = _start + v.size();
			_end_of_storage = _start + v.capacity();
			swap(v);
			return *this;
		}


		vector <T>& operator = (const vector<T>& v)
		{
			if (this != &v) // 防止自己给自己赋值
			{
				vector<T> tmp(v); // 拷贝构造tmp对象
				swap(tmp); // 交换_start，_finish， _endofstorage
			}
			return *this;
		}



	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;


	};


	void func(const vector<int>& v)
	{
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int> :: const_iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}



	void TestVector1()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		func(v1);

		v1.pop_back();
		v1.pop_back();
		v1.pop_back();

		func(v1);

		cout << endl;
	}

	void TestVector2()
	{
		vector<int> v2;
		v2.push_back(1);
		v2.push_back(2);
		v2.push_back(3);
		v2.push_back(4);
		v2.push_back(5);
		v2.resize(3);
		
		func(v2);
		
		v2.resize(6, 4);

		func(v2);
	}


	void TestVector3()
	{
		vector<int> v3;
		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v3.push_back(4);
		v3.push_back(5);	
		
		func(v3);
		v3.insert(v3.end(), 4);

		func(v3);

		v3.erase(v3.end() - 1);
		func(v3);

		v3.erase(v3.begin());
		func(v3);
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows, vector<int>());
			for (size_t i = 0; i < vv.size(); ++i)
			{
				vv[i].resize(i + 1, 0);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	void TestVector4()
	{
		vector<int> v3;
		v3.push_back(1);
		v3.push_back(2);
		v3.push_back(3);
		v3.push_back(4);
		v3.push_back(5);

		func(v3);

		vector<int> v4 = v3;

		func(v4);

		vector<int> v5(v3.begin(), v3.end());

		func(v5);
	}


	void TestVector5()
	{
		vector<vector<int>> ret = Solution().generate(5);
		for (size_t i = 0; i < ret.size(); ++i)
		{
			for (size_t j = 0; j < ret[i].size(); ++j)
			{
				cout << ret[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	
};


