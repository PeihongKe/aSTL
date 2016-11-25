#ifndef _ANOTHERSTL_CONSTRUCT_
#define _ANOTHERSTL_CONSTRUCT_

#include <new>
#include "astl\iterator\iterator_traits.hpp"
#include "astl\base\type_traits.hpp"
#include <cstdlib>
#include <climits>


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
	template<typename ForwardIterator>
	inline void destroy(ForwardIterator from, ForwardIterator to)
	{
		_destroy(from, to, value_type(from));
	}

	template<typename ForwardIterator, typename T>
	inline void _destroy(ForwardIterator from, ForwardIterator to, T*)
	{
		typedef typename type_traits<T>::has_trivial_dtor has_trivial_dtor;
		_destroy_by_has_trivial_dtor(from, to, has_trivial_dtor());
	}

	template<typename ForwardIterator>
	inline void _destroy_by_has_trivial_dtor(ForwardIterator from, ForwardIterator to, _true_type)	{	}

	template<typename ForwardIterator>
	inline void _destroy_by_has_trivial_dtor(ForwardIterator from, ForwardIterator to, _false_type) 
	{
		while (from != to)
		{
			destroy(get_pointer(from++));
		}
	}

	template<typename T>
	inline void deallocate(T* add)
	{
		::operator delete(add);
	}

	template<typename T>
	inline T* allocate(ptrdiff_t size, T*)
	{
		std::set_new_handler(0);
		T* temp = static_cast<T*>(::operator new (std::nothrow) (static_cast<size_t>(size * sizeof(T))));
		if (temp == 0)
		{
			std::cerr << "Out of memory"<<std::endl;
			exit(1);
		}
		return temp;
	}

	// standard interface for an allocator
	template<typename T>
	class allocator 
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
		template< class U > struct rebind { typedef allocator<U> other; };

		pointer allocate(size_type n, const void* hint =0)
		{
			return allocate(static_cast<difference_type>(n), static_cast<pointer>(0));
		}

		void deallocate(pointer p, size_type n)
		{
			while(n-- >0)
			{ 
				deallocate(p++);
			}
		}

		void construct(pointer p, const T& v)
		{
			construct(p, v);
		}

		void destroy(pointer p)
		{
			destroy(p);
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
			return static_cast<size_type>(std::UINT_MAX/sizeof(value_type));
		}

	};
	

}


#endif

