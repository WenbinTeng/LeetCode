#include <stack>
#include <vector>

class Solution {
  public:
    int maximumScore(std::vector<int> &nums, int k) {
        if (nums.empty())
            return 0;

        int res = 0;
        std::vector<int> lMin(nums.size(), -1);
        std::vector<int> rMin(nums.size(), nums.size());
        std::stack<int> s;

        for (int i = 0; i < nums.size(); ++i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                rMin[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        s = std::stack<int>();

        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                lMin[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }

        for (int i = 0; i < nums.size(); ++i) {
            int l = lMin[i] + 1;
            int r = rMin[i] - 1;

            if (l <= k && r >= k)
                res = std::max(res, nums[i] * (r - l + 1));
        }

        return res;
    }
};