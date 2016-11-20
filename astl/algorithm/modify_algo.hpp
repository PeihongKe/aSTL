#ifndef _ANOTHERSTL_MODIFY_
#define _ANOTHERSTL_MODIFY_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
 
#include "astl\base\type_traits.hpp"
#include "astl\allocator\construct.hpp"


namespace anotherSTL
{ 
	//TODO: specialized it 
	template<typename InputIterator, typename OutputIterator>
	OutputIterator copy(InputIterator first1, InputIterator last1, OutputIterator first2)
	{
		return _copy_1(first1, last1, first2, value_type(first1));
	}

	template<typename InputIterator, typename OutputIterator, typename T>
	OutputIterator _copy_1(InputIterator first1, InputIterator last1, OutputIterator first2, T*)
	{
		typedef type_traits<T>::is_POD isPOD;
		return _copy_2(first1, last1, first2, isPOD());
	}

	// TODO: implement
	template<typename InputIterator, typename OutputIterator>
	OutputIterator _copy_2(InputIterator first1, InputIterator last1, OutputIterator first2, _false_type)
	{	
		while (first1 != last1)
		{

		}
		return NULL;
	}


	//TODO: implement
	template<typename InputIterator, typename OutputIterator>
	OutputIterator _copy_2(InputIterator first1, InputIterator last1, OutputIterator first2, _true_type)
	{
		return NULL;
	}

}





#endif

