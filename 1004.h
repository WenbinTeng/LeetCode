#include <vector>

class Solution {
public:
    int longestOnes(std::vector<int>& A, int K) {
        int res = 0;
        int cnt = K;
        int i = 0;
        int j = 0;
        while (j < A.size())
        {
            if (A[j] == 0) --cnt;

            while (i <= j && cnt < 0)
            {
                if (A[i] == 0) ++cnt; ++i;
            }

            ++j;

            res = std::max(res, j - i);
        }

        return res;
    }
};