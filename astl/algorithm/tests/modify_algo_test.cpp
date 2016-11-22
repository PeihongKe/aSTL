#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE algo_modify
#include <boost/test/unit_test.hpp>
#include "astl\algorithm\modify_algo.hpp"

using namespace anotherSTL;


BOOST_AUTO_TEST_CASE(copy_POD)
{
	const int size = 3;
	int input[size] = { 1,2,3 };
	int result[size] ;
	int* result_end = anotherSTL::copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 1);
	BOOST_CHECK(result[1] == 2);
	BOOST_CHECK(result[2] == 3);
	BOOST_CHECK((result_end - result) == size);
}