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

	//NOTE: char, unsigned char and signed char are three diferent types
	template<>
	struct type_traits<char>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<unsigned char>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<signed char>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<short>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<unsigned short>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<int>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<unsigned int>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<long>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<unsigned long>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<float>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};

	template<>
	struct type_traits<double>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};


	template<>
	struct type_traits<long double>
	{
		typedef _true_type is_POD_type;
		typedef _true_type has_trivial_default_ctr;
		typedef _true_type has_trivial_copy_ctr;
		typedef _true_type has_trivial_assignment_ctr;
		typedef _true_type has_trivial_dtor;
	};




}




#endif