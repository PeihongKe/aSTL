#ifndef _iterator_
#define _iterator_

#include "iteratorUtil.hpp"

namespace anotherSTL
{
	template<typename Category, typename T, typename Distance = ptrdiff_t,
		typename Pointer = T*, typename Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Distance	difference_type;
		typedef Category	iterator_category;
	};


	template<typename T>
	struct random_access_iterator : public iterator<random_access_iterator_tag, T>
	{
	private:
		iterator _it_;
	public:
		random_access_iterator():_it_(nullptr){}
		random_access_iterator(const random_access_iterator& rhs): _it_(rhs.it){}
		random_access_iterator& operator=(const random_access_iterator& rhs)
		{
			if (this != &rhs)
			{
				this->_it_ = rhs._it_;
			}
			return *this;
		}
		random_access_iterator& operator++ () { ++_it_; return *this; }
		random_access_iterator operator++(int) { random_access_iterator temp(*this); operator++(); return temp; }
		bool operator==(const random_access_iterator& rhs) { return this->_it_ == rhs._it_;  }
		bool operator!=(const random_access_iterator& rhs) { return true; }
		value_type operator*() { return *_it_; }
	};

	//template<typename InputIterator class Distance>
	//void advance(InputIterator& it, Distance n);

	template<typename InputIterator>
	inline typename iterator_traits<InputIterator>::difference_type
		__distance(InputIterator first, InputIterator last, input_interator_tag)
	{
		iterator_traits<InputIterator>::difference_type n = 0;
		while (first != last)
		{
			++first;
			++n;
		}
		return n;
	}

	template<typename RandomAccessIteraotr>
	inline typename iterator_traits<RandomAccessIteraotr>::difference_type
		__distance(RandomAccessIteraotr first, RandomAccessIteraotr last, random_access_iterator_tag)
	{
		return last - first; 
	}

	template<typename InputIterator>
	typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last)
	{
		typedef typename iterator_traits<InputIterator>::iterator_category category;
		__distance(first, second, tag());
	}

 
}



#endif // 

