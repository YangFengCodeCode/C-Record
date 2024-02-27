#pragma once

template<class Iterator, class Ref, class Ptr>

struct ReverseIterator
{
	typedef ReverseIterator<Iterator, Ref, Ptr> Self;
	Iterator cur;
	ReverseIterator(Iterator it)
		:cur(it)
	{}


	Self& operator++()
	{
		--cur;
		return *this;
	}

	Ref operator*()
	{
		Self tmp = cur;
		--tmp;
		return *tmp;
	}

	bool operator !=(const Self& s)
	{
		cur != s.cur;
	}

};
