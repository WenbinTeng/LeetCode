#include <vector>

class Solution {
public:
    int countPairs(std::vector<int>& nums, int low, int high) {
        int* a = nums.data();
        int  n = nums.size();
        int  res = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                res += (a[i] ^ a[j]) >= low && (a[i] ^ a[j]) <= high ? 1 : 0;
            }
        }

        return res;
    }
};