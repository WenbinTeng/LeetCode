#include <vector>

class Solution {
public:
    int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
        if (!check(nums, queries, queries.size()))
            return -1;

        int l = 0;
        int r = queries.size();

        while (l < r) {
            int mid = (l + r) / 2;
            if (check(nums, queries, mid))
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

private:
    bool check(std::vector<int>& nums, std::vector<std::vector<int>>& queries, int k) {
        std::vector<long long> diff(nums.size() + 1);
        for (int i = 0; i < k; i++) {
            auto& q = queries[i];
            diff[q[0]] += q[2];
            diff[q[1] + 1] -= q[2];
        }

        long long curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += diff[i];
            if (curr < nums[i])
                return false;
        }

        return true;
    }
};