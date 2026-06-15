class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        for ( size_t idx = 0 ; idx < bits.size() ; idx ++)
        {
            // It doesn't matter which is next bit
            // we can skip next one
            if ( bits[idx] == 1 )
                idx ++;
            // if this is zero sure its a single digit
            // but if its last we have a solution
            else if ( idx == bits.size()-1 )
                    return true;
            
        }
        return false;
    }
};