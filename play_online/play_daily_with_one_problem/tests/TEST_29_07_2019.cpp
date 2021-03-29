#include <29_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_29_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	daily_interview::graph g(4);

	g.edge(1,2);
	g.edge(1,3);
	g.edge(1,4);
	g.edge(2,3);
	g.edge(2,4);
	g.edge(3,4);

	//g.show();

	BOOST_CHECK( g.has_cycle() == true );

}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	daily_interview::graph g(4);

	g.edge(1,2);
	g.edge(1,3);
	g.edge(1,4);
	g.edge(2,3);
	g.edge(2,4);
	g.edge(3,4);

	//g.show();

	BOOST_CHECK( g.has_cycle() == true );

}

BOOST_AUTO_TEST_SUITE_END()

