#pragma once
#include <memory>
#include <iostream>
#include <vector>

namespace ds
{
	namespace detail { class graph_impl; }
	
	class graph
	{
		private:
			std::shared_ptr< detail::graph_impl > pimpl_;

		public:
			graph();
			~graph();
			graph( const  int array[][2], const size_t size );
			
			void add_edge( const int sv, const int dv );
			std::vector< int> dfs( const int sv, const int dv);
			size_t connected_components();

			friend std::ostream& operator<<( std::ostream &os, const graph &g );
	};
}

