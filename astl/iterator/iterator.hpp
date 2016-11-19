#ifndef _ANOTHERSTL_ITERATOR_
#define _ANOTHERSTL_ITERATOR_

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


	template<typename InputIterator, typename Distance >
	inline void __advance(InputIterator& it, Distance n, input_interator_tag)
	{
		//TODO: how about n is negative, is this possible
		while (n-- > 0)
		{
			++it;
		}
	}

	template<typename BiDirectionaryIterator, typename Distance>	
	inline void __advance(BiDirectionaryIterator& first, Distance n, bidirectional_iterator_tag)
	{
		if (n > 0)
		{
			while (n-- > 0){++it;}
		}
		else
		{
			while (n++ < 0){--it;}
		}
	}


	template<typename InputIterator, typename Distance >
	inline void __advance(InputIterator& it, Distance n, random_access_iterator_tag)
	{
		it += n;
	}

	template<typename InputIterator, class Distance>
	inline void advance(InputIterator& it, Distance n)
	{		
		__advance(it, n, category(it));
	}

	// TOCHECK: how about output iterator
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
	inline typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator second)
	{
		return __distance(first, second, category(first));
	}

 
}



#endif // 

