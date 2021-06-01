class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        int cnt = 0;
        while (n)
        {
            cnt += n & 1;
            n = n >> 1;
        }

        return cnt == 1;
    }
};