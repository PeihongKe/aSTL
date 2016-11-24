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

BOOST_AUTO_TEST_CASE(copy_struct)
{
	//	should call template<typename InputIterator, typename OutputIterator> 	OutputIterator _copy_by_category(InputIterator first1, InputIterator last1, OutputIterator first2, random_access_iterator_tag)
	struct Shape { int a; int b; };
	const int size = 2;
	Shape sps[2] = { {1,2}, {3,4} };		
	
	Shape result[size];
	Shape* result_end = anotherSTL::copy(&sps[0], sps + size, &result[0]);
	BOOST_CHECK(result[0].a == 1);
	BOOST_CHECK(result[0].b == 2);
	BOOST_CHECK(result[1].a == 3);
	BOOST_CHECK(result[1].b == 4);
	BOOST_CHECK((result_end - result) == size);
}

BOOST_AUTO_TEST_CASE(fill_int)
{
	const int size = 3;
	int output[size];	
	int value = 1;
	fill(&output[0], output + size, value);
	int expected[size] = { value, value, value };
	BOOST_CHECK_EQUAL_COLLECTIONS(&output[0], output + size, &expected[0], expected + size);
}


BOOST_AUTO_TEST_CASE(fill_n_int)
{
	const int size = 3;
	int output[size];
	int value = 1;
	int* outputEnd = fill_n(&output[0], size, value);
	int expected[size] = { value, value, value };
	BOOST_CHECK_EQUAL_COLLECTIONS(&output[0], outputEnd, &expected[0], expected + size);
}