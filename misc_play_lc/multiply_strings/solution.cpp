class Solution {
public:
    string multiply(string num1, string num2) {
        if ( num1 == "0" or num2 == "0" )
            return "0";
        
        // Final result can not go beyond this size
        size_t n = num1.size() + num2.size();
        std::string result( n, 0 );
        for (int i = num1.size() - 1; i >= 0; i--) {
            for (int j = num2.size() - 1; j >= 0; j--) {
                
                int n = (num1[i] - '0') * (num2[j] - '0') + result[i + j + 1] ;
                
                result[i + j + 1] = n % 10;
                
                result[i + j] += n / 10;
            }
        }
        
       for (int i = 0; i < result.size(); i++) {
          result[i] += '0';
      }
       
        return result[0] == '0' ? result.substr(1) : result;
    }
};