#include <random_pick_with_weight.hpp>


namespace lc
{
    Solution::Solution(std::vector<int> &w)
    {
    	for (auto n : w)
            prefixSums.push_back(n + (prefixSums.empty() ? 
                0 : prefixSums.back()));
    }

    int Solution::pickIndex()
    {
    	// generate a random number in the range of [0, 1]
        float randNum = (float) rand() / RAND_MAX;
        float target =  randNum * prefixSums.back();
        // run a linear search to find the target zone
        for (int i = 0; i < prefixSums.size(); ++i)
            if (target < prefixSums[i])
                return i;
        return prefixSums.size() - 1;
    }

}
