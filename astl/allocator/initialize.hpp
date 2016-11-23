#ifndef _ANOTHERSTL_INITIALIZE_
#define _ANOTHERSTL_INITIALIZE_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
#include "astl\base\type_traits.hpp"
#include "astl\allocator\construct.hpp"
#include "astl\algorithm\modify_algo.hpp"


namespace anotherSTL
{ 
	//TODO: specialized it 
	template<typename InputIterator, typename ForwardIterator>
	inline ForwardIterator uninitialized_copy(InputIterator first1, InputIterator last1, ForwardIterator first2)
	{
		return _uninitialized_copy_1(first1, last1, first2, value_type(first1));
	}

	template<typename InputIterator, typename ForwardIterator, typename T>
	inline ForwardIterator _uninitialized_copy_1(InputIterator first1, InputIterator last1, ForwardIterator first2, T*)
	{
		typedef typename type_traits<T>::is_POD_type isPOD;
		return _uninitialized_copy_2(first1, last1, first2, isPOD());
	}

	template<typename InputIterator, typename ForwardIterator>
	inline ForwardIterator _uninitialized_copy_2(InputIterator first1, InputIterator last1, ForwardIterator first2, _true_type)
	{
		return copy(first1, last1, first2);
	}

	// TODO: need  commit and roll back transaction
	// TODO: do we need this, can we just called copy as well
	template<typename InputIterator, typename ForwardIterator>
	inline ForwardIterator _uninitialized_copy_2(InputIterator first1, InputIterator last1, ForwardIterator first2, _false_type)
	{
		while (first1 != last1)
		{
			construct(get_pointer(first2), *first1);
			++first1;
			++first2;
		}
		return first2;
	}




}





#endif

