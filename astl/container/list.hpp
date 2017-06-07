#ifndef _ANOTHERSTL_LIST_
#define _ANOTHERSTL_LIST_
#include "astl\iterator\iterator_traits.hpp"

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
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, Ref, Ptr> self;
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef Ptr pointer;
		typedef Ref reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef __list_node<T>* link_type;

		link_type node;

		__list_iterator(link_type inp) :node(inp) {}
		__list_iterator() {}
		__list_iterator(const self& inp) : node( inp.node){}

		bool operator==(const self& rhs) const { return node == rhs.node; }
		bool operator!=(const self& rhs) const { return !(this->operator==(rhs); }

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

}

#endif