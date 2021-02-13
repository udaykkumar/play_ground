#include <30_07_2019.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_30_07_2019 )

BOOST_AUTO_TEST_CASE( Case_1 )
{
	char matrix[][1024] = {  
						{'F', 'A', 'C', 'I'},  
						{'O', 'B', 'Q', 'P'},  
						{'A', 'N', 'O', 'B'},  
						{'M', 'A', 'S', 'S'}
					};
	char s[] = "FOAM";
  BOOST_CHECK( daily_interview::word_search( matrix, 4, 4, s, 4 ) == true );
}



BOOST_AUTO_TEST_CASE( Case_2 )
{
	char matrix[][1024] = {  
						{'F', 'A', 'C', 'I'},  
						{'O', 'B', 'Q', 'P'},  
						{'A', 'N', 'O', 'B'},  
						{'M', 'A', 'S', 'S'}
					};
	char s[] = "AM";
  BOOST_CHECK( daily_interview::word_search( matrix, 4, 4, s, 2 ) == true );
}


BOOST_AUTO_TEST_CASE( Case_3 )
{
	char matrix[][1024] = {  
						{'F', 'A', 'F', 'O', 'R', 'E', 'N', 'S', 'I', 'C'},  
						{'O', 'B', 'Q', 'P', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'A', 'N', 'O', 'B', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'}
					};
	char s[] = "FORENSIC";
  BOOST_CHECK( daily_interview::word_search( matrix, 10, 10, s, 8 ) == true );
}


BOOST_AUTO_TEST_CASE( Case_4 )
{
	char matrix[][1024] = {  
						{'O', 'B', 'Q', 'P', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'A', 'N', 'O', 'B', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'F', 'A', 'F', 'O', 'R', 'E', 'N', 'S', 'I', 'C'},  
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'}
					};
	char s[] = "FORENSIC";
  BOOST_CHECK( daily_interview::word_search( matrix, 10, 10, s, 8 ) == true );
}


BOOST_AUTO_TEST_CASE( Case_5 )
{
	char matrix[][1024] = {  
						{'O', 'B', 'Q', 'P', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'A', 'N', 'O', 'B', 'B', 'Q', 'P', 'B', 'Q', 'P'},  
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'F', 'A', 'F', 'O', 'R', 'E', 'N', 'S', 'I', 'C'},  
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'},
						{'M', 'A', 'S', 'S', 'B', 'Q', 'P', 'B', 'Q', 'P'}
					};
	char s[] = "FORENSIX";
  BOOST_CHECK( daily_interview::word_search( matrix, 10, 10, s, 8 ) == false );
}

BOOST_AUTO_TEST_SUITE_END()

