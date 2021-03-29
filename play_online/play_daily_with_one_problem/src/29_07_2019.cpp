/*
 Hi, here's your problem today. This problem was recently asked by Facebook:

 Given an undirected graph, determine if a cycle exists in the graph.

 Here is a function signature:


 def find_cycle(graph):
 # Fill this in.

 graph = {
 'a': {'a2':{}, 'a3':{} },
 'b': {'b2':{}},
 'c': {}
 }
 print find_cycle(graph)
 # False
 graph['c'] = graph
 print find_cycle(graph)
 # True


 Can you solve this in linear time, linear space?

 */
#include <29_07_2019.hpp>
#include <iostream>
namespace daily_interview
{
void graph::edge(const size_t v, const size_t w)
{
	adjcency_list[v].push_back(w);
	adjcency_list[w].push_back(v);
}

bool graph::has_cycle(const size_t vertex, bool *visited, size_t parent)
{
	visited[vertex] = true;

	for (std::list<int>::iterator it = adjcency_list[vertex].begin();
			it != adjcency_list[vertex].end(); ++it)
	{
		if (visited[*it] == false)
		{
			if (has_cycle(*it, visited, vertex))
				return true;
		}
		else if (*it != (int) parent)
			return true;
	}

	return false;
}

bool graph::has_cycle()
{
	bool *visited = new bool[vertices];
	for (size_t index = 0; index < vertices; index++)
	{
		visited[index] = false;
	}

	for (size_t u = 0; u < vertices; u++)
	{
		if (visited[u] == false)
		{
			if (has_cycle(u, visited, -1))
			{
				return true;
			}
		}
	}

	return false;
}

void graph::show()
{
	for (size_t u = 0; u < vertices; u++)
	{
		std::cout << "Vertex " << u << "->";
		for (auto i : adjcency_list[u])
		{
			std::cout << i << "->";
		}
		std::cout << "\n";
	}
}
}

