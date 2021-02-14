#include "better-double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( betterdll_suite_remove )

BOOST_AUTO_TEST_CASE( betterdll_init )
{
    ds::betterdll list;
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( betterdll_initial_list_should_be_empty )
{
    ds::betterdll list;
    BOOST_CHECK( list.isEmpty() == true );
}

BOOST_AUTO_TEST_CASE( betterdll_removeHead_single_element )
{
    ds::betterdll list;
    BOOST_CHECK( list.addHead(1) == 0 );
    BOOST_CHECK( list.size() == 1 );

    BOOST_CHECK( list.removeHead() == 0 );
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( betterdll_removeHead_multiple_elements )
{
    ds::betterdll list;
    for( size_t i = 1; i <= 10 ; i ++ )
    {
        BOOST_CHECK( list.addHead(i) ==  0 );
        BOOST_CHECK( list.size() == i );
    }

    BOOST_CHECK( list.size() == 10 );

    for( size_t i = 10; i >= 1 ; i --  )
    {
        BOOST_CHECK( list.removeHead() ==  0 );
        BOOST_CHECK( list.size() == i-1 );
    }

    BOOST_CHECK( list.size() == 0 );
}

 BOOST_AUTO_TEST_CASE( betterdll_removeTail_single_element )
 {
     ds::betterdll list;
     BOOST_CHECK( list.addTail(1) == 0 );
     BOOST_CHECK( list.size() == 1 );

     BOOST_CHECK( list.removeTail() == 0 );
     BOOST_CHECK( list.size() == 0 );
 }


 BOOST_AUTO_TEST_CASE( betterdll_removeTail_multiple_elements )
 {
     ds::betterdll list;
     for( size_t i = 1 ; i <= 10 ; i ++ )
     {
        BOOST_CHECK( list.addTail(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        

    for( size_t i = 10 ; i >= 1 ; i -- )
     {
        BOOST_CHECK( list.removeTail() == 0 );
        BOOST_CHECK( list.size() == i-1 );
     }

     BOOST_CHECK( list.size() == 0 );
 }


 BOOST_AUTO_TEST_CASE( betterdll_removeTail_empty_list_returns_minus_1 )
 {
     ds::betterdll list;
     BOOST_CHECK( list.removeTail() == -1 );
 }
 


 BOOST_AUTO_TEST_CASE( betterdll_removeHead_empty_list_returns_minus_1 )
 {
     ds::betterdll list;
     BOOST_CHECK( list.removeHead() == -1 );
 }


 BOOST_AUTO_TEST_CASE( betterdll_removeHead_remove_until_empty )
 {
     ds::betterdll list;
     for( size_t i = 1 ; i <= 100 ; i ++ )   
     {
        BOOST_CHECK( list.addHead(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        
    for( ; list.isEmpty() == false ; )
        BOOST_CHECK( list.removeTail() == 0 );

    BOOST_CHECK( list.removeTail() == -1 );    
    BOOST_CHECK( list.removeHead() == -1 );    
    BOOST_CHECK( list.size() == 0 );    
        
 }


 BOOST_AUTO_TEST_CASE( betterdll_removeTail_remove_until_empty )
 {
     ds::betterdll list;
     for( size_t i = 1 ; i <= 100 ; i ++ )   
     {
        BOOST_CHECK( list.addHead(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        
    for( ; list.isEmpty() == false ; )
        BOOST_CHECK( list.removeTail() == 0 );

    BOOST_CHECK( list.removeTail() == -1 );    
    BOOST_CHECK( list.removeHead() == -1 );    
    BOOST_CHECK( list.size() == 0 );    
        
 }
 

BOOST_AUTO_TEST_SUITE_END()


