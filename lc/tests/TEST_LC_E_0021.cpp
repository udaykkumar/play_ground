#include <LC_E_0021.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_LC_E_0021 )

BOOST_AUTO_TEST_CASE( isSameTree_Case_1 )
{
    lc::TreeNode *t1 = new lc::TreeNode(1);
        t1->left     = new lc::TreeNode(2);
        t1->right    = new lc::TreeNode(3);

    lc::TreeNode *t2 = new lc::TreeNode(1);
        t2->left     = new lc::TreeNode(2);
        t2->right    = new lc::TreeNode(3);

    BOOST_CHECK( lc::isSameTree(t1,t2) == true );
}


BOOST_AUTO_TEST_CASE( isSameTree_Case_2 )
{
    lc::TreeNode *t1 = new lc::TreeNode(1);
        t1->left     = new lc::TreeNode(2);

    lc::TreeNode *t2 = new lc::TreeNode(1);
        t2->right    = new lc::TreeNode(3);

    BOOST_CHECK( lc::isSameTree(t1,t2) == false );
}


BOOST_AUTO_TEST_SUITE_END()

