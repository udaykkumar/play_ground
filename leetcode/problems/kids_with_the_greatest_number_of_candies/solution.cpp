class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res( candies.size(), false );
        int i = 0;
        int greatest = *std::max_element( candies.begin(), candies.end() );
        for( const auto &c : candies ) {
            res[i++] = ((c + extraCandies) >= greatest);
        }
        
        return res;
    }
};