#ifndef _ANOTHERSTL_MODIFY_
#define _ANOTHERSTL_MODIFY_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
 
#include "astl\base\type_traits.hpp"
#include "astl\allocator\construct.hpp"
#include <string>

namespace anotherSTL
{ 

	inline char* copy(const char* first1, const char* last1, char* first2)
	{
		size_t size = last1 - first1;
		memmove(first2, first1, size);
		return first2 + size;
	}	 

	template<typename InputIterator, typename OutputIterator>
	inline OutputIterator copy(InputIterator first1, InputIterator last1, OutputIterator first2)
	{
		_copy_functor<InputIterator, OutputIterator> copy_f;
		return copy_f(first1, last1, first2);
	}

	// So that particial specilization is possible
	template<typename InputIterator, typename OutputIterator>
	struct _copy_functor
	{

		inline OutputIterator operator() (InputIterator first1, InputIterator last1, OutputIterator first2)
		{
			typedef typename iterator_traits<InputIterator>::iterator_category category;
			return _copy_by_category(first1, last1, first2, category());
		}
	};

	// specialization for pointers
	template<typename T>
	struct _copy_functor<T*, T*>
	{
		inline T* operator() (T* first1, T* last1, T* first2)
		{
			typedef type_traits<T>::has_trivial_assignment_ctr has_trivial_assignment_ctr;
			return _copy_by_trivial_assign_ctr_4_ptr(first1, last1, first2, has_trivial_assignment_ctr());
		}
	};

	// specialization for pointers
	template<typename T>
	struct _copy_functor<const T*, T*>
	{
		inline T* operator() (const T* first1, const T* last1, T* first2)
		{
			typedef type_traits<T>::has_trivial_assignment_ctr has_trivial_assignment_ctr;
			return _copy_by_trivial_assign_ctr_4_ptr(first1, last1, first2, has_trivial_assignment_ctr());
		}
	};

	// trivial assignment operator (iterators are points only now)
	template<typename T>
	inline T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _true_type)
	{	
		size_t size = last1 - first1;
		memmove(first2, first1, sizeof(T)* size);
		return first2 + size;
	}

	// non-trivial assignment operator (iterators are points only now)
	template<typename T>
	inline T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _false_type)
	{
		return _copy_by_category(first1, last1, first2, random_access_iterator_tag());
	}

	template<typename InputIterator, typename OutputIterator>
	inline OutputIterator _copy_by_category(InputIterator first1, InputIterator last1, OutputIterator first2, random_access_iterator_tag)
	{
		for (ptrdiff_t i = 0; i < last1 - first1; ++i, ++first2)
		{
			*(first2 ) = *(first1+i);
		}
		return first2;
	}

	template<typename InputIterator, typename OutputIterator>
	inline OutputIterator _copy_by_category(InputIterator first1, InputIterator last1, OutputIterator first2, input_interator_tag)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			*(first2) = *first1;
		}
		return first2;
	}




}





#endif

