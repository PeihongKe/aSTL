#ifndef _ANOTHERSTL_LIST_
#define _ANOTHERSTL_LIST_
#include "astl\iterator\iterator_traits.hpp"
#include "astl\allocator\simpleAllocator.hpp"
#include "astl\iterator\iterator.hpp"
#include "astl\allocator\simpleAllocator.hpp"
#include "astl\allocator\construct.hpp"

namespace anotherSTL
{
	template<typename T>
	struct __list_node
	{
		typedef __list_node<T>* Pointer;
		Pointer next;
		Pointer prev;
		T data;
	};

	template<typename T, class Ref, class Ptr>
	class __list_iterator
	{
	public:
		typedef __list_iterator<T, T&, T*>			iterator;
		typedef __list_iterator<T, Ref, Ptr>		self;
		typedef bidirectional_iterator_tag			iterator_category;
		typedef T									value_type;
		typedef Ptr									pointer;
		typedef Ref									reference;
		typedef size_t								size_type;
		typedef ptrdiff_t							difference_type;
		typedef __list_node<T>*						link_type;

		link_type node;

		__list_iterator(link_type inp) :node(inp) {}
		__list_iterator() {}
		__list_iterator(const self& inp) : node( inp.node){}

		bool operator==(const self& rhs) const { return node == rhs.node; }
		bool operator!=(const self& rhs) const { return !(this->operator==(rhs)); }

		reference operator*() const { return (*node).data; }
		pointer operator->() const { return &(operator*()); }

		self& operator++() // ++i
		{
			node = (*node).next;
			return *this;
		}

		self operator++(int) // i++
		{
			self temp(*this);
			++*this;
			return temp;
		}

		self& operator--()
		{
			node = (*node).prev;
			return *this;
		}

		self operator--(int)
		{
			self temp(*this);
			--*this;
			return temp;
		}
	};

	template<typename T, typename Alloc = simpleAllocator<T> >
	class list
	{


	public:
		typedef T											value_type;
		typedef simple_alloc<T, Alloc>						allocator_type;

		// as the first attemp just define the default member types for default Alloc
		typedef T&											reference;          // this should be allocator_type::reference
		typedef const T&									const_reference;    // this should be allocator_type::const_reference
		typedef T*											pointer;            // this should be allocator_type::pointer
		typedef const T*									const_pointer;      // this should be allocator_type::const_pointer
		typedef __list_iterator<T, T&, T*>					iterator;
		typedef const __list_iterator<T, T&, T*>			const_iterator;
		// todo : typedef reverse_iterator
		// todo : typedef const_reverse_iterator
		typedef size_t										size_type;
		typedef typename iterator_traits<iterator>::difference_type	difference_type;


	private:
		typedef __list_node<T>*								link_type;
		typedef __list_node<T>								list_node;
		typedef simple_alloc<list_node, simpleAllocator<list_node>>				list_node_allocator_type;

		//iterator endNode;
		list_node* node;
		size_t numOfNodes;
		allocator_type alloc;
		list_node_allocator_type node_alloc;

	public:
		// ctr.
		explicit list(const allocator_type& alloc = allocator_type()): alloc(alloc), node_alloc(list_node_allocator_type())
		{		
			node = node_alloc.allocate();
			node->next = node;
			node->prev = node;
			numOfNodes = 0;
		}

		explicit list(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): alloc(alloc), node_alloc(list_node_allocator_type())
		{
			node = node_alloc.allocate();
			link_type curr = node;
			for (size_t i = 0; i < n; ++i)
			{
				link_type newNode = node_alloc.allocate();	
				++numOfNodes;
				construct(&newNode->data, val);				 
				curr->next = newNode;
				newNode->prev = curr;
				curr = newNode;
			}
			curr->next = endNode;
			node->prev = curr;
		}

		template<class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		{

		}

		list(const list& x)
		{

		}

		~list()
		{
			list_node* curr = node;
			for (size_t i = 0; i < numOfNodes + 1; ++i )
			{
				list_node* next = curr->next;
				node_alloc.deallocate(curr);
				curr = next;
			}

		}

		// iterator
		iterator begin()
		{
			return iterator(node->next);
		}

		const_iterator begin() const
		{

		}

		iterator end()
		{
			return iterator(node);
		}

		const_iterator end() const
		{

		}

		list& operator=(const list& x)
		{

		}


		//reverse_iterator rbegin()
		//{

		//}

		//const_reverse_iterator rbegin() const
		//{

		//}

		// capacity.
		bool empty() const
		{
			return numOfNodes == 0;
		}

		size_type size() const
		{

		}

		size_type max_size() const
		{

		}

		//element access
		reference front()
		{

		}

		const_reference front() const
		{

		}

		reference back()
		{

		}

		const_reference back() const
		{

		}

		// modifier
		template<typename InputIterator>
		void assign(InputIterator first, InputIterator last)
		{

		}

		void assign(size_type n, const value_type& val)
		{

		}

		void push_front(const value_type& val)
		{

		}

		void push_back(const value_type& val)
		{

		}

		void pop_back()
		{

		}

		void push_back()
		{

		}

		// return value: point to the inserted value
		iterator insert(iterator pos, const value_type& val)
		{

		}


		void insert(iterator pos, size_type n, const value_type& val)
		{

		}

		template<class InputIterator>
		void insert(iterator pos, InputIterator first, InputIterator last)
		{

		}

		iterator erase(const_iterator pos)
		{

		}

		iterator erase(const_iterator first, const_iterator last)
		{

		}

		void swap(list& x)
		{

		}

		void resize(size_type n, const value_type& val = value_type())
		{

		}

		void clear()
		{

		}

		// operation
		void splice(iterator pos, list&x)
		{

		}

		void splice(iterator pos, list&x, iterator i)
		{

		}

		void splice(iterator pos, list& x, iterator first, iterator last)
		{

		}

		void remove(const value_type& val)
		{

		}

		template<typename Predicate>
		void remove_if(Predicate pred)
		{

		}

		void unique()
		{

		}

		template<class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{

		}

		void merge(list& x)
		{

		}

		template<typename Compare>
		void merge(list& x, Compare comp)
		{

		}

		void sort()
		{

		}

		template<typename Compare>
		void sort(Compare comp)
		{

		}

		void reverse()
		{

		}

		//observors
		allocator_type get_allocator() const
		{

		}

	};


	// non-member functions
	template<typename T, typename Alloc>
	bool operator==(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{

	}

	template<typename T, typename Alloc>
	bool operator!=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<typename T, typename Alloc>
	bool operator<(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{

	}

	template<typename T, typename Alloc>
	bool operator>=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<typename T, typename Alloc>
	bool operator>(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		return !(lhs <= rhs);
	}

	template<typename T, typename Alloc>
	bool operator<=(const list<T, Alloc>& lhs, const list<T, Alloc>& rhs)
	{
		return (lhs < rhs) && lhs == rhs;
	}

	template<typename T, typename Alloc>
	void swap(list<T, Alloc>& lhs, list<T, Alloc>& rhs)
	{

	}

}

#endif