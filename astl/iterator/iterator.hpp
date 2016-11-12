#ifndef _iterator_
#define _iterator_

#include "iterator_traits.hpp"

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

