#ifndef __29_07_2019_HPP_INCLUDED__
#define __29_07_2019_HPP_INCLUDED__

#include <list>
#include <memory>

namespace daily_interview 
{
	struct graph
	{
		size_t  vertices;
		std::list<int> *adjcency_list;

		bool has_cycle( const size_t vertex, bool *visited, size_t parent);

		graph(const size_t vertcs ) :
			vertices( (vertcs+1) )
		{
			adjcency_list = new std::list<int>[vertcs+1];
		}

		void yi();
		void edge(const size_t v, const size_t w);
		bool has_cycle();
		void show();
	};
}

#endif
