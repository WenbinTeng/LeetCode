#include <stack>
#include <vector>

class Solution {
  public:
    bool find132pattern(std::vector<int> &nums) {
        std::stack<int> s;

        int n = nums.size();
        int k = -INT_MAX - 1;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] < k)
                return true;

            while (!s.empty() && s.top() < nums[i]) {
                k = std::max(k, s.top());
                s.pop();
            }

            s.push(nums[i]);
        }

        return false;
    }
};