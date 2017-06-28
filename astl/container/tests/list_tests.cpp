#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_container_list

#include <boost/test/unit_test.hpp>
#include "astl\container\list.hpp"
#include <list>
#include <iterator> 
#include <cmath>
#include <string>


using namespace anotherSTL;



BOOST_AUTO_TEST_CASE(list_ctor)
{    
	anotherSTL::list<int> first;
	BOOST_CHECK(first.empty() == true);
	
	//anotherSTL::list<int> second(4, 100);
	//for (auto i = second.begin(); i != second.end(); ++i)
	//{
	//	BOOST_CHECK(*i == 100);
	//}
	//
	//std::list<int> third(second.begin(), second.end());
	//for (auto i = third.begin(); i != third.end(); ++i)
	//{
	//	BOOST_CHECK(*i == 100);
	//}

	//std::list<int> fourth(third);
	//for (auto i = fourth.begin(); i != fourth.end(); ++i)
	//{
	//	BOOST_CHECK(*i == 100);
	//}

	//int inputs[] = {16, 2, 77, 29};
	//std::list<int> fifth(inputs, inputs + sizeof(inputs) / sizeof(int));
	//auto i = fifth.begin();
	//BOOST_CHECK(*i == 16);
	//++i;
	//BOOST_CHECK(*i == 2);
	//++i;
	//BOOST_CHECK(*i == 77);
	//++i;
	//BOOST_CHECK(*i == 29);
	//++i;
	//BOOST_CHECK(i == fifth.end());
}

BOOST_AUTO_TEST_CASE(list_cpy_assign)
{
	std::list<int> first(3);  // list of 3 zero-initialized ints
	std::list<int> second(5); // list of 5 zero-initialized ints

	second = first;
	first = std::list<int>();
	BOOST_CHECK(first.size() == 0);
	BOOST_CHECK(second.size() == 3);
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

BOOST_AUTO_TEST_CASE(list_empty)
{
	int input[] = { 1,2,3,4,5,6,7,8,9,10};
	int sum(0);
	std::list<int> mylist(input, input+10);
	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	BOOST_CHECK(sum == 55);
}

BOOST_AUTO_TEST_CASE(list_size)
{
	std::list<int> myints;
	BOOST_CHECK(myints.size() == 0);

	for (int i = 0; i < 10; ++i)
	{
		myints.push_back(i);
	}
	BOOST_CHECK(myints.size() == 10);

	myints.insert(myints.begin(), 10, 100);
	BOOST_CHECK(myints.size() == 20);

	myints.pop_back();
	BOOST_CHECK(myints.size() == 19);

	myints.push_front(100);
	BOOST_CHECK(myints.size() == 20);
}

BOOST_AUTO_TEST_CASE(list_max_cap)
{
	std::list<int> mylist;
	//todo: BOOST_CHECK(mylist.max_size())
}

BOOST_AUTO_TEST_CASE(list_assign)
{
	std::list<int> first;
	std::list<int> second;
	first.assign(7, 100);
	std::list<int> res = { 100,100,100,100,100,100,100 };
	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), res.begin(), res.end());

	second.assign(first.begin(), first.end());
	BOOST_CHECK_EQUAL_COLLECTIONS(second.begin(), second.end(), res.begin(), res.end());

	int myints[] = { 1,2,3 };
	first.assign(myints, myints + 3);
	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), myints, myints+3);
}

BOOST_AUTO_TEST_CASE(list_push_front)
{
	std::list<int> mylist(2, 100);
	mylist.push_front(200);
	mylist.push_front(300);
	std::list<int> res = { 300,200,100,100 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

BOOST_AUTO_TEST_CASE(list_pop_front)
{
	std::list<int> mylist;
	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);
	mylist.pop_front();
	std::list<int> res1 = { 200, 300 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res1.begin(), res1.end());

	mylist.pop_front();
	std::list<int> res2 = { 300 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res2.begin(), res2.end());	

	mylist.pop_front();
	BOOST_CHECK(mylist.empty());
}

BOOST_AUTO_TEST_CASE(list_insert)
{
	std::list<int> mylist;
	std::list<int>::iterator it;

	for (int i = 1; i <= 5; ++i)
	{
		mylist.push_back(i);
	}

	it = mylist.begin();
	BOOST_CHECK(*it == 1);

	++it;
	BOOST_CHECK(*it == 2);

	mylist.insert(it, 10); // insert in front of the iterator
	BOOST_CHECK(*it == 2);

	--it;
	BOOST_CHECK(*it == 10);
	++it;

	mylist.insert(it, 2, 20);
	--it;
	BOOST_CHECK(*it == 20);

	std::vector<int> myvector(2, 30);
	mylist.insert(it, myvector.begin(), myvector.end());
	std::vector<int> res = { 1,10,20,30,30,20,2,3,4,5 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end()); 
}

BOOST_AUTO_TEST_CASE(list_erase)
{
	std::list<int> mylist;
	std::list<int>::iterator it1, it2;
	for (int i = 1; i<10; ++i) mylist.push_back(i * 10);

	it1 = it2 = mylist.begin();
	std::advance(it2, 6);
	BOOST_CHECK(*it2 == 70);

	++it1;
	BOOST_CHECK(*it1 == 20);

	it1 = mylist.erase(it1);
	BOOST_CHECK(*it1 == 30);

	it2 = mylist.erase(it2);
	BOOST_CHECK(*it2 == 80);

	++it1;
	BOOST_CHECK(*it1 == 40);

	--it2;
	BOOST_CHECK(*it2 == 60);

	mylist.erase(it1, it2);

	std::vector<int> res = { 10,30,60,80, 90 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

BOOST_AUTO_TEST_CASE(list_swap)
{
	std::list<int> first(3, 100);   // three ints with a value of 100
	std::list<int> second(5, 200);  // five ints with a value of 200

	first.swap(second);

	std::vector<int> res1 = { 200,200,200,200,200 };
	std::vector<int> res2 = { 100,100,100};

	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), res1.begin(), res1.end());
	BOOST_CHECK_EQUAL_COLLECTIONS(second.begin(), second.end(), res2.begin(), res2.end());

}

BOOST_AUTO_TEST_CASE(list_resize)
{
	std::list<int> mylist;
	for (int i = 1; i < 10; ++i) 
	{
		mylist.push_back(i); 
	}

	mylist.resize(5);
	std::vector<int> res1 = { 1,2,3,4,5 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res1.begin(), res1.end());

	mylist.resize(8,100);
	std::vector<int> res2 = { 1,2,3,4,5, 100, 100, 100 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res2.begin(), res2.end());

	mylist.resize(12);
	std::vector<int> res3 = { 1,2,3,4,5, 100, 100, 100, 0,0,0,0 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res3.begin(), res3.end());
}

BOOST_AUTO_TEST_CASE(list_clear)
{
	std::list<int> mylist;
	std::list<int>::iterator it;

	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	mylist.clear();
	BOOST_CHECK(mylist.empty() == true);

	mylist.push_back(1101);
	mylist.push_back(2202);
	std::vector<int> res = { 1101, 2202 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

BOOST_AUTO_TEST_CASE(list_splice)
{
	std::list<int> mylist1, mylist2;
	std::list<int>::iterator it;

	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);      // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);   // mylist2: 10 20 30

	it = mylist1.begin();
	++it;                         // points to 2
	BOOST_CHECK(*it == 2);

	mylist1.splice(it, mylist2);	 // mylist1: 1 10 20 30 2 3 4
									// mylist2 (empty)
									 // "it" still points to 2 (the 5th element
	BOOST_CHECK(*it == 2);
	std::vector<int> res = { 1,10,20,30,2,3,4 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist1.begin(), mylist1.end(), res.begin(), res.end());
	BOOST_CHECK(mylist2.empty() == true);

	mylist2.splice(mylist2.begin(), mylist1, it);                                // mylist1: 1 10 20 30 3 4
																				 // mylist2: 2
																				 // "it" is now invalid.
	std::vector<int> res1 = { 1,10,20,30,3,4 };
	std::vector<int> res2 = { 2};
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist1.begin(), mylist1.end(), res1.begin(), res1.end());
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist2.begin(), mylist2.end(), res2.begin(), res2.end());

	it = mylist1.begin();
	std::advance(it, 3);           // "it" points now to 30
	BOOST_CHECK(*it == 30);

	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end()); // mylist1: 30 3 4 1 10 20
	std::vector<int> res3 = { 30,3,4,1,10,20 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist1.begin(), mylist1.end(), res3.begin(), res3.end());
}

BOOST_AUTO_TEST_CASE(list_remove)
{
	int myints[] = { 17,89,7,14 };
	std::list<int> mylist(myints, myints + 4);
	mylist.remove(89);

	std::vector<int> res = { 17,7,14 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

BOOST_AUTO_TEST_CASE(list_remove_if)
{
	int myints[] = { 15,36,7,17,20,39,4,1 };
	std::list<int> mylist(myints, myints + 8);   // 15 36 7 17 20 39 4 1

	mylist.remove_if([](const int&v) {return (v < 10); });           // 15 36 17 20 39
	mylist.remove_if([](const int& v) {return (v % 2) == 1;  });     // 36 20

	std::vector<int> res = { 36, 20 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}

BOOST_AUTO_TEST_CASE(list_unique)
{
	double mydoubles[] = { 12.15,  2.72, 73.0,  12.77,  3.14,
		12.77, 73.35, 72.25, 15.3,  72.25 };
	std::list<double> mylist(mydoubles, mydoubles + 10);

	mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
							   // 15.3,  72.25, 72.25, 73.0,  73.35

	mylist.unique();           //  2.72,  3.14, 12.15, 12.77
							   // 15.3,  72.25, 73.0,  73.35

	auto same_integral_part = [](double first, double second) { return int(first) == int(second); };
	mylist.unique(same_integral_part);  //  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0
	std::vector<double> res = { 2.72, 3.14, 12.15, 15.3, 72.25, 73.0 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());

	auto is_near = [](double first, double second) {return std::fabs(first - second) < 5.0; };
	mylist.unique(is_near);           //  2.72, 12.15, 72.25
	std::vector<double> res2 = { 2.72, 12.15, 72.25 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res2.begin(), res2.end());
}

BOOST_AUTO_TEST_CASE(list_merge)
{
	std::list<double> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();

	first.sort();
	second.sort();

	first.merge(second);
	BOOST_CHECK(second.empty() == true);

	std::vector<double> res = { 1.4,2.2,2.9,3.1,3.7,7.1 }; 
	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), res.begin(), res.end());
	
	second.push_back(2.1);
	first.merge(second, [](double first, double second) {return int(first) < int(second); });
	std::vector<double> res1 = { 1.4, 2.2, 2.9, 2.1, 3.1, 3.7, 7.1 };
	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), res1.begin(), res1.end());
}

BOOST_AUTO_TEST_CASE(list_sort)
{
	std::list<std::string> mylist;
	std::list<std::string>::iterator it;
	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");

	mylist.sort();
	std::vector<std::string> res = { "Three", "one", "two" };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());

	// comparison, not case sensitive.
	auto compare_nocase = [](const std::string& first, const std::string& second)
	{
		unsigned int i = 0;
		while ((i<first.length()) && (i<second.length()))
		{
			if (tolower(first[i])<tolower(second[i])) return true;
			else if (tolower(first[i])>tolower(second[i])) return false;
			++i;
		}
		return (first.length() < second.length());
	};


	mylist.sort(compare_nocase);
	std::vector<std::string> res1 = {  "one", "Three", "two" };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res1.begin(), res1.end());
}

BOOST_AUTO_TEST_CASE(list_revserse)
{
	std::list<int> mylist;
	for (int i = 1; i<10; ++i) mylist.push_back(i);
	mylist.reverse();

	std::vector<int> res = { 9,8,7,6,5,4,3,2,1 };
	BOOST_CHECK_EQUAL_COLLECTIONS(mylist.begin(), mylist.end(), res.begin(), res.end());
}
