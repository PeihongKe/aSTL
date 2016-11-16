#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE iterator_trait
#include <boost/test/unit_test.hpp>
#include "astl\iterator\iterator_traits.hpp"
#include "astl\iterator\iterator.hpp"
#include <typeinfo>
#include <iostream>
#include <string>

using namespace anotherSTL;


BOOST_AUTO_TEST_CASE(distance_func)
{
	int a[3] = { 1,2,3 };
	int *begin = a;
	int *end = a + 3;
	int dis = distance(begin, end);
	BOOST_CHECK(dis == 3);

}

BOOST_AUTO_TEST_CASE(advance_func)
{
	int a[3] = { 1,2,3 };
	int *begin = a;
	int *end = a + 2;
    advance(begin, 2);
	BOOST_CHECK(*begin == *end);

}


BOOST_AUTO_TEST_CASE(category_function)
{
	int a[3] = { 1,2,3 };
	int *begin = a;
	random_access_iterator_tag* rci(dynamic_cast<random_access_iterator_tag*>(&category(begin)));
	BOOST_CHECK(rci != nullptr);
}

BOOST_AUTO_TEST_CASE(iterator_distance_type_function)
{
	int a[3] = { 1,2,3 };
	BOOST_CHECK(std::string(typeid(distance_type(&a[0])).name()) ==  "int *\0");
}

BOOST_AUTO_TEST_CASE(iterator_value_type_function)
{
	int a[3] = { 1,2,3 };
	std::cout << std::string(typeid(value_type(&a[0])).name());
	BOOST_CHECK(std::string(typeid(value_type(&a[0])).name()) == "int *\0");
}


BOOST_AUTO_TEST_CASE(iterator_traits_specialization1)
{
	BOOST_CHECK(std::string(typeid(iterator_traits<int *>::value_type).name()) == "int\0");
	BOOST_CHECK(std::string(typeid(iterator_traits<int *>::pointer).name()) == "int *\0");
	BOOST_CHECK(std::string(typeid(iterator_traits<int *>::reference).name()) == "int\0");
	BOOST_CHECK(std::string(typeid(iterator_traits<int *>::difference_type).name()) == "int\0");	
	BOOST_CHECK(std::string(typeid(iterator_traits<int *>::iterator_category).name()) == "struct anotherSTL::random_access_iterator_tag\0");
}


BOOST_AUTO_TEST_CASE(iterator_traits_specialization2)
{	
	BOOST_CHECK(std::string(typeid(iterator_traits<const int *>::value_type).name()) == "int\0");
	BOOST_CHECK(std::string(typeid(iterator_traits<const int *>::pointer).name()) == "int const *\0");	
	//TODO: check
	BOOST_CHECK(std::string(typeid(iterator_traits<const int *>::reference).name()) == "int\0");

	BOOST_CHECK(std::string(typeid(iterator_traits<const int *>::difference_type).name()) == "int\0");
	BOOST_CHECK(std::string(typeid(iterator_traits<const int *>::iterator_category).name()) == "struct anotherSTL::random_access_iterator_tag\0");
}



