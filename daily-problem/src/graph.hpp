#ifndef __GRAPH_HPP_INCLUDED__
#define __GRAPH_HPP_INCLUDED__

#include <iostream>
#include <unordered_map>
#include <unordered_set>

namespace bira
{
    template< typename vertexType >
    struct graph
    {

        typedef std::unordered_set< vertexType >            vset_t;
        typedef std::unordered_map< vertexType, vset_t >    vmap_t;
        typedef std::unordered_map< vertexType, bool   >    visit_journal_t;


    private:
        vmap_t adjList;

        bool path( vertexType u, vertexType v, visit_journal_t& visited, std::string& p )
        {
            /* U doesn't even exists */
            if( adjList.find(u) == adjList.end() || visited[u] == true )
            {
                return false;
            }

            visited[u] = true;

            auto entry = adjList.find(u);

            /* 
                There is path from u -> v here 
                but we have visited so mark that 
            */
            
            if( entry->second.find(v) != entry->second.end() )
            {
                p += " <- " + std::to_string(v);
                return true;
            }

            /* we do not have path 
                we'll try and see if there exists a path 
                from each of the connected vertices, if there is ??
                we are done
            */
            for( auto vertex : entry->second ) 
            {   
                if( path(vertex, v, visited, p) )
                {
                    p += " <- " + std::to_string(vertex);
                    return true;
                }
            }

            /* we did exhaust everything nothing */
            return false;
        }

    public:
        graph()
        {

        }

        ~graph()
        {

        }

        void addEdge( vertexType u, vertexType v )
        {
            auto it = adjList.find(u);
            if(  it == adjList.end()  )
            {
                adjList.insert(std::pair<vertexType, vset_t >(u, vset_t()));
                it = adjList.find(u);
            }
            it->second.insert(v);

        }

        void show()
        {
            for( auto it : adjList )
            {
                std::cout << it.first << " : " ;
                for( auto e : it.second )
                {
                    std::cout << e << " -> ";
                }
                std::cout << "\n";
            }
        }

        std::string path( vertexType u, vertexType v )
        {
            std::string     p("");
            
            visit_journal_t  visited;
            for( auto vertex : adjList ) {
                visited.insert( std::pair<vertexType, bool> ( vertex.first, false) );
            }
            
            if( path( u, v, visited, p) ){
                return p + " <- " + std::to_string(u);
            }

           return "None";
        }


    };

}
#endif