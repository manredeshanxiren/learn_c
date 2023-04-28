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
			_capacity = _size == 0 ? 3 : _size;
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
		void resize(size_t n, char ch = '\0')
		{
			if (n < _size)
			{	
				_size = n;
				_str[n] = '\0';
			}
			else if(n > _size)
			{
				if (n > _capacity)
				{
					reserve(n);
				}
				int i = _size;
				while (i < n)
				{
					_str[i] = ch;
					++i;
				}
				_size = n;
				_str[n] = '\0';
			}
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size + 1 > _capacity)
			{
				reserve(2 * _capacity);
			}
			////错误问题会导致死循环
			//size_t end = _size;
			//while (end > pos)
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			size_t end = _size + 1;
			while (end > pos)
			{
				_str[end] = _str[end - 1];
				--end;
			}
			_str[pos] = ch;
			++_size;

			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			//挪动数据
			size_t end = _size + len;
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			while (end - len  + 1 > pos)
			{
				_str[end] = _str[end - len];
				--end;
			}
			_size += len;
			//拷贝数据
			strncpy(_str + pos, str, len);
			return *this;
		}
		string& erase(size_t pos, size_t len = npos)
		{
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}
		void reserve(size_t n)
		{
			char* temp = new char[n + 1];
			strcpy(temp, _str);
			delete[] _str;
			_str = temp; 
			_capacity = n;
		}
		void push_back(char ch)
		{
			//if (_size + 1 > _capacity)
			//{
			//	reserve(2 * _capacity);
			//}
			//_str[_size] = ch;
			//++_size;
			//_str[_size] = '\0';
			////apend(&ch);
			insert(_size, ch);
		}
		void apend(const char* str)
		{
			//int len = strlen(str);
			//if (_size + len > _capacity)
			//{
			//	reserve(_size + len);
			//}
			//strcpy(_str + _size, str);
			//_size += len;
			insert(_size, str);
		}

		char* c_str()
		{
			return _str;
		}
		void swap(string& s)
		{
			std::swap(_str, s._str);
			std::swap(_size, s._size);
			std::swap(_capacity, s._capacity);
		}

		size_t find(char ch, size_t pos = 0)
		{
			assert(pos <= _size);
			for (int i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos <= _size);
			
			char* p = strstr(_str + pos, str);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		 
		string& operator +=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& operator +=(const char* str)
		{
			apend(str);
			return *this;
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
		bool operator<(const string& s) const
		{
			return strcmp(_str, s._str) < 0;
		}
		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}
		bool operator>(const string& s) const
		{
			return !(*this < s  && *this == s);
		}
		bool operator>=(const string& s) const
		{
			return *this > s || *this == s;
		}
		bool operator<=(const string& s) const
		{
			//这里给函数加上const才可以交换s和*this的值
			//因为不加const的话相当于是用s去调==的函数
			//但是因为s是一个const类型的，所以是权限的放大
			//所以结论就是对于不修改成员变量的函数最好加上const
			return *this < s || s == *this;
		}
		bool operator!=(const string& s) const
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

		 static const size_t npos;
	};

	const size_t string :: npos = -1;
	ostream& operator << (ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out  << ch;
		}
		return out;
	}

	istream& operator >> (istream& in,  string& s)
	{
		s.clear();
		char ch = in.get();
		char buff[128];
		size_t i = 0;
		while (ch != ' ' && ch != '\n')
		{
				buff[i++] = ch;
				if (i == 127)
				{
						buff[127] = '\0';
						s += buff;
						i = 0;
				}	
			
				ch = in.get();
		}
		if (i != 0)
		{
			buff[i] = '\0';
			s += buff;
		}
		return in;
	}


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
		s2.push_back('x');
		s2 += 'x';
		cout << s2.c_str() << endl;
		//s2.apend(" hello srting");
		s2 += " hello string";
		cout << s2.c_str() << endl;

		s2.resize(40, 'e');
		cout << s2.c_str() << endl;
		s2.resize(30);
		cout << s2.c_str() << endl;
		s2.insert(0, 'x');
		cout << s2.c_str() << endl;
		s2.insert(10, "yyy");
		cout << s2.c_str() << endl;
		s2.insert(0, "yyy");
		cout << s2.c_str() << endl;
		s2.insert(3, "xxxxxx");
		cout << s2.c_str() << endl;

		s2.erase(2, 3);
		cout << s2.c_str() << endl;

	}
	
	//流插重载必须实现成友元函数？ 不对
void test_string5()
{
	string s1("0123456789");
	s1[3] = '\0';
	cout << s1 << endl;
	cin >> s1;
	cout << s1 << endl;



}
}

