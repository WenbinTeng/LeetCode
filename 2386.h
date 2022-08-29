#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    long long kSum(std::vector<int>& nums, int k) {
        long long sum = 0;
        std::priority_queue<std::pair<long long, int>> pq;

        for (auto& num : nums)
        {
            if (num >= 0) sum += num; else num = -num;
        }

        std::sort(nums.begin(), nums.end());

        pq.push({sum, 0});

        while (--k)
        {
            auto [s, i] = pq.top();
            pq.pop();

            if (i < nums.size())
            {
                pq.push({s - nums[i], i + 1});
                if (i > 0) pq.push({s - nums[i] + nums[i - 1], i + 1});
            }
        }

        return pq.top().first;
    }
};