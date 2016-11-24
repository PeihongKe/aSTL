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

	template<typename ForwardIterator, typename Size, typename T>
	ForwardIterator uninitialize_fill_n(ForwardIterator first, Size n, const T&v)
	{
		return _uninitialize_fill_n(first, n, v, value_type(first));
	}

	template<typename ForwardIterator, typename Size, typename T, typename T1>
	ForwardIterator _uninitialize_fill_n(ForwardIterator first, Size n, const T&v, T1*)
	{
		typedef typename type_traits<T1>::is_POD_type isPOD;
		return _uninitialize_fill_n_by_category(first, n, v, isPOD());
	}

	template<typename ForwardIterator, typename Size, typename T>
	ForwardIterator _uninitialize_fill_n_by_category(ForwardIterator first, Size n, const T&v, _true_type)
	{
		return fill_n(first, n, v);
	}

	template<typename ForwardIterator, typename Size, typename T>
	ForwardIterator _uninitialize_fill_n_by_category(ForwardIterator first, Size n, const T&v, _false_type)
	{
		while (n-- > 0)
		{
			// use copy ctor to construct for the uninitialize 
			construct(get_pointer(first++), v);
		}
		return first;
	}

	// depending on the value type of forward iterator
	template<typename ForwardIterator, typename T>
	inline void uninitialize_fill(ForwardIterator first, ForwardIterator last, const T&v)
	{		
		_uninitialized_fill(first, last, v, value_type(first));
	}

	template<typename ForwardIterator, typename T, typename T1>
	inline void _uninitialized_fill(ForwardIterator first, ForwardIterator last, const T& v, T1*)
	{
		typedef typename type_traits<T1>::is_POD_type isPOD;
		_uninitialize_fill_by_isPOD(first, last, v, isPOD());
	}

	// is_POD: cpy ctor = cpy assignment ctor; dtor is trivial
	template<typename ForwardIterator, typename T>
	inline void _uninitialize_fill_by_isPOD(ForwardIterator first, ForwardIterator last, const T&v, _true_type)
	{
		fill(first, last, v);
	}
	
	template<typename ForwardIterator, typename T>
	inline void _uninitialize_fill_by_isPOD(ForwardIterator first, ForwardIterator last, const T&v, _false_type)
	{
		while (first != last)
		{
			construct(get_pointer(first++), v);			
		}
	}



}





#endif

