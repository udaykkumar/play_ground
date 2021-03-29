#include <graph.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( TEST_Graph )

BOOST_AUTO_TEST_CASE( Case_1 )
{
    bira::graph<int> g;

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(4,6);

    g.show();

    std::cout << "Get Path from 1 - > 6 [ expected to get 1 -> 3 -> 6 or 1 -> 4 -> 6 or 1 -> 2 -> 6 ] \n";
    std::cout << g.path(1,6) << "\n";

}


BOOST_AUTO_TEST_CASE( Case_2 )
{
    bira::graph<int> g;

    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,5);
    g.addEdge(2,6);
    g.addEdge(3,5);
    g.addEdge(3,6);
    g.addEdge(4,6);
    g.addEdge(10,11);
    g.addEdge(6,21);
    g.addEdge(6,3);
    g.addEdge(16,49);
    g.addEdge(11,16);
    g.addEdge(4,10);

    g.show();

    
    std::cout << "Get Path from 1 - > 49 [ expected to get 1 -> 4 -> 10 -> 11 -> 16 -> 49  ] \n";
    std::cout << g.path(1,49)<< "\n";

}
BOOST_AUTO_TEST_SUITE_END()

