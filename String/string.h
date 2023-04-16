#pragma once
#include<string.h>
#include<iostream>
#include<assert.h>

using namespace std;
namespace xupt
{
	class string
	{
	public:

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin() const 
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
		//string()
		//	:_str(new char [ 1 ])
		//	, _size(0)
		//	,_capacity(0)
		//{
		//	_str[0] = '\0';
		//}
		//string(const char* str = nullptr)
		//string(const char* str = '\0')
		//string(const char* str = "\0")
		string(const char* str = "")
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];//+1因为要多以\0
			strcpy(_str, str);
		}
		string(const string& s)
			:_size(s._size)
			,_capacity(s._capacity)
		{
			_str = new char[_capacity + 1];
			strcpy(_str, s._str);
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_capacity = 0;
			_size = 0;
		}
	
		char* c_str()
		{
			return _str;
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		//用于常量的下标
		const char& operator[]( size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}
		bool operator<(const string& s)
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator==(const string& s)
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator>(const string& s)
		{
			return !(*this < s  && *this == s);
		}
		bool operator>=(const string& s)
		{
			return *this > s || *this == s;
		}
		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}
		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		string& operator=(const string& s)
		{
			if (this != &s)
			{
				//delete[] _str;
				//_str = new char[_capacity + 1];
				//strcpy(_str, s._str);
				//_capacity = s._capacity;
				//_size = s._size;

				char* temp = new char[_capacity + 1];
				strcpy(temp, s._str);
				delete[] _str;
				_str = temp;
				_capacity = s._capacity;
				_size = s._size;
			}
			return *this;
		}

		size_t size() const
		{
			return _size;
		}




	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};





	//构造，[]运算符重载
	void test_string1()
	{
		string s1;
		string s2("hello xupt");

		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;

		s2[0]++;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	//赋值
	void test_string2()
	{
		string s1("s1");
		string s2("s2");

		string s3("s3");

		//s3[0]++;
		//cout << s1.c_str() << endl;
		//cout << s2.c_str() << endl;
		//cout << s3.c_str() << endl;

		s1 = s3;
		s2 = s2;
		cout << s1.c_str() << endl;
		cout << s2.c_str() << endl;
	}

	void Print(const string& s)
	{
		//for (int i = 0; i < s.size(); i++)
		//{
		//	cout << s[ i ];
		//}
		for (auto ch : s)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
	//常量下标的测试
	//迭代器---范围for
	void test_string3()
	{
		string s1("hello xupt");
		Print(s1);
		cout << endl;


		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			//(*it)--;
			cout << *it << " ";
			++it; 
		}
		cout << endl;

		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}

	//比较字符串
	//> < == 运算符重载
	void test_string4()
	{
		string s1("hello xupt");
		string s2("hello xupt");
		string s3("*****");
		cout << (s1 == s2) << endl;


	}
}