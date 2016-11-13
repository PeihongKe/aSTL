
#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "astl\iterator\iterator.hpp"
//#include <boost\test\unit_test_log.hpp>
//#include <boost\test\unit_test_monitor.hpp>
//#include <boost\test\framework.hpp>


BOOST_AUTO_TEST_CASE(test_init)
{
	int current_time = 0; // real call is required here

	BOOST_TEST_MESSAGE("Testing initialization :");
	BOOST_TEST_MESSAGE("Current time:" << current_time);
}

