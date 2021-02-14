#include <sudoku.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;
namespace utf = boost::unit_test;
struct screens {
    screens()    { initscr(); }
    ~screens()   { endwin();  }
};


BOOST_FIXTURE_TEST_SUITE( TEST_sudoku, screens )

/* Disable this for now */
BOOST_AUTO_TEST_CASE( Case_1)//, * utf::disabled())
{
	std::vector<size_t> inputVector  = { 
    				   3, 0, 6, 5, 0, 8, 4, 0, 0 ,  
                       5, 2, 0, 0, 0, 0, 0, 0, 0 ,  
                       0, 8, 7, 0, 0, 0, 0, 3, 1 ,  
                       0, 0, 3, 0, 1, 0, 0, 8, 0 ,  
                       9, 0, 0, 8, 6, 3, 0, 0, 5 ,  
                       0, 5, 0, 0, 9, 0, 6, 0, 0 ,  
                       1, 3, 0, 0, 0, 0, 2, 5, 0 ,  
                       0, 0, 0, 0, 0, 0, 0, 7, 4 ,  
                       0, 0, 5, 2, 0, 6, 3, 0, 0 
                   	};  

    
	ml::sudoku puzzle2(inputVector);
	puzzle2.solve();
	
}



BOOST_AUTO_TEST_CASE( Case_2)//, * utf::disabled())
{
	
    ml::sudoku puzzle1;
    puzzle1.solve();

}


BOOST_AUTO_TEST_CASE( Case_3)//, * utf::disabled())
{	
   std::vector<size_t> inputVector  = { 
    				   0,0,0,0,0,0,0,0,0,
					   0,0,8,0,0,0,0,4,0,
					   0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,6,0,0,0,
					   0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,
					   2,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,2,0,0,
					   0,0,0,0,0,0,0,0,0
                   	};  

    
	ml::sudoku puzzle2(inputVector);
	puzzle2.solve();

}


BOOST_AUTO_TEST_CASE( Case_4)//, * utf::disabled())
{	
   std::vector<size_t> inputVector  = { 
    				   0,0,0,0,0,0,0,0,0,
					   0,0,8,0,0,0,0,4,0,
					   0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,6,0,0,0,
					   0,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,0,0,0,
					   2,0,0,0,0,0,0,0,0,
					   0,0,0,0,0,0,2,0,0,
					   0,0,0,0,0,0,0,0,0
                   	};  

    
	ml::sudoku puzzle2(inputVector);
	puzzle2.solve();

}

BOOST_AUTO_TEST_SUITE_END()


