#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int maximumSum(std::vector<int>& nums) {
        int res = -1;
        std::unordered_map<int, std::vector<int>> um;

        for (const auto n : nums)
        {
            int sum = 0;
            int num = n;
            
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }

            um[sum].push_back(n);
        }

        for (auto &[_, vec] : um)
        {
            if (vec.size() > 1)
            {
                std::sort(vec.begin(), vec.end(), std::greater<int>());
                res = std::max(res, vec[0] + vec[1]);
            }
        }

        return res;
    }
};