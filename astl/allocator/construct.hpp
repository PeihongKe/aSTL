#ifndef _ANOTHERSTL_CONSTRUCT_
#define _ANOTHERSTL_CONSTRUCT_

#include <new>
#include "astl\iterator\iterator_traits.hpp"


namespace anotherSTL
{

	template<typename T1, typename T2>
	inline void construct(T1 *p, const T2& value)
	{
		new(p) T1(value);
	}

	template<typename T>
	inline void destroy(T* p)
	{
		p->~T();
	}


	//TODO: cneed to be specialized for trades with trivial dtor
	template<typename FwdIterator>
	inline void destroy(FwdIterator from, FwdIterator to)
	{
		while (from != to)
		{
			destroy(get_pointer(from));
			++from;
		}
	}

}


#endif

