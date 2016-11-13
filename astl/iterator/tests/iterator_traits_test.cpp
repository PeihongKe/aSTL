

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest 
#include <boost/test/unit_test.hpp>




//int main()
//{
//	return 0;
//}
//


BOOST_AUTO_TEST_CASE(my_test)
{
	BOOST_CHECK_EQUAL(1+7, 8);
 
}

