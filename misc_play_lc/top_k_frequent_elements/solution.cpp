class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        
        typedef int freq_t  ;
        typedef int value_t ;

        /// This following code generates a value -> frequency map
        std::unordered_map< value_t, std::pair< freq_t , value_t >  > squeeze;
        for ( auto n : nums ) {
        	if ( squeeze.find(n) != squeeze.end() ) {
        		squeeze[n].first ++;
        	} else  {
        		squeeze[n] = std::make_pair(1,n);
        		
        	}
        }
        


        /// what we do now is declare a priority Queue to store freq, value object 
        auto cmp = [] ( const std::pair< freq_t, value_t> &p1, const std::pair< freq_t, value_t> &p2 ) {
	        	return p1.first < p2.first;
	        };

		std::priority_queue< std::pair< freq_t, value_t >, std::vector< std::pair<freq_t, value_t> >,  decltype(cmp) >  pq(cmp);
         
        for ( auto kvp : squeeze ) {
        	pq.push(kvp.second);
        }

        std::vector<int> res;
        int i = 0;
        while ( (pq.size() > 0) and (i < k)) {
        	auto top = pq.top();
        	pq.pop();
        	++i;
        	//std::cout << top.first << " " << top.second << "\n";
        	res.emplace_back(top.second);
        }

        return res;
    }
};