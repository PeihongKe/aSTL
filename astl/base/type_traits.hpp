#ifndef _ANOTHERSTL_TYPE_TRAITS_
#define _ANOTHERSTL_TYPE_TRAITS_

 
namespace anotherSTL
{
	struct _true_type{};
	struct _false_type{};

	template<typename T>
	struct type_traits 
	{	
		typedef _false_type is_POD_type;
		typedef _false_type has_trivial_default_ctr;
		typedef _false_type has_trivial_copy_ctr;
		typedef _false_type has_trivial_assignment_ctr;
		typedef _false_type has_trivial_dtor;
	};

	// partial specilization
	template<typename T>
	struct type_traits<T*>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<char>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};
}




#endif