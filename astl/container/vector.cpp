#include "astl\container\vector.hpp"
#include "astl\allocator\construct.hpp"
#include "astl\allocator\initialize.hpp"
#include "astl\algorithm\modify_algo.hpp"
#include <algorithm>
#include <exception>
#include <stdexcept>



namespace anotherSTL
{
 

 

 
 

	//template<typename T, typename Alloc>
	//void vector<T, Alloc>::destruct()
	//{
	//	anotherSTL::destroy(, end_iterator);
	//}

 

 
 

 
 
 
 
 

	//template<typename T, typename Alloc>
	//void vector<T, Alloc>::insert(iterator postion, size_type n, const value_type& val)
	//{
	//	ensure_enough_more_space(n);
	//	move_tail(position, n);
	//	// TODO: refactor to commond code wtih the constructor
	//	for (size_type i = 0; i < n; ++i)
	//	{
	//		*(position + i) = val;
	//	}
	//}

	//template<typename T, typename Alloc>
	//template<typename InputIterator>
	//void vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
	//{
	//	size_type n = distance(first, last);
	//	ensure_enough_more_space(n);
	//	move_tail(position, n);
	//	// TODO: refactor to commond code wtih the constructor
	//	for (InputIterator curr = first, size_type i = 0; i < n; ++i, ++first)
	//	{
	//		*(position+i) = *curr;
	//	}
	//}


}