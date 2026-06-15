class Solution {

	std::unordered_map < int , std::string > cache;

	std::string palindrome(std::string &s, int left, int right ) {

		int key =  left * 10000 + right;

		if ( cache.find(key) != cache.end() ) {
			return cache[key];
		}

		while ( (left >= 0) and (right < s.size()) and s[left] == s[right] )  {
			left --;
			right ++;
		}

		left =  ( left == -1 ) ? 0 : left + 1;
		right = ( right == s.size() ) ? s.size()-1 : right-1;

		std::string ps = s.substr(left, right-left + 1);
		//	while ( left <= right )
		//		ps += s[left++];

		cache[key] = ps;
		return ps;
	}

	std::string find_even_palindrome(std::string &s, int mid) {
		int left = mid-1;
		int right = mid;
		return palindrome(s, left, right);
	}

	std::string find_odd_palindrome(std::string &s, int mid) {
		int left = mid-1;
		int right = mid+1;

		return palindrome(s, left, right);
	}

public:
    std::string longestPalindrome(std::string s) {
    	
    	std::string p = "";

    	for ( int i = 0 ; i < s.size(); ++i ) {
    		std::string lp = find_even_palindrome(s, i);
    		if ( lp.size() > p.size() )
    			p = lp;

    		std::string rp = find_odd_palindrome(s,i);
    		if ( rp.size() > p.size() )
    			p = rp;
    	}
        return p;
    }
};