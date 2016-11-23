#ifndef _ANOTHERSTL_ITERATOR_TRAITS
#define _ANOTHERSTL_ITERATOR_TRAITS

#include "astl\base\fundamental.hpp"

namespace anotherSTL
{
	struct output_iterator_tag {}; //Write
	struct input_interator_tag {}; // Read
	struct forward_interator_tag : public input_interator_tag {}; //Read Write
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
	

	// NOTE: how this function is used
	template<typename Iterator>
	inline typename iterator_traits<Iterator>::difference_type*
		distance_type(const Iterator&)
	{
		typedef typename iterator_traits<Iterator>::difference_type diff_type;
		return static_cast<diff_type*>(0);
	}

	// Note: how this function is used, just as a type marker for different overloaded function
	template<typename Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		value_type(const Iterator&)
	{
		typedef typename iterator_traits<Iterator>::value_type v_type;
			return static_cast<v_type*>(0);
	}

	template<typename Iterator>
	inline typename iterator_traits<Iterator>::value_type*
		get_pointer(Iterator i)
	{
		return &(*i);
	}
}


#endif // !_ANOTHERSTL_ITERATOR_TRAITS

