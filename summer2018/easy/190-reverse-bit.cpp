class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;    // Left shift to add 1 more position for a new bit
            res += n & 1; // Get only most right bit
            n >>= 1;      // Remove used most right bit
        } // do it 32 times
        return res;
    }
};
