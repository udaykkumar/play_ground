#include "double-linked-list.hpp"
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( dll_suite_remove )

BOOST_AUTO_TEST_CASE( dll_init )
{
    ds::dll list;
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( dll_initial_list_should_be_empty )
{
    ds::dll list;
    BOOST_CHECK( list.isEmpty() == true );
}

BOOST_AUTO_TEST_CASE( dll_removeHead_single_element )
{
    ds::dll list;
    BOOST_CHECK( list.addHead(1) == 0 );
    BOOST_CHECK( list.size() == 1 );

    BOOST_CHECK( list.removeHead() == 1 );
    BOOST_CHECK( list.size() == 0 );
}

BOOST_AUTO_TEST_CASE( dll_removeHead_multiple_elements )
{
    ds::dll list;
    for( size_t i = 1; i <= 10 ; i ++ )
    {
        BOOST_CHECK( list.addHead(i) ==  0 );
    }

    BOOST_CHECK( list.size() == 10 );

    for( int i = 10; i >= 1 ; i --  )
    {
        BOOST_CHECK( list.removeHead() ==  i );
    }

    BOOST_CHECK( list.size() == 0 );
}

 BOOST_AUTO_TEST_CASE( dll_removeTail_single_element )
 {
     ds::dll list;
     BOOST_CHECK( list.addTail(1) == 0 );
     BOOST_CHECK( list.size() == 1 );

     BOOST_CHECK( list.removeTail() == 1 );
     BOOST_CHECK( list.size() == 0 );
 }


 BOOST_AUTO_TEST_CASE( dll_removeTail_multiple_elements )
 {
     ds::dll list;
     for( size_t i = 1 ; i <= 10 ; i ++ )
     {
        BOOST_CHECK( list.addTail(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        

    for( int i = 10 ; i >= 1 ; i -- )
     {
        BOOST_CHECK( list.removeTail() == i );
     }

     BOOST_CHECK( list.size() == 0 );
 }


 BOOST_AUTO_TEST_CASE( dll_removeTail_empty_list_returns_minus_1 )
 {
     ds::dll list;
     BOOST_TEST_MESSAGE( list.removeTail() );
     BOOST_CHECK( list.removeTail() == -1 );
 }
 


 BOOST_AUTO_TEST_CASE( dll_removeHead_empty_list_returns_minus_1 )
 {
     ds::dll list;
     BOOST_TEST_MESSAGE( list.removeHead() );
     BOOST_CHECK( list.removeHead() == -1 );
 }


 BOOST_AUTO_TEST_CASE( dll_removeHead_remove_until_empty )
 {
     ds::dll list;
     for( size_t i = 1 ; i <= 100 ; i ++ )   
     {
        BOOST_CHECK( list.addHead(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        
    for( int i = 1 ; i <= 100 ;  i ++ )
        BOOST_CHECK( list.removeTail() == i );

    BOOST_CHECK( list.removeTail() == -1 );    
    BOOST_CHECK( list.removeHead() == -1 );    
    BOOST_CHECK( list.size() == 0 );    
        
 }


 BOOST_AUTO_TEST_CASE( dll_removeTail_remove_until_empty )
 {
     ds::dll list;
     for( size_t i = 1 ; i <= 100 ; i ++ )   
     {
        BOOST_CHECK( list.addHead(i) == 0 );
        BOOST_CHECK( list.size() == i );
     }
        
    for( int i = 1 ; i <= 100 ;  i ++ )
        BOOST_CHECK( list.removeTail() == i );

    BOOST_CHECK( list.removeTail() == -1 );    
    BOOST_CHECK( list.removeHead() == -1 );    
    BOOST_CHECK( list.size() == 0 );    
        
 }
 

BOOST_AUTO_TEST_SUITE_END()


