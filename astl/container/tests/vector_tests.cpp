#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_container_vector
#include <boost/test/unit_test.hpp>
#include "astl\container\vector.hpp"



using namespace anotherSTL;


namespace anotherSTL
{
	namespace vector_test
	{
		// vectorElement
		struct vectorElement
		{
			int a;
		public:
			vectorElement(int a = 0) :a(a) {}
		};

		bool operator == (const vectorElement& left, const vectorElement& right)
		{
			return left.a == right.a;
		}

		bool operator != (const vectorElement& left, const vectorElement& right)
		{
			return !operator ==(left, right);
		}

		std::ostream& operator<<(std::ostream& os, const vectorElement& obj)
		{
			os << obj.a;
			return os;
		}

		// vectorElementWithRSC
		struct vectorElementWithRSC
		{
			int* a;
		public:
			vectorElementWithRSC(int a1 = 0)
			{
				//a = new int;
				//*a = a1;
				a = new int(a1);
			}

			vectorElementWithRSC(const vectorElementWithRSC& rhs)
			{
				//a = new int;
				//*a = a1;
				a = new int;
				*a = *rhs.a;
			}

			~vectorElementWithRSC()
			{
				delete a;
			}
		};

		bool operator == (const vectorElementWithRSC& left, const vectorElementWithRSC& right)
		{
			return *left.a == *right.a;
		}

		bool operator != (const vectorElementWithRSC& left, const vectorElementWithRSC& right)
		{
			return !operator ==(left, right);
		}

		std::ostream& operator<<(std::ostream& os, const vectorElementWithRSC& obj)
		{
			os << *obj.a;
			return os;
		}
	
	}



}


 

using namespace vector_test;


BOOST_AUTO_TEST_CASE(vector_struct_rsc_empty_ctor)
{
	anotherSTL::vector<vectorElementWithRSC> v;
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
}

BOOST_AUTO_TEST_CASE(vector_struct_rsc_n_val_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElementWithRSC> v(2, vectorElementWithRSC());
	BOOST_CHECK(v.size() == size);
	BOOST_CHECK(v.capacity() == size);
}



BOOST_AUTO_TEST_CASE(vector_struct_rsc_itetrator_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElementWithRSC> v(size, vectorElementWithRSC());
	anotherSTL::vector<vectorElementWithRSC> v1(v.begin(), v.end());

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());

	vectorElementWithRSC myElems[] = { vectorElementWithRSC(16), vectorElementWithRSC(2), vectorElementWithRSC(77), vectorElementWithRSC(29) };
	anotherSTL::vector<vectorElementWithRSC> v2(myElems, myElems + sizeof(myElems) / sizeof(int));
	BOOST_CHECK_EQUAL_COLLECTIONS(v2.begin(), v2.end(), myElems, myElems + 4);
}

BOOST_AUTO_TEST_CASE(vector_struct_rsc_cpy_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElementWithRSC> v(size, vectorElementWithRSC());
	anotherSTL::vector<vectorElementWithRSC> v1(v);

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_struct_rsc_cpy_asignment_ctor)
{
	size_t size = 2;
	vectorElementWithRSC elem1(100);
	
	anotherSTL::vector<vectorElementWithRSC> v(size, vectorElementWithRSC());
	anotherSTL::vector<vectorElementWithRSC> v1(4, elem1);
	v1 = v;
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_struct_rsc_reall)
{
	// TODO" without casting to sizt_t, initialziation would fail which it shouldnot
	anotherSTL::vector<vectorElementWithRSC> v((size_t)10, 100);
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(100);
	}

	anotherSTL::vector<vectorElementWithRSC> v1((size_t)110, 100);
	BOOST_CHECK_EQUAL_COLLECTIONS(v1.begin(), v1.end(), v.begin(), v.end());
}


BOOST_AUTO_TEST_CASE(vector_struct_empty_ctor)
{
	anotherSTL::vector<vectorElement> v;
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
}

BOOST_AUTO_TEST_CASE(vector_struct_n_val_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElement> v(2, vectorElement());
	BOOST_CHECK(v.size() == size);
	BOOST_CHECK(v.capacity() == size);
}

BOOST_AUTO_TEST_CASE(vector_struct_itetrator_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElement> v(size, vectorElement());
	anotherSTL::vector<vectorElement> v1(v.begin(), v.end());

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());

	vectorElement myElems[] = { vectorElement(16), vectorElement(2), vectorElement(77), vectorElement(29) };
	anotherSTL::vector<vectorElement> v2(myElems, myElems + sizeof(myElems) / sizeof(int));
	BOOST_CHECK_EQUAL_COLLECTIONS(v2.begin(), v2.end(), myElems, myElems + 4);
}

BOOST_AUTO_TEST_CASE(vector_struct_cpy_ctor)
{
	size_t size = 2;
	anotherSTL::vector<vectorElement> v(size, vectorElement());
	anotherSTL::vector<vectorElement> v1(v);

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_struct_cpy_asignment_ctor)
{
	size_t size = 2;
	vectorElement elem1(100);	
	anotherSTL::vector<vectorElement> v(size, vectorElement());
	anotherSTL::vector<vectorElement> v1(4, elem1);
	v1 = v;
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_struct_reall)
{
	anotherSTL::vector<vectorElement> v(10, vectorElement(100));
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(100);
	}

	anotherSTL::vector<vectorElement> v1(110, vectorElement(100));
	BOOST_CHECK_EQUAL_COLLECTIONS(v1.begin(), v1.end(), v.begin(), v.end());
}

//
//BOOST_AUTO_TEST_CASE(vector_POD_empty_ctor) 
//{	
//	anotherSTL::vector<int> v;
//	BOOST_CHECK(v.size() == 0);
//	BOOST_CHECK(v.capacity() == 0);	
//}

BOOST_AUTO_TEST_CASE(vector_POD_n_val_ctor)
{
	size_t size = 2;
	anotherSTL::vector<int> v(size, 100);
	BOOST_CHECK(v.size() == size);
	BOOST_CHECK(v.capacity() == size);
}

BOOST_AUTO_TEST_CASE(vector_POD_itetrator_ctor)
{
	size_t size = 2;
	anotherSTL::vector<int> v(size, 100);
	anotherSTL::vector<int> v1(v.begin(), v.end());

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());

	int myints[] = { 16,2,77,29 };
	anotherSTL::vector<int> v2(myints, myints + sizeof(myints) / sizeof(int));
	BOOST_CHECK_EQUAL_COLLECTIONS(v2.begin(), v2.end(), myints, myints + 4);
}

BOOST_AUTO_TEST_CASE(vector_POD_cpy_ctor)
{
	size_t size = 2;
	anotherSTL::vector<int> v(size, 100);
	anotherSTL::vector<int> v1(v);

	BOOST_CHECK(v1.size() == size);
	BOOST_CHECK(v1.capacity() == size);
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_POD_cpy_asignment_ctor)
{
	size_t size = 2;
	anotherSTL::vector<int> v(size, 100);
	anotherSTL::vector<int> v1(4, 200);
	v1 = v;
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_POD_reall)
{	
	anotherSTL::vector<int> v(10, 100);
	for (int i = 0; i < 100; ++i)
	{
		v.push_back(100);
	}

	anotherSTL::vector<int> v1(110, 100);
	BOOST_CHECK_EQUAL_COLLECTIONS(v1.begin(), v1.end(), v.begin(), v.end());
}

// TODO: cannot allocate big array like std::vector can do 
//BOOST_AUTO_TEST_CASE(vector_bigsize)
//{
//	int bigSize = std::numeric_limits<int>::max()/sizeof(int);	
//	anotherSTL::vector<int> v(bigSize, 100);
//}


BOOST_AUTO_TEST_CASE(vector_iterator_begin)
{
	anotherSTL::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	BOOST_CHECK(*v.begin() == 1);
}

BOOST_AUTO_TEST_CASE(vector_iterator_end)
{
	anotherSTL::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	anotherSTL::vector<int> v1;
	for (anotherSTL::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		v1.push_back(*it);
	}
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), v1.begin(), v1.end());
}


BOOST_AUTO_TEST_CASE(vector_capacity_size)
{
	anotherSTL::vector<int> v;
	BOOST_CHECK(v.size() == 0);
	v.push_back(1);
	BOOST_CHECK(v.size() == 1);
	v.pop_back();
	BOOST_CHECK(v.size() == 0);
	v.push_back(1);
	BOOST_CHECK(v.size() == 1);

	anotherSTL::vector<int> v1(20,0);
	BOOST_CHECK(v1.size() == 20);
	v1.pop_back();
	BOOST_CHECK(v1.size() == 19);
	while (!v1.empty())
	{
		v1.pop_back();
	}
	BOOST_CHECK(v1.size() == 0);

	anotherSTL::vector<int> v2(20, 0);
	BOOST_CHECK(v2.size() == 20);
	for (int i = 0; i < 80; ++i)
	{
		v2.push_back(0);
	}
	BOOST_CHECK(v2.size() == 100);
	while (!v2.empty())
	{
		v2.pop_back();
	}
	BOOST_CHECK(v2.size() == 0);
}

BOOST_AUTO_TEST_CASE(vector_capacity_resize1)
{
	anotherSTL::vector<int> v;	
	for (int i = 1; i<10; i++) v.push_back(i);

	v.resize(5);
	v.resize(8, 100);
	v.resize(12);

	std::vector<int> expected = { 1 ,2, 3 ,4 ,5 ,100 ,100 ,100, 0, 0, 0, 0 };
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(vector_capacity_resize2)
{
	anotherSTL::vector<int> v;
	for (int i = 1; i<40; i++) v.push_back(i);

	v.resize(20);
	v.resize(30, 100);
	v.resize(35);

	std::vector<int> expected = { 1 ,2, 3 ,4 ,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,100,100,100,100,100,100,100,100,100,100,0,0,0,0,0 };
	BOOST_CHECK_EQUAL_COLLECTIONS(v.begin(), v.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(vector_capacity_capacity)
{
	anotherSTL::vector<int> v;

	// set some content in the vector:
	for (int i = 0; i<20; i++) v.push_back(i);
	int c = v.capacity();
	BOOST_CHECK(c = 20);
	v.push_back(21);
	c = v.capacity();
	BOOST_CHECK(c = 40);
	for (int i = 22; i < 41; ++i)
	{
		v.push_back(i);
	}
	BOOST_CHECK(c = 80);
}


BOOST_AUTO_TEST_CASE(vector_capacity_reserve)
{
	anotherSTL::vector<int> v;	
	int c = v.capacity();
	BOOST_CHECK(c == 0);
	v.reserve(20);
	c = v.capacity();
	BOOST_CHECK(c == 20);
	v.reserve(100);
	c = v.capacity();
	BOOST_CHECK(c = 100);
	v.reserve(20);
	c = v.capacity();
	BOOST_CHECK(c = 100);
}

BOOST_AUTO_TEST_CASE(vector_capacity_empty)
{
	anotherSTL::vector<int> v;	
	BOOST_CHECK(v.empty());
	v.push_back(1);
	BOOST_CHECK(!v.empty());
	v.pop_back();
	BOOST_CHECK(v.empty());
}

BOOST_AUTO_TEST_CASE(vector_elementAccess_index)
{
	anotherSTL::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	const anotherSTL::vector<int> vConst(v);
	BOOST_CHECK(vConst[0] == 1);
	BOOST_CHECK(vConst[1] == 2);
	BOOST_CHECK(vConst[2] == 3);	

	BOOST_CHECK(v[0] == 1);
	BOOST_CHECK(v[1] == 2);
	BOOST_CHECK(v[2] == 3);

	// does not check boundary
	BOOST_CHECK_NO_THROW(vConst[3]);
	BOOST_CHECK_NO_THROW(v[3]);
	BOOST_CHECK_NO_THROW(vConst[-1]);
	BOOST_CHECK_NO_THROW(v[-1]);
}

BOOST_AUTO_TEST_CASE(vector_elementAccess_at)
{
	anotherSTL::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	const anotherSTL::vector<int> vConst(v);
	BOOST_CHECK(vConst.at(0) == 1);
	BOOST_CHECK(vConst.at(1) == 2);
	BOOST_CHECK(vConst.at(2) == 3);

	BOOST_CHECK(v.at(0) == 1);
	BOOST_CHECK(v.at(1) == 2);
	BOOST_CHECK(v.at(2) == 3);

	// does not check boundary
	BOOST_CHECK_THROW(vConst.at(3), std::out_of_range);
	BOOST_CHECK_THROW(v.at(3), std::out_of_range);
	BOOST_CHECK_THROW(vConst.at(-1), std::out_of_range);
	BOOST_CHECK_THROW(v.at(-1), std::out_of_range);
}

BOOST_AUTO_TEST_CASE(vector_elementAccess_frontback)
{
	anotherSTL::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	const anotherSTL::vector<int> vConst(v);
	BOOST_CHECK(vConst.at(0) == 1);
	BOOST_CHECK(vConst.at(1) == 2);
	BOOST_CHECK(vConst.at(2) == 3);

	BOOST_CHECK(v.front() == 1);
	BOOST_CHECK(v.back() == 3);
	BOOST_CHECK(vConst.front() == 1);
	BOOST_CHECK(vConst.back() == 3);

	v.push_back(4);
	BOOST_CHECK(v.back() == 4);
	v.pop_back();
	BOOST_CHECK(v.back() == 3);
}

BOOST_AUTO_TEST_CASE(vector_modify_assign)
{
	anotherSTL::vector<int> first;
	anotherSTL::vector<int> second;
	anotherSTL::vector<int> third;
	
	//TODO: has to cast to size_t otherwise would fail
	first.assign((size_t)7, 100);             // 7 ints with a value of 100
	anotherSTL::vector<int> expectedFirst(7,100);
	BOOST_CHECK_EQUAL_COLLECTIONS(first.begin(), first.end(), expectedFirst.begin(), expectedFirst.end());

	anotherSTL::vector<int>::iterator it;
	it = first.begin() + 1;

	second.assign(it, first.end() - 1); // the 5 central values of first
	anotherSTL::vector<int> expectedSecond(5, 100);
	BOOST_CHECK_EQUAL_COLLECTIONS(second.begin(), second.end(), expectedSecond.begin(), expectedSecond.end());

	int myints[] = { 1776,7,4 };
	third.assign(myints, myints + 3);   // assigning from array.
	std::vector<int> expectedThird({1776, 7,4});
	BOOST_CHECK_EQUAL_COLLECTIONS(third.begin(), third.end(), expectedThird.begin(), expectedThird.end());

}

BOOST_AUTO_TEST_CASE(vector_modify_insert)
{
	anotherSTL::vector<int> myvector(3, 100);
	anotherSTL::vector<int>::iterator it;

	it = myvector.begin();
	it = myvector.insert(it, 200);

	myvector.insert(it, size_t(2), 300);

	// "it" no longer valid, get a new one:
	it = myvector.begin();

	anotherSTL::vector<int> anothervector(2, 400);
	myvector.insert(it + 2, anothervector.begin(), anothervector.end());

	int myarray[] = { 501,502,503 };	
	myvector.insert(myvector.begin(), myarray, myarray + 3);

	std::vector<int> expected = { 501 ,502 ,503, 300 ,300, 400, 400, 200, 100, 100, 100 };
	BOOST_CHECK_EQUAL_COLLECTIONS(myvector.begin(), myvector.end(), expected.begin(), expected.end());
}

BOOST_AUTO_TEST_CASE(vector_modify_erase)
{
	anotherSTL::vector<int> myvector;

	// set some values (from 1 to 10)
	for (int i = 1; i <= 10; i++) myvector.push_back(i);

	// erase the 6th element
	anotherSTL::vector<int>::iterator it = myvector.erase(myvector.begin() + 5);
	BOOST_CHECK(*it == 7);

	// erase the first 3 elements:
	anotherSTL::vector<int>::iterator it1 = myvector.erase(myvector.begin(), myvector.begin() + 3);
	BOOST_CHECK(*it1 == 4);
	std::vector<int> expected = {4,5,7,8,9,10 };
	BOOST_CHECK_EQUAL_COLLECTIONS(myvector.begin(), myvector.end(), expected.begin(), expected.end());

}