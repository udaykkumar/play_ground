#include <random_pick_with_weight.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_random_pick_with_weight )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<int> v{1, 3, 4, 5, 24, 67};
	lc::Solution s(v);
	for (int i = 0; i < 20; ++i)
	{
		std::cout << s.pickIndex() << "\n";
	}
}

BOOST_AUTO_TEST_CASE( Case_2 )
{
	std::vector<int> v{1, 3};
	lc::Solution s(v);
	for (int i = 0; i < 20; ++i)
	{
		std::cout << s.pickIndex() << "\n";
	}
	

}
BOOST_AUTO_TEST_SUITE_END()

