#include <21_07_2019.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_21_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	daily_interview::bst bst;

	std::vector<int> ints =
	{ 1, 2, 3, 4, 5, 6, 7 };
	for (auto i : ints)
	{
		bst.add(i);
	}

	//bst.show();

	////std::cout << "\n CEIL " << bst.ceil(4) << " FLOOR " << bst.floor(4);
	//BOOST_CHECK( bst.ceil(4) == 5 );
	//BOOST_CHECK( bst.floor(4) == 4 );
}

BOOST_AUTO_TEST_SUITE_END()

