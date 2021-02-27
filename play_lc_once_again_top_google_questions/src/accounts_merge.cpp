#include <accounts_merge.hpp>
#include <unordered_map>

namespace lc
{
    std::vector< std::vector<std::string> > accounts_merge(
    		std::vector< std::vector<std::string> > &accounts)
    {
        typedef  std::unordered_map<std::string, std::string> stringmap;
    	typedef  std::unordered_map<std::string, std::unordered_map<std::string, std::string>> graph;

        graph g;
        for ( auto a : accounts )
        {
            auto name = a[0];
            for ( int i = 0 ; i < a.size(); ++i )
            {
                //g.insert( std::pair< std::string, stringmap>( name, std::pair() ));
            }
        }
        
        return accounts;
    }
}

