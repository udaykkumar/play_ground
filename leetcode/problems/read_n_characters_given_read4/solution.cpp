/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int nread {0};
        while (nread < n ) {
            const int read = read4(buf + nread);
            nread += read;
            if(read <= 0)
                break;
        }
        
        return min(n, nread);
    }
};