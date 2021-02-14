#include <Test_Utils.h>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

static bool hide_prints = true;

void show_vector( const std::string &label,
		const std::vector<int> &iv )
{
    if ( hide_prints )
        return;

    std::ostringstream vts;
    std::copy(iv.begin(), iv.end(), 
            std::ostream_iterator<int>(vts, ", "));
	BOOST_TEST_MESSAGE(label);
    BOOST_TEST_MESSAGE(vts.str());
}

void generate_iv_ov( std::vector<int> &iv, std::vector<int> &ov)
{
	// Generate Input
    std::iota( iv.begin(), iv.end(), 1);
    //show_vector( "iv", iv );

    std::iota( ov.begin(), ov.end(), 1);
 	//show_vector( "ov", ov );
}
