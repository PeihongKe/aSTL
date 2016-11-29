#ifndef _ANOTHER_STL_SIMPLE_ALLOCATOR_
#define _ANOTHER_STL_SIMPLE_ALLOCATOR_
#include "astl\allocator\construct.hpp"
#include <limits>
#include <iostream>

namespace anotherSTL
{
	// standard interface for an allocator
	template<typename T>
	class simpleAllocator
	{
	public:
		typedef T				value_type;
		typedef T*				pointer;
		typedef const T*		const_pointer;
		typedef T&				reference;
		typedef const T&		const_reference;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;

		//TODO: double check the usage of this defintion
		template< class U > struct rebind
		{
			typedef simpleAllocator<U> other;
		};

		simpleAllocator()
		{}

		simpleAllocator(const simpleAllocator&)
		{
		}

		template<typename U>
		simpleAllocator(const simpleAllocator<U>&)
		{

		}

		static pointer allocate(size_type n, const void* hint = 0)
		{
			return anotherSTL::allocate(static_cast<difference_type>(n), static_cast<pointer>(0));
		}

		static void deallocate(pointer p, size_type n)
		{
			anotherSTL::deallocate(p);
		}

		void construct(pointer p, const T& v)
		{
			anotherSTL::construct(p, v);
		}

		void destroy(pointer p)
		{
			anotherSTL::destroy(p);
		}

		pointer address(reference x)
		{
			return static_cast<pointer>(&x);
		}

		const_pointer const_address(const_reference x)
		{
			return static_cast<const_pointer>(&x);
		}

		size_type max_size() const
		{			
			return static_cast<size_type>(std::numeric_limits<unsigned int>::max()/sizeof(value_type));
		}

	};

	template<typename T, class Alloc>
	class simple_alloc
	{
	public:
		static T* allocate(size_t n)
		{
			return 0 == n ? 0 : Alloc::allocate(n * sizeof(T));
		}

		static T* allocate(void)
		{
			return Alloc::allocate(sizeof(T));
		}

		static void deallocate(T *p, size_t n)
		{
			if (0 != n)
			{
				Alloc::deallocate(p, n * sizeof(n));
			}
		}

		static void deallocate(T *p)
		{
			Alloc::deallocate(p, sizeof(T));
		}
	};

}

#endif