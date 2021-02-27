#include <accounts_merge.hpp>
#include <unordered_map>

namespace lc
{
    std::vector< std::vector<std::string> > accounts_merge(
    		std::vector< std::vector<std::string> > &accounts)
    {
    	std::unordered_map<std::string, std::vector<int>> emails;
    	for ( int idx = 0 ; idx < accounts.size() ; ++idx )
    	{
    		auto l = accounts[idx];
    		for ( int i = 1; i < l.size() ; ++i )
    		{
    			auto email = l[i];
    			auto kvp   = emails.find(email);
    			if ( kvp != emails.end() )
    			{
    				emails[ email ].push_back(i);
    			}
    			else
    			{
    				emails.insert( std::pair< std::string, std::vector<int> >( 
    					email, std::vector<int>({i})) );
    			}
    		}
    	}



        return accounts;
    }
}

