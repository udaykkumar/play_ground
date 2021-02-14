#include <14_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_14_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    BOOST_CHECK( bracket_sequence("(((())))").is_valid() == true );
}


BOOST_AUTO_TEST_CASE( Case_2 )
{
    BOOST_CHECK( bracket_sequence("[()]{}").is_valid() == true );
}

BOOST_AUTO_TEST_CASE( Case_3 )
{
    BOOST_CHECK( bracket_sequence("({[)]").is_valid() == false );
}

BOOST_AUTO_TEST_CASE( Case_4 )
{
    BOOST_CHECK( bracket_sequence("((({[})))").is_valid() == false );
}

BOOST_AUTO_TEST_CASE( Case_5 )
{
    BOOST_CHECK( bracket_sequence("((({[})))").is_valid() == false );
}

BOOST_AUTO_TEST_CASE( Case_6 )
{
    BOOST_CHECK( bracket_sequence("").is_valid() == true );
}

BOOST_AUTO_TEST_SUITE_END()

