#pragma once

namespace xupt
{

	  template<class Iterator,class Ref, class Ptr>
	  struct Reverse_Iterator
	  {
		  Iterator _cur;
		  typedef Reverse_Iterator<Iterator, Ref, Ptr> Self;

		  Reverse_Iterator(const Iterator& it)
			  :_cur(it)
		  {}

		  Ref operator*()
		  {
			  Iterator tmp = _cur;
			  --tmp;
			  return *tmp;
		  }

		  Self& operator++()
		  {
			  --_cur;
			  return *this;
		  }

		  Self& operator--()
		  {
			  ++_cur;
			  return *this;
		  }

		  bool operator!=(const Self& s)
		  {
			  return _cur != s._cur;
		  }

	  };



};
