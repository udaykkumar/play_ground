#include "graph_impl.hpp"
#include <iostream>
#include <sstream>
#include <list>


namespace ds
{
	namespace detail 
	{

		graph_impl::graph_impl()
		{

		}

		graph_impl::~graph_impl()
		{

		}

		void graph_impl::add_edge(const int sv, const int dv)
		{
				if ( adjlist_.find(sv) == adjlist_.end()) adjlist_.insert( std::pair< int, std::vector<int>> (sv, std::vector<int>()) );
				if ( adjlist_.find(dv) == adjlist_.end()) adjlist_.insert( std::pair< int, std::vector<int>> (dv, std::vector<int>()) );
				adjlist_[sv].emplace_back(dv);
				adjlist_[dv].emplace_back(sv);
		}


		bool graph_impl::dfs( const int sv, const int dv, std::vector< int > &path , std::set<int> &visited )
		{
			if ( visited.find(sv) != visited.end() ) return false;
			visited.emplace(sv);

			/// If we find that source is destination 
			/// lets put both
			if ( sv == dv ) {
				path.emplace_back(dv);
				//path.emplace_back(sv);
				return true;
			}


			/// Source edge must be part of this adj list
			/// we have no path otherwise
			auto neighbours = adjlist_.find(sv);
			if ( neighbours != adjlist_.end() )
			{
				/// if there are neighbours then its a list 
				/// vector precisely go through one by one
				for ( auto neighbour : neighbours->second ) 
				{
					/// a true return means we found a valid path
					if ( dfs( neighbour, dv, path, visited ) )
					{
						path.emplace_back(sv);
						return true;
					}
				}
			}

			return false;
		}



		///////////////////////////////////////////////////////////////////////////
		/// 	This is Buggy or still to implement completely					///
		///////////////////////////////////////////////////////////////////////////
		bool graph_impl::bfs( const int sv, const int dv, std::vector< int > &path, std::set<int> &visited )
		{
			std::list< int > queue;
			queue.push_back(sv);


			while ( not queue.empty() ) {
				auto v = queue.front();
				queue.pop_front();
				if ( v == dv )
				{
					path.emplace_back(v);
					path.emplace_back(dv);
					return true;
				}
				/// Source edge must be part of this adj list
				/// we have no path otherwise
				auto neighbours = adjlist_.find(v);
				if ( neighbours != adjlist_.end() )
				{
					/// if there are neighbours then its a list 
					/// vector precisely go through one by one
					for ( auto neighbour : neighbours->second ) 
					{
						queue.push_back(neighbour);
					}
				}
			}

			return false;
		}

		std::string graph_impl::to_string() const
		{
			if ( adjlist_.size() <= 0 )
				return std::string("empty");

			std::ostringstream out;
			for ( auto kvp :  adjlist_ )
			{
				out << "\tNode " << kvp.first << " : " << "{";
				for ( auto e : kvp.second ) {
					out <<  " " << e  ;
				}
				out << " }" << std::endl;
			}

			return out.str();
		}	


		size_t graph_impl::connected_components( )
		{
			size_t size = 0;
			std::set < int > visited;
			for ( auto kvp :  adjlist_ )
			{
				if ( explore(kvp.first, visited) )
					size += 1;
			}

			return size;
		}


		bool graph_impl::explore( const int sv, std::set<int> &visited )
		{
			if ( visited.find(sv) != visited.end() ) 
				return false;

			visited.emplace(sv);

			for( auto neighbours : adjlist_[sv] ) {
				explore( neighbours, visited);
			}

			return true;
		}
	}

	graph::graph()
	{
		this->pimpl_ = std::make_shared< detail::graph_impl >();
	}

	graph::graph( const int array[][2], const size_t size )
	{
		this->pimpl_ = std::make_shared< detail::graph_impl >();
		for( size_t row{0} ; row < size ; ++row ) {
			this->pimpl_->add_edge(array[row][0], array[row][1]);
		}
	}
	
	graph::~graph()
	{

	}


	void graph::add_edge(const int sv, const int dv)
	{
		this->pimpl_->add_edge(sv, dv);
	}

	std::vector< int >  graph::dfs( const int sv, const int dv)
	{
		std::vector< int > path;
		std::set< int > visited;
		pimpl_->dfs( sv, dv, path , visited );
		return path;
	}

	size_t graph::connected_components()
	{
		return pimpl_->connected_components();
	}

	std::ostream& operator<<( std::ostream &os, const graph &g )
	{
		os << "Graph :\n";
		os << g.pimpl_->to_string();
		return os;
	}

}