#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE allocator_test
#include <boost/test/unit_test.hpp>
#include "astl\allocator\initialize.hpp"
#include "astl\allocator\simpleAllocator.hpp"
#include <memory>
#include <vector>
#include <deque>
#include <list>
#include <stack>


using namespace anotherSTL;


BOOST_AUTO_TEST_CASE(uninitialized_copy_int)
{
	// should call "template<typename T> 	T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _true_type)"
	const int size = 3;
	int input[size] = { 1,2,3 };
	int result[size];
	int* result_end = anotherSTL::uninitialized_copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 1);
	BOOST_CHECK(result[1] == 2);
	BOOST_CHECK(result[2] == 3);
	BOOST_CHECK((result_end - result) == size);
}


BOOST_AUTO_TEST_CASE(uninitialized_copy_const_char)
{
	// should call "inline char* copy(const char* first1, const char* last1, char* first2)"
	const int size = 3;
	const char input[size] = { 'a','b', 'c' };
	char result[size];
	char* result_end = anotherSTL::uninitialized_copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 'a');
	BOOST_CHECK(result[1] == 'b');
	BOOST_CHECK(result[2] == 'c');
	BOOST_CHECK((result_end - result) == size);
}

BOOST_AUTO_TEST_CASE(uninitialized_copy_char)
{
	// should called "	template<typename T> T* _copy_by_trivial_assign_ctr_4_ptr(T* first1, T* last1, T* first2, _true_type)"
	const int size = 3;
	char input[size] = { 'a','b', 'c' };
	char result[size];
	char* result_end = anotherSTL::uninitialized_copy(&input[0], input + size, &result[0]);
	BOOST_CHECK(result[0] == 'a');
	BOOST_CHECK(result[1] == 'b');
	BOOST_CHECK(result[2] == 'c');
	BOOST_CHECK((result_end - result) == size);
}

BOOST_AUTO_TEST_CASE(uninitialized_copy_struct)
{	
	// should call	template<typename InputIterator, typename ForwardIterator> 	inline ForwardIterator _uninitialized_copy_2(InputIterator first1, InputIterator last1, ForwardIterator first2, _false_type)
	struct Shape { int a; int b; };
	const int size = 2;
	Shape sps[2] = { { 1,2 },{ 3,4 } };

	Shape result[size];
	Shape* result_end = anotherSTL::uninitialized_copy(&sps[0], sps + size, &result[0]);
	BOOST_CHECK(result[0].a == 1);
	BOOST_CHECK(result[0].b == 2);
	BOOST_CHECK(result[1].a == 3);
	BOOST_CHECK(result[1].b == 4);
	BOOST_CHECK((result_end - result) == size);
}

BOOST_AUTO_TEST_CASE(uninitialized_fill_int)
{
	const int size = 3;
	int value = 1;
	int output[size];
	fill(&output[0], output + size, value);
	BOOST_CHECK(output[0] == value);
	BOOST_CHECK(output[1] == value);
	BOOST_CHECK(output[2] == value);
}

BOOST_AUTO_TEST_CASE(uninitialized_fill_struct)
{
	struct Shape { int a; int b; };
	const int size = 2;
	Shape output[2];
	Shape value = { 1,2 };	
	anotherSTL::uninitialize_fill(&output[0], output + size, value);
	BOOST_CHECK(output[0].a == 1);
	BOOST_CHECK(output[0].b == 2);
	BOOST_CHECK(output[1].a == 1);
	BOOST_CHECK(output[1].b == 2);
}

BOOST_AUTO_TEST_CASE(uninitialized_fill_n_int)
{
	const int size = 3;
	int value = 1;
	int output[size];
	int *outputEnd = uninitialize_fill_n(&output[0], size, value);
	int expected[size] = { value, value, value };
	BOOST_CHECK_EQUAL_COLLECTIONS(&output[0], outputEnd, &expected[0], expected + size);
}

BOOST_AUTO_TEST_CASE(uninitialized_fill_n_struct)
{
	struct Shape { int a; int b; };
	const int size = 2;
	Shape output[2];
	Shape value = { 1,2 };
	Shape* outputEnd = anotherSTL::uninitialize_fill_n(&output[0], size, value);
	BOOST_CHECK(output[0].a == 1);
	BOOST_CHECK(output[0].b == 2);
	BOOST_CHECK(output[1].a == 1);
	BOOST_CHECK(output[1].b == 2);
}

BOOST_AUTO_TEST_CASE(simpleAllocator_test_empty_vector)
{
	//std::vector<int, std::allocator<int>>  v;
	std::vector<int, anotherSTL::simpleAllocator<int>>  myEmptyVector;
	BOOST_CHECK(myEmptyVector.size() == 0);	
}

BOOST_AUTO_TEST_CASE(simpleAllocator_test_vector)
{
	//std::vector<int, std::allocator<int>>  v;
	std::vector<int, anotherSTL::simpleAllocator<int>>  myVector = {1,2,3};
	std::vector<int>  stdVector = { 1,2,3 };
	BOOST_CHECK_EQUAL_COLLECTIONS(myVector.begin(), myVector.end(), stdVector.begin(), stdVector.end());
}


BOOST_AUTO_TEST_CASE(simpleAllocator_test_deque)
{
	std::deque<int, anotherSTL::simpleAllocator<int>>  myDeq = { 1,2,3 };
	std::deque<int>  stdDeq = { 1,2,3 };
	BOOST_CHECK_EQUAL_COLLECTIONS(myDeq.begin(), myDeq.end(), stdDeq.begin(), stdDeq.end());
}

BOOST_AUTO_TEST_CASE(simpleAllocator_test_list)
{
	std::list<int, anotherSTL::simpleAllocator<int>>  myList = { 1,2,3 };
	std::list<int>  stdList = { 1,2,3 };
	BOOST_CHECK_EQUAL_COLLECTIONS(myList.begin(), myList.end(), stdList.begin(), stdList.end());
}

BOOST_AUTO_TEST_CASE(simpleAllocator_test_stack)
{
	const int size = 3;
	
	std::deque<int, anotherSTL::simpleAllocator<int>> myDeq;
	myDeq.push_back(100);
	myDeq.push_back(200);
	myDeq.push_back(300);
	std::stack<int, std::deque<int, anotherSTL::simpleAllocator<int>> > myStack(myDeq);
	// check size;
	BOOST_CHECK(myStack.size() == 3);

	std::deque<int> stdDeq(size, 100);   
	stdDeq.push_back(100);
	stdDeq.push_back(200);
	stdDeq.push_back(300);
	std::stack<int, std::deque<int>> stdStack(stdDeq);
	// check top
	myStack.pop();
	stdStack.pop();
	BOOST_CHECK(myStack.top() == stdStack.top());		
	BOOST_CHECK(myStack.size() == 2);
}



