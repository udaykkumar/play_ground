#include <logger_rate_limiter.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_logger_rate_limiter )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	lc::logger_rate_limiter logger;
	BOOST_CHECK(logger.shouldPrintMessage(1, "foo") == true); // return true, next allowed timestamp for "foo" is 1 + 10 = 11
	BOOST_CHECK(logger.shouldPrintMessage(2, "bar") == true); // return true, next allowed timestamp for "bar" is 2 + 10 = 12
	BOOST_CHECK(logger.shouldPrintMessage(3, "foo") == false); // 3 < 11, return false
	BOOST_CHECK(logger.shouldPrintMessage(8, "bar") == false); // 8 < 12, return false
	BOOST_CHECK(logger.shouldPrintMessage(10, "foo") == false); // 10 < 11, return false
	BOOST_CHECK(logger.shouldPrintMessage(11, "foo") == true); // 11 >= 11, return true, next allowed timestamp for "foo" is
	// 11 + 10 = 21

}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	lc::logger_rate_limiter logger;
	BOOST_CHECK(logger.shouldPrintMessage(0, "A") == true);
	BOOST_CHECK(logger.shouldPrintMessage(0, "B") == true);
	BOOST_CHECK(logger.shouldPrintMessage(0, "C") == true);
	BOOST_CHECK(logger.shouldPrintMessage(0, "A") == false);
	BOOST_CHECK(logger.shouldPrintMessage(0, "B") == false);
	BOOST_CHECK(logger.shouldPrintMessage(0, "C") == false);
	BOOST_CHECK(logger.shouldPrintMessage(11, "A") == true);
	BOOST_CHECK(logger.shouldPrintMessage(11, "B") == true);
	BOOST_CHECK(logger.shouldPrintMessage(11, "C") == true);
	BOOST_CHECK(logger.shouldPrintMessage(11, "A") == false);

}
BOOST_AUTO_TEST_SUITE_END()

