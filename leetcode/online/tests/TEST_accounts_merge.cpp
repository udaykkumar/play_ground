#include <accounts_merge.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_accounts_merge )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	std::vector<std::vector<std::string> > accounts =
	{
	{ "John", "johnsmith@mail.com", "john00@mail.com" },
	{ "John", "johnnybravo@mail.com" },
	{ "John", "johnsmith@mail.com", "john_newyork@mail.com" },
	{ "Mary", "mary@mail.com" } };

	lc::accounts_merge(accounts);
}
BOOST_AUTO_TEST_SUITE_END()

