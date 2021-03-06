#ifndef _ANOTHERSTL_VECTOR_
#define _ANOTHERSTL_VECTOR_

#include <iterator>
#include <memory>
#include "astl\iterator\iterator.hpp"
#include "astl\allocator\simpleAllocator.hpp"
#include "astl\allocator\construct.hpp"
#include "astl\allocator\initialize.hpp"
#include "astl\algorithm\modify_algo.hpp"
#include "astl\algorithm\minmax_algo.hpp"

#include <algorithm>
#include <exception>
#include <stdexcept>

// C++98
namespace anotherSTL
{

	#define DEFAULT_VECTOR_SIZE 20
	#define DEFAULT_VECTOR_INCREMENTAL_RATIO 2
		


	// TODO: add allocator
	//template<typename T>
	template<typename T, typename Alloc = simpleAllocator<T>>	
	class vector
	{
	public:
		// typedef.
		typedef T									value_type;
		typedef value_type&							reference;
		typedef value_type*							iterator;
		typedef value_type*							pointer;
		typedef size_t								size_type;
		typedef const value_type&					const_reference; // TODO: check if we need this
		typedef const T*							const_iterator; // TODO: check if we need this
		typedef const T*							const_pointer;
		typedef simple_alloc<T, Alloc>				allocator_type;

	public:
		// ctor.
		vector() : alloc(allocator_type()), start_iterator(0), end_iterator(0), storage_end_iterator(0) { }
		vector(size_type n, const value_type& val) { initialize_n_value(n, val); }
		vector(int n, const value_type& val) { initialize_n_value(n, val); }
		vector(long n, const value_type& val) { initialize_n_value(n, val); }

		vector(const vector& x) { initialize_by_iterator_range(x.begin(), x.end()); }



		// TODO: this can definitely be improved depending on InputIterator type. Do it later after ite is created. 
		template<typename InputIterator>
		vector(InputIterator first, InputIterator second) { initialize_by_iterator_range(first, second); }

		// dtor.
		~vector() { kill(); }

		// assingment operator.
		vector& operator= (const vector& x)
		{
			vector<T, Alloc> t(x);
			this->swap(t);
			return *this;
		}

		// iterator.
		iterator begin() { return start_iterator; }
		const_iterator begin() const { return start_iterator; }
		iterator end() { return end_iterator; }
		const_iterator end() const { return end_iterator; }

		// capacity 
		size_type size() const { return end() - begin(); }
		size_type capacity() const { return storage_end_iterator - begin(); }
		size_type max_size() const
		{
			// TODO: to make code reuse simpleAllocator::max_size
			return static_cast<size_type>(std::numeric_limits<unsigned int>::max() / sizeof(value_type));
		}
		void resize(size_type n, value_type val = value_type())
		{
			if (n < size())
			{
				anotherSTL::destroy(start_iterator + n, end_iterator);
				end_iterator = start_iterator + n;
			}
			else if (n < capacity())
			{
				anotherSTL::uninitialized_fill_n(end_iterator, n - size(), val);
				end_iterator = start_iterator + n;
			}
			else if (n < max_size())
			{
				reallocate_with_new_capacity(n);
				anotherSTL::uninitialized_fill_n(end_iterator, n - size(), val);
				end_iterator = start_iterator + n;

			}
			else
			{
				// TODO: finalized it ?
				throw std::length_error("resize size is larger than max size of a vector");
			}
		}

		bool empty() const { return start_iterator == end_iterator; }

		void reserve(size_type n)
		{
			if (n > max_size())
			{
				throw std::length_error("resize size is larger than max size of a vector");
			}
			else if (n > capacity())
			{
				reallocate_with_new_capacity(n);
			}
		}

		// element access
		reference operator[] (size_type n)
		{
			return  const_cast<reference>((static_cast<const vector&>(*this)).operator[](n));
		}
		const_reference operator[] (size_type n) const
		{
			return *(start_iterator + n);
		}
		reference at(size_type n)
		{
			return const_cast<reference>(static_cast<const vector<T>&>(*this).at(n));
		}

		const_reference at(size_type n) const
		{
			if (n >= size() || n < 0)
			{
				throw std::out_of_range("index out of range ");
			}
			else
			{
				return this->operator[](n);
			}
		}
		reference front() { return *begin(); }

		const_reference front() const
		{
			return *begin();
		}

		reference back()
		{
			return const_cast<reference>(static_cast<const vector<T>&>(*this).back());
		}

		const_reference back() const
		{
			//if (size() >= 1)
			//{
			return *(end() - 1);
			//}
		}

		//TODO: reverse iterator
		//reverse_iterator rbegin();
		//const_reverse_iterator rbegin() const;

		// modifier
		void assign(size_type n, const value_type& val)
		{
			if (n < capacity())
			{
				clear();

			}
			else if (n < max_size())
			{
				kill();
			}
			else
			{
				throw std::length_error("resize size is larger than max size of a vector");
			}
			vector v(n, val);
			this->swap(v);

		}
		template<typename InputItereator>
		void assign(InputItereator first, InputItereator last)
		{
			ptrdiff_t n = anotherSTL::distance(first, last);
			if (n < static_cast<ptrdiff_t>(capacity()))
			{
				clear();
			}
			else if (n < static_cast<ptrdiff_t>(max_size()))
			{
				kill();
			}
			else
			{
				throw std::length_error("resize size is larger than max size of a vector");
			}
			vector v(first, last);
			this->swap(v);
		}

		void push_back(const value_type& val)
		{
			insertToEnd(val);
		}

		void pop_back()
		{
			// undefine behaviour: if size is empty, behaviour is undefined
			destroy(--end_iterator);
		}

		iterator insert(iterator position, const value_type& val)
		{
			if (size() == capacity())
			{
				iterator oldStart = start_iterator;
				iterator oldEnd = end_iterator;
				iterator oldStorageEnd = storage_end_iterator;

				size_t newSize = size() * DEFAULT_VECTOR_INCREMENTAL_RATIO;
				iterator startNew = alloc.allocate(newSize);
				ptrdiff_t n = position - begin();
				iterator endTemp = uninitialized_copy(begin(), position, startNew);
				construct(endTemp++, val);
				iterator endTemp1 = uninitialized_copy(position, end(), endTemp);

				// destroy
				destroy(oldStart, oldEnd);
				alloc.deallocate(oldStart, oldStorageEnd - oldStart);

				start_iterator = startNew;
				end_iterator = endTemp1;
				storage_end_iterator = startNew + newSize;

				return startNew + n;
			}
			else
			{
				pointer it = copy_backward(position + 1, end(), end() + 1);
				construct(position, val);
				return position;
			}
		}

		void insert(iterator position, size_type n, const value_type& val)
		{
			size_t requiredSize = size() + n;
			if (requiredSize > max_size())
			{
				throw std::length_error("no enough storage to store n more values ");
			}
			else if (requiredSize >= capacity())
			{
				iterator oldStart = start_iterator;
				iterator oldEnd = end_iterator;
				iterator oldStorageEnd = storage_end_iterator;

				size_t newSize = anotherSTL::min(requiredSize * DEFAULT_VECTOR_INCREMENTAL_RATIO, max_size());

				iterator startNew = alloc.allocate(newSize);
				iterator endTemp = uninitialized_copy(begin(), position, startNew);
				while (n > 0)
				{
					construct(endTemp++, val);
					--n;
				}
				iterator endTemp1 = uninitialized_copy(position, end(), endTemp);

				// destroy
				destroy(oldStart, oldEnd);
				alloc.deallocate(oldStart, oldStorageEnd - oldStart);

				start_iterator = startNew;
				end_iterator = endTemp1;
				storage_end_iterator = startNew + newSize;
			}
			else
			{
				iterator newEnd = end() + n;
				pointer it = copy_backward(position + 1, end(), newEnd);
				while (n > 0)
				{
					construct(position++, val);
					--n;
				}
				end_iterator = newEnd;
			}
		}

		template<typename InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			ptrdiff_t n = anotherSTL::distance(first, last); // TODO: should this std::distance or anotherSTL::distance?????
			size_t requiredSize = size() + n;
			if (requiredSize > max_size())
			{
				throw std::length_error("no enough storage to store n more values ");
			}
			else if (requiredSize >= capacity())
			{
				size_t newSize = anotherSTL::min(requiredSize * DEFAULT_VECTOR_INCREMENTAL_RATIO, max_size());

				iterator startNew = alloc.allocate(newSize);
				iterator endTemp = uninitialized_copy(begin(), position, startNew);
				while (first != last)
				{
					construct(endTemp++, *first);
					++first;
				}
				iterator endTemp1 = uninitialized_copy(position, end(), endTemp);

				start_iterator = startNew;
				end_iterator = endTemp1;
				storage_end_iterator = startNew + newSize;
			}
			else
			{
				iterator newEnd = end() + n;
				pointer it = copy_backward(position, end(), newEnd);
				while (first != last)
				{
					construct(position++, *first);
					++first;
				}
				end_iterator = newEnd;
			}

		}


		void swap(vector& x)
		{
			iterator start = x.start_iterator;
			iterator end = x.end_iterator;
			iterator end_storage = x.storage_end_iterator;

			x.start_iterator = this->start_iterator;
			x.end_iterator = this->end_iterator;
			x.storage_end_iterator = this->storage_end_iterator;

			this->start_iterator = start;
			this->end_iterator = end;
			this->storage_end_iterator = end_storage;
		}

		iterator erase(iterator position)
		{
			return erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last)
		{
			copy(last , end_iterator, first);
			ptrdiff_t n = anotherSTL::distance(last  , end_iterator); // TODO: should this std::distance or anotherSTL::distance?????
			destroy(first + n, end_iterator);
			end_iterator = first + n;
			
			return first;
		}

		void clear()
		{
			anotherSTL::destroy(start_iterator, end_iterator);
		}

		allocator_type get_allocator() const
		{
			return alloc;
		}

	private:
		iterator start_iterator;
		iterator end_iterator;
		iterator storage_end_iterator;
		allocator_type alloc;


		void insertToEnd(const value_type& v)
		{
			size_t newSize;
			if (size() == 0)
			{
				newSize = DEFAULT_VECTOR_SIZE;
				reallocate_with_new_capacity(newSize);
			}
			else if (size() >= capacity())
			{
				newSize = (size()) * DEFAULT_VECTOR_INCREMENTAL_RATIO;
				reallocate_with_new_capacity(newSize);
			}
			
			construct(end(), v);
			++end_iterator;
					
		}

		void initialize_n_value(size_type n, const value_type&v)
		{
			alloc = allocator_type();
			// NOTE: seperation of memory allocation and construction
			iterator start = alloc.allocate(n);
			iterator end = anotherSTL::uninitialized_fill_n(start, n, v);

			start_iterator = start;
			end_iterator = end;
			storage_end_iterator = start + n;
		}

		template<typename InputIterator> 
		void initialize_by_iterator_range(InputIterator first, InputIterator second)
		{
			size_type n = distance(first, second);
			iterator start = alloc.allocate(n);
			iterator end = anotherSTL::uninitialized_copy(first, second, start);

			start_iterator = start;
			end_iterator = end;
			storage_end_iterator = start + n;
		}

		void kill()
		{
			anotherSTL::destroy(start_iterator, end_iterator);
			ptrdiff_t n = distance(start_iterator, storage_end_iterator);
			alloc.deallocate(start_iterator, n);
			start_iterator = NULL;
			end_iterator = NULL;
			storage_end_iterator = NULL;
		}


		void reallocate_with_new_capacity(size_t n)
		{
			iterator start_new = alloc.allocate(n);
			// here assumes that n >= end_iterator - start_iterator
			iterator end_new = anotherSTL::uninitialized_copy(start_iterator, end_iterator, start_new);
			kill();
			start_iterator = start_new;
			end_iterator = end_new;
			storage_end_iterator = start_new + n;
		}

		
	};

	template<typename T, typename Alloc>
	bool operator == (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<typename T, typename Alloc>
	bool operator != (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(rhs == lhs);
	}

	template<typename T, typename Alloc>
	bool operator< (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		// todo
	}

	template<typename T, typename Alloc>
	bool operator>= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename T, typename Alloc>
	bool operator> (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs) && !(lhs == rhs);
	}

	template<typename T, typename Alloc>
	bool operator<= (const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template<typename T, typename Alloc>
	void swap(vector<T, Alloc>& lhs, vector<T, Alloc>& rhs)
	{
		//todo:
	}

}

#endif