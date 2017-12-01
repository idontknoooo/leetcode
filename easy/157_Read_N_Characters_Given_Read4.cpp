// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {

        int res = 0;
        while (n > 0) {
            int tmp = min(read4(buf), n);
            res += tmp; // count the number of char we can read
            buf += tmp; // tell buf how many we have read
            n -= 4;
        }
        return res;
    }
};
