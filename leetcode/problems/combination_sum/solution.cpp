
class Solution {

	void combinationSum( std::vector<int>& candidates, int target, int start,  std::vector< int > combination, std::vector< std::vector< int > > &res ) {

		if ( target == 0 ) {
			res.emplace_back(combination);
			return;
		}

		if ( target < 0 ) {
			return;
		} 

		for ( int i = start; i < int(candidates.size()); ++i ) {
			combination.emplace_back(candidates[i]);
			combinationSum( candidates, target - candidates[i], i, combination, res);
			combination.pop_back();
		}
	}

public:
    std::vector< std::vector<int>> combinationSum( std::vector<int>& candidates, int target) {
        
        std::vector< std::vector< int > > res;
        std::vector< int > combination;
        if ( candidates.size() == 0 ) return res;

       	combinationSum( candidates, target, 0, combination, res);

        return res;
    }
};