#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE iterator_trait
#include <boost/test/unit_test.hpp>
#include "astl\container\vector.hpp"



using namespace anotherSTL;


BOOST_AUTO_TEST_CASE(vector_empty_ctor) 
{	
	anotherSTL::vector<int> v;
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);	
}

BOOST_AUTO_TEST_CASE(vector_n_val_ctor)
{
	size_t size = 2;
	anotherSTL::vector<int> v(size, 100);
	BOOST_CHECK(v.size() == size);
	BOOST_CHECK(v.capacity() == size);
}