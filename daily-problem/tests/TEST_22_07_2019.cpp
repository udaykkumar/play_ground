#include <22_07_2019.hpp>
#include <boost/test/unit_test.hpp>
#include <iostream>
using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_22_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    daily_interview::binary_tree binay_tree;
	
	std::vector<int> ints = {5, 3, 2, 4, 7, 6};
	for( auto i: ints )
	{
		binay_tree.add(i);
	}


	//binay_tree.show();
	binay_tree.invert();
	//binay_tree.show();

	
}

BOOST_AUTO_TEST_SUITE_END()

