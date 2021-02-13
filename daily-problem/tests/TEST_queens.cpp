#include <queens.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;
namespace utf = boost::unit_test;

struct screens {
    screens()    { initscr(); }
    ~screens()   { endwin();  }
};


BOOST_FIXTURE_TEST_SUITE( TEST_queens, screens )

/* Disable this for now */
//BOOST_AUTO_TEST_CASE( Case_1, * utf::disabled())
BOOST_AUTO_TEST_CASE( Case_1 )
{
	ml::queens puzzle;
	puzzle.solve();
	
}

BOOST_AUTO_TEST_SUITE_END()


