#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE algo_modify
#include <boost/test/unit_test.hpp>
#include "astl\algorithm\modify_algo.hpp"
#include <vector>

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

BOOST_AUTO_TEST_CASE(copy_backward_int)
{
	// call 	template<typename T> 	inline T* _copy_backward_by_trivial_assign_ctr_4_ptr(const T* first1, const T* last1, T* last2, _true_type)
	const int size = 8;
	int output[size] = { 10,20,30,40,50, 60,70,80 };
	anotherSTL::copy_backward(&output[0], output + 5, output +8);
	int expected[size] = { 10,20,30,10,20, 30,40,50 };
	BOOST_CHECK_EQUAL_COLLECTIONS(&output[0], output + size, &expected[0], expected + size);
}


BOOST_AUTO_TEST_CASE(copy_backward_char)
{
	// call 	template<typename T> 	inline T* _copy_backward_by_trivial_assign_ctr_4_ptr(const T* first1, const T* last1, T* last2, _true_type)
	const int size = 8;
	char output[size] = { 10,20,30,40,50, 60,70,80 };
	anotherSTL::copy_backward(&output[0], output + 5, output + 8);
	char expected[size] = { 10,20,30,10,20, 30,40,50 };
	BOOST_CHECK_EQUAL_COLLECTIONS(&output[0], output + size, &expected[0], expected + size);
}

BOOST_AUTO_TEST_CASE(copy_backward_const_char)
{
	// 	inline char* copy_backward(const char* first1, const char* last1, char* last2)
	const int size = 8;
	const char input[size] = { 10,20,30,40,50, 60,70,80 };
	char output[size] = { 1,2,3,4,5, 6,7,8 };
	anotherSTL::copy_backward(&input[0], input + size, output + size);
	
	BOOST_CHECK_EQUAL_COLLECTIONS(&input[0], input + size, &output[0], output + size);
}
 
BOOST_AUTO_TEST_CASE(copy_backward_struct)
{
	//	template<typename BiDirectionalIterator1, typename BiDirectionalIterator2> 	inline BiDirectionalIterator2 _copy_backward_by_category(BiDirectionalIterator1 first1, BiDirectionalIterator1 last1, BiDirectionalIterator2 last2, random_access_iterator_tag)
	struct Shape { int a; } s1,s2,s3;
	s1.a = 1;
	s2.a = 2;
	s3.a = 3;
	const int size = 3;
	Shape input[size] = {s1,s2,s3};
	Shape output[size];
	anotherSTL::copy_backward(&input[0], input + size, output + size);
	BOOST_CHECK_EQUAL_COLLECTIONS(reinterpret_cast<char*>(&input[0]), reinterpret_cast<char*>(&input[0]) + sizeof(Shape) * size, reinterpret_cast<char*>(&output[0]), reinterpret_cast<char*>(&output[0]) + sizeof(Shape) * size);
}