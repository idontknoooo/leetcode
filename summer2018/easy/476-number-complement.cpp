// Manipulate bit with a mask
class Solution {
public:
    int findComplement(int num) {
        int copy = num;
        int i = 0;

        while(copy) {
            copy >>= 1;
            num ^= (1<<i); // Toggle bit use mask
            i += 1;
        }
        return num;
    }
};


// Use power of 2 -1 as a mask
class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        int temp = num;
        
        while(temp > 0)
        {
            mask = mask<<1;
            temp = temp>>1;
        }
        return num^(mask-1);
    }
};

// Same as above
class Solution {
public:

    int findComplement(int num) {
        unsigned mask = ~0; // I guess it gonna be all 1s?
        while (num & mask) mask <<= 1;
        return ~mask & ~num;

    }

};
