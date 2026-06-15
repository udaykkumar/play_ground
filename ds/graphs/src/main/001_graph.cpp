#include <iostream>

#include "graph.hpp"

static void show_details( ds::graph &g )
{
	std::cout << g << std::endl;
	
	std::vector< std::vector<int> > paths = { {1,4}, {2,5}, {8,1} };
	for ( auto p : paths )
	{
		int i = p[0];
		int j = p[1];
		std::cout << "finding path from " << i << " -> " << j << "  : { ";
		auto path = g.dfs(i,j);
	    if ( path.empty() ) {
			std::cout << " No route " ;
	    }
	    else {
	     	for ( auto e : path )  { std::cout << e << " " ; }
	    }
		std::cout <<  "}" << std::endl;
	}

    std::cout << "connected_components " << g.connected_components() << std::endl;
}

#define ArraySize(x) ( sizeof x / sizeof x[0] )

int main(int argc, char const *argv[])
{

	{
        ds::graph g;
	    	g.add_edge(1,2);
	    	g.add_edge(1,3);
	    	g.add_edge(2,4);
	    	g.add_edge(3,4);

	    	g.add_edge(5,6);
	    	g.add_edge(5,7);

	    	g.add_edge(8,-1);
        show_details(g);

    
    }

    {
        int array[][2] = { {1,2}, {1,3}, {2,4}, {3,4}, {5,6}, {5,7}, {8,-1} };
        ds::graph g(array, ArraySize(array) );
        show_details(g);
    }

    
    return 0;
}