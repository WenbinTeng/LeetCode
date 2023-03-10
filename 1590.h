#include <unordered_map>
#include <vector>

class Solution {
public:
    int minSubarray(std::vector<int> &nums, int p) {
        int n = nums.size();
        int x = 0;
        int res = n;
        std::vector<int> prevSum(n + 1);
        std::unordered_map<int, int> um;

        prevSum[0] = 0;
        for (int i = 0; i < n; ++i)
            prevSum[i + 1] = (prevSum[i] + nums[i]) % p;
        if (prevSum.back() == 0)
            return 0;

        x = prevSum[n];
        for (int i = 0; i <= n; ++i) {
            um[prevSum[i]] = i;
            auto it = um.find((prevSum[i] - x + p) % p);
            if (it != um.end())
                res = std::min(res, i - it->second);
        }

        return res < n ? res : -1;
    }
};