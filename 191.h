class Solution {
public:
    int hammingWeight(unsigned int n) {
        int res = 0;

        while (n) {
            res += n & 1;
            n = n >> 1;
        }

        return res;
    }
};