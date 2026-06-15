#pragma once
#include <unordered_map>
#include <vector>
#include <set>

#include "graph.hpp"
namespace ds
{

	namespace detail {
		class graph_impl
		{
			private:
				std::unordered_map< int, std::vector<int>>  adjlist_;

				bool explore( const int sv, std::set<int> &visited );

			public:
				graph_impl();
				~graph_impl();

				void add_edge(int sv, int dv);
				bool dfs( const int sv, const int dv, std::vector<int> &, std::set<int> &visited );
				bool bfs( const int sv, const int dv, std::vector<int> &, std::set<int> &visited );
				size_t connected_components();

				std::string to_string() const;
					
		};
	}
	
}