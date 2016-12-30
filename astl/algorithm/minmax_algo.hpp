#ifndef _ANOTHERSTL_MINMAX_
#define _ANOTHERSTL_MINMAX_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
#include "astl\base\type_traits.hpp"
#include "astl\allocator\construct.hpp"
#include <string>

namespace anotherSTL
{ 

	template<typename T>
	const T& max(const T&a, const T& b)
	{
		return a < b ? b : a;
	}
	
	template<typename T>
	const T& min(const T&a, const T& b)
	{
		return a < b ? a : b;
	}

	template<typename T, typename Compare>
	const T& max(const T&a, const T& b, Compare comp)
	{
		return comp(a,b) ? b : a;
	}

	template<typename T, typename Compare>
	const T& min(const T&a, const T& b, Compare comp)
	{
		return comp(a, b) ? a : b;
	}
}





#endif

