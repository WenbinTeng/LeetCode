class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0;

        while (x || y) {
            if ((x & 1) != (y & 1))
                ++res;
            x = x >> 1;
            y = y >> 1;
        }

        return res;
    }
};