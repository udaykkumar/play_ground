class Solution {
  std::unordered_map< int, size_t > vtoi_;

    void make_vtoi( const std::vector<int> &nums ) {
        size_t index = 0;
        for ( auto n : nums  ) {
            vtoi_[n] = index;
            ++index;
        }
    }

    bool exists_in_map( const int v ) const {
        return vtoi_.find(v) != vtoi_.end();
    }

    size_t index_of( const int v ) {
        return vtoi_[v];
    }

public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        
        /// Create a map of value to index
        make_vtoi(nums);

        /// for each element in list
        for ( size_t i = 0 ; i < nums.size() ; ++i ) {

            /// we look for target - current element
            int look_for { target - nums.at(i) };

            /// if exists .. 
            if ( exists_in_map(look_for) ) {

                auto idx { index_of(look_for) };
                /// Make sure its not looking at it-self
                if ( idx != i ) {

                    /// all well means we are done
                    return { (int)idx , (int)i };
                }
            }
        }

        return { -1, -1 } ;
    }
};