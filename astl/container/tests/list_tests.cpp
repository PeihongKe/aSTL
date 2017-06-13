#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_container_list

#include <boost/test/unit_test.hpp>
#include "astl\container\list.hpp"
#include <list>


using namespace anotherSTL;



BOOST_AUTO_TEST_CASE(list_ctor)
{    
	std::list<int> first;
	BOOST_CHECK(first.empty() == true);
	
	std::list<int> second(4, 100);
	for (auto i = second.begin(); i != second.end(); ++i)
	{
		BOOST_CHECK(*i == 100);
	}
	
	std::list<int> third(second.begin(), second.end());
	for (auto i = third.begin(); i != third.end(); ++i)
	{
		BOOST_CHECK(*i == 100);
	}

	std::list<int> fourth(third);
	for (auto i = fourth.begin(); i != fourth.end(); ++i)
	{
		BOOST_CHECK(*i == 100);
	}

	int inputs[] = {16, 2, 77, 29};
	std::list<int> fifth(inputs, inputs + sizeof(inputs) / sizeof(int));
	auto i = fifth.begin();
	BOOST_CHECK(*i == 16);
	++i;
	BOOST_CHECK(*i == 2);
	++i;
	BOOST_CHECK(*i == 77);
	++i;
	BOOST_CHECK(*i == 29);
	++i;
	BOOST_CHECK(i == fifth.end());
}

BOOST_AUTO_TEST_CASE(list_cpy_assign)
{
	std::list<int> first(3);  // list of 3 zero-initialized ints
	std::list<int> second(3); // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();
	BOOST_CHECK(first.size() == 0);
	BOOST_CHECK(second.size() == 0);
}


BOOST_AUTO_TEST_CASE(list_begin_and_end)
{
	int input[] = { 75,23,65,42,13 };
	std::list<int> mylist(input, input + 5);
	std::list<int> res;
	for (std::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		res.push_back(*it);
	} 
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

