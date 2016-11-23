#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE algo_modify
#include <boost/test/unit_test.hpp>
#include "astl\algorithm\modify_algo.hpp"

using namespace anotherSTL;


BOOST_AUTO_TEST_CASE(copy_int)
{
	// should call "template<typename T> 	T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _true_type)"
	const int size = 3;
	int input[size] = { 1,2,3 };
	int result[size] ;
	int* result_end = anotherSTL::copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 1);
	BOOST_CHECK(result[1] == 2);
	BOOST_CHECK(result[2] == 3);
	BOOST_CHECK((result_end - result) == size);
}


BOOST_AUTO_TEST_CASE(copy_const_char)
{
	// should call "inline char* copy(const char* first1, const char* last1, char* first2)"
	const int size = 3;
	const char input[size] = { 'a','b', 'c' };
	char result[size];
	char* result_end = anotherSTL::copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 'a');
	BOOST_CHECK(result[1] == 'b');
	BOOST_CHECK(result[2] == 'c');
	BOOST_CHECK((result_end - result) == size);
}

BOOST_AUTO_TEST_CASE(copy_char)
{
	// should called "	template<typename T> T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _true_type)"
	const int size = 3;
	char input[size] = { 'a','b', 'c' };
	char result[size];
	char* result_end = anotherSTL::copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 'a');
	BOOST_CHECK(result[1] == 'b');
	BOOST_CHECK(result[2] == 'c');
	BOOST_CHECK((result_end - result) == size);
}