class Solution {
public:
   bool isPalindrome(std::string s) {
        
        int start = 0;
        int end   = s.size()-1;
        while( start < end ) {
        	auto sc{ s[start] };
        	auto ec{ s[end]   };

        	/// small and equal at both ends .. keeep going
        	if ( std::tolower(sc) == std::tolower(ec)) {
        		start ++;
        		end --;
        	} else if( not std::isalnum(sc) ) {
        		/// its probably not a  a character
        		start ++;
        	} else if ( not std::isalnum(ec)) {
        		/// its probably not a  a character
        		end --;
        	} else {
        		/// its a char but not equal throwup
        		return false;
        	}

        }
		return true;

    }
};