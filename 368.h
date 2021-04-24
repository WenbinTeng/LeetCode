#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> largestDivisibleSubset(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        std::vector<int> f(n, 0);
        std::vector<int> g(n, 0);
        std::vector<int> res;

        for (int i = 0; i < n; ++i)
        {
            int len = 1;
            int pre = i;

            for (int j = 0; j < i; ++j)
            {
                if (len < f[j] + 1 && nums[i] % nums[j] == 0)
                {
                    len = f[j] + 1;
                    pre = j;
                }
            }

            f[i] = len;
            g[i] = pre;
        }

        int index = std::max_element(f.begin(), f.end()) - f.begin();
        int value = f[index];

        while (res.size() != value)
        {
            res.push_back(nums[index]);
            index = g[index];
        }

        return res;
    }
};