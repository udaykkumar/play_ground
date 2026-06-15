class Solution {

	std::unordered_map< int, bool > seen_;

	bool seen( int i ) { return seen_.find(i) != seen_.end() ; }
	void  see( int i ) {  seen_[i] = true ; }


	bool canJump( std::vector<int> &nums, int current) {
		//std::cout << "canJump " << current << " \n"; 
		if ( seen(current) ) 	return false;
		
		if ( current >= int(nums.size()) ) {
			see(current);
			return false;	
		} 
		if ( current == (int(nums.size()) -1) ) return true;
		
		for ( int i = nums[current]; i >= 1  ; --i ) {
			if ( canJump(nums, current + i) )
				return true;
		}

		see(current);
		return false;
	}

public:
    bool canJump(std::vector<int>& nums) {
    	/// There is nothing to jump
    	if ( nums.size() == 0 ) return false;

    	/// We are already at end
    	if ( nums.size() == 1 ) return true;

    	for ( int i = nums[0]; i >= 1 ; --i ) {
    		if ( canJump(nums, i) )
    			return true;
    	}

        return false;
    }
};
