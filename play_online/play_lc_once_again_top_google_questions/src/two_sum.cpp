#include <two_sum.hpp>
#include <unordered_map>
namespace lc
{
	std::vector<int> two_sum(std::vector<int> &nums, int target)
	{
	    std::unordered_map< int, int > map;
	    int i = 0;
	    for (auto n : nums)
	        map.insert(std::make_pair(n, i++));
	    
	    i = 0;
	    for ( auto n : nums )
	    {
	        int y = (target - n);
	        auto kv = map.find(y);
	        if (kv != map.end() and  kv->second != i)
	            return {i, kv->second};
	        ++i;
	    }
	
	    return {-1, -1};
	}
}

