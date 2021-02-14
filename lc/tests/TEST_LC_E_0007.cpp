#include <LC_E_0007.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0007 )

BOOST_AUTO_TEST_CASE( mergeTwoLists_Case_1 )
{
    lc::ListNode *l1 = new lc::ListNode(1);
    lc::ListNode *l2 = new lc::ListNode(1);
    int outarray[ ]  = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9};
    lc::ListNode *c  = nullptr;
    int i = 0;

    i = 2;
    for( c = l1; i < 10 ; i ++, c = c->next )
        c->next =  new lc::ListNode(i) ;

    i = 2;
    for( c = l2; i < 10 ; i ++, c = c->next )
        c->next =  new lc::ListNode(i) ;


    BOOST_TEST_MESSAGE("List1 \n");
    for( c = l1; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    BOOST_TEST_MESSAGE("List2 \n");
    for( c = l2; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    lc::ListNode *l = lc::mergeTwoLists(l1, l2);

    BOOST_TEST_MESSAGE("List \n");
    for( c = l; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    i = 0;
    for( c = l; c ;  c = c->next )
        BOOST_CHECK( c->val == outarray[i++] );

    BOOST_TEST_MESSAGE("\n");

}

BOOST_AUTO_TEST_CASE( mergeTwoLists_Case_2 )
{
    lc::ListNode *l1 = new lc::ListNode(1);
    lc::ListNode *l2 = nullptr;
    int outarray[ ]  = {1,2,3,4,5,6,7,8,9};
    lc::ListNode *c  = nullptr;
    int i = 0;

    i = 2;
    for( c = l1; i < 10 ; i ++, c = c->next )
        c->next =  new lc::ListNode(i) ;


    BOOST_TEST_MESSAGE("List1 \n");
    for( c = l1; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    BOOST_TEST_MESSAGE("List2 \n");
    for( c = l2; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    lc::ListNode *l = lc::mergeTwoLists(l1, l2);

    BOOST_TEST_MESSAGE("List \n");
    for( c = l; c ;  c = c->next )
        BOOST_TEST_MESSAGE( " " << c->val );

    i = 0;
    for( c = l; c ;  c = c->next )
        BOOST_CHECK( c->val == outarray[i++] );

    BOOST_TEST_MESSAGE("\n");
}
BOOST_AUTO_TEST_SUITE_END()

