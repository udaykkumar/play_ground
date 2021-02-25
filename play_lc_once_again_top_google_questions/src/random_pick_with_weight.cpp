#include <random_pick_with_weight.hpp>


namespace lc
{
    Solution::Solution(std::vector<int> &w)
    {
    	std::random_device rd;
		gen = std::mt19937(rd()); //Standard mersenne_twister_engine seeded with rd()
    	distrib = std::uniform_int_distribution<int>(1, 6);
    }

    int Solution::pickIndex()
    {
    	return distrib(gen);
    }

}
