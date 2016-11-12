#ifndef _ANOTHERSTL_ITERATOR_UTIL
#define _ANOTHERSTL_ITERATOR_UTIL

#include "astl\base\fundamental.hpp"

namespace anotherSTL
{
	struct output_iterator_tag {};
	struct input_interator_tag {};	
	struct forward_interator_tag : public input_interator_tag {};
	struct bidirectional_iterator_tag: public forward_interator_tag	{};
	struct random_access_iterator_tag: public bidirectional_iterator_tag{};

	template<typename Iterator>
	class iterator_traits
	{
	public:
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template<typename T>
	class iterator_traits<T*>
	{
	public:
		typedef typename T								value_type;		
		typedef typename T*								pointer;
		typedef typename T&								reference;
		typedef typename ptrdiff_t						difference_type;
		typedef typename random_access_iterator_tag		iterator_category;
	};

	template<typename T>
	class iterator_traits<const T*>
	{
	public:
		typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef ptrdiff_t					difference_type;
		typedef random_access_iterator_tag	iterator_category;
	};

	template<typename InputIterator>
	inline typename iterator_traits<InputIterator>::iterator_category
		category(const InputIterator&)
	{
		typedef typename iterator_traits<InputIterator>::iterator_category category;
		return category();
	}
	
}


#endif // !_ANOTHERSTL_ITERATOR_UTIL

