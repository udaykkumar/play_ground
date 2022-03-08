class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int answer = 0;
        for ( auto w : words )
        {
            int map[255] = {0,};
            for ( auto c : chars )
                map[ c ] ++;
            
            int yes = true;
            for ( auto c : w )
            {
                if( map[c] == 0 )
                {
                    yes = false;
                    break;
                }
                map[c] --;
            }
            
            if ( yes )
            {
                answer += w.size();
            }
        }
        return answer;
    }
};