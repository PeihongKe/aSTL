#ifndef _ANOTHERSTL_VECTOR_
#define _ANOTHERSTL_VECTOR_

#include <iterator>
#include <memory>
#include "astl\iterator\iterator.hpp"

// C++98
namespace anotherSTL
{

	#define DEFAULT_VECTOR_SIZE 20;
	#define DEFAULT_VECTOR_INCREMENTAL_RATIO 2;


	// TODO: add allocator
	template<typename T>
	class vector
	{
	public:
		// typedef.
		typedef T									value_type;
		typedef T&									reference;
		typedef const T&							const_reference;
		typedef T*									iterator;
		typedef const T*							const_iterator;
		typedef T*									pointer;
		typedef const T*							const_pointer;
		typedef unsigned							size_type;

		// ctor.
		explicit vector();
		explicit vector(size_type n, const value_type& val =value_type());		
		vector(const vector& x);				
		template<typename InputIterator> vector(InputIterator first, InputIterator second);

		// dtor.
		~vector();

		// assingment operator.
		vector& operator= (const vector& x);

		// iterator.
		iterator begin();
		const_iterator begin() const;
		iterator end();
		const_iterator end() const;

		// capacity 
		size_type size() const;
		size_type capacity() const;
		size_type max_size() const;
		void resize(size_type n, value_type val = value_type());
		bool empty() const;
		void reserve(size_type n);

		// element access
		reference operator[] (size_type n);
		const_reference operator[] (size_type n) const;
		reference at(size_type n);
		const_reference at(size_type n) const;
		reference front();
		const_reference front() const;
		reference back();
		const_reference back() const;

		// modifier
		void assign(size_type n, const value_type& val);
		template<typename InputItereator> void assign(InputItereator first, InputItereator last);
		void push_back(const value_type& val);
		void pop_back();
		iterator insert(iterator position, const value_type& val);
		void insert(iterator postion, size_type n, const value_type& val);
		template<typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last);
		void swap(vector& x);

		//iterator erase(iterator position);
		//iterator erase(iterator first, iterator last);
		//void clear();

	private:
		pointer _data_;
		size_type _size_;
		size_type _capacity_;

		void construct(size_type capacity);
		void destruct();

		explicit vector(size_type t);
		bool has_space(size_type n=1);
		bool has_space(size_type n=1) const;
		int last_elem_index();
		int last_elem_index() const;
		void reallocate(size_type n) const;
		void ensure_enough_more_space(size_type n = 1) const;
		size_type available_space() const;
		void move_tail(iterator from, size_type steps);
	};
}

#endif