#ifndef _ANOTHERSTL_INITIALIZE_
#define _ANOTHERSTL_INITIALIZE_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
#include "astl\allocator\construct.hpp"


namespace anotherSTL
{ 
	//TODO: specialized it 
	template<typename InputIterator, typename ForwardIterator>
	inline void uninitialized_copy(InputIterator first1, InputIterator last1, ForwardIterator first2)
	{
		while (first1 != last1)
		{
			construct(get_pointer(first2), *first1);
			++first1;
		}
	}



}





#endif

