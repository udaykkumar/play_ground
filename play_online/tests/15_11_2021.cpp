#include <15_11_2021.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_15_11_2021 )

BOOST_AUTO_TEST_CASE( transform_product_of_all_except_ith_Case_1 )
{
	{
		std::vector<int> input{    1,  2,  3,  4, 5};
		std::vector<int> expOut{ 120, 60, 40, 30, 24};
		
		std::vector<int> output = 
			daily_interview::transform_product_of_all_except_ith(input);
		
		BOOST_CHECK( output.size() == input.size() );
		BOOST_CHECK( output.size() == expOut.size() );


		for (size_t i = 0; i < output.size(); ++i)
			BOOST_CHECK( output.at(i) == expOut.at(i) );
		
	}

	{
		std::vector<int> input{  3, 2, 1};
		std::vector<int> expOut{ 2, 3, 6};
		
		std::vector<int> output = 
			daily_interview::transform_product_of_all_except_ith(input);
		
		BOOST_CHECK( output.size() == input.size() );
		BOOST_CHECK( output.size() == expOut.size() );


		for (size_t i = 0; i < output.size(); ++i)
			BOOST_CHECK( output.at(i) == expOut.at(i) );
		
	}


}

BOOST_AUTO_TEST_SUITE_END()

