#include <stack>
#include <vector>

class Solution {
  public:
    std::vector<int> nextGreaterElements(std::vector<int> &nums) {
        std::vector<int> res(nums.size(), -1);
        std::stack<int> s;

        for (int i = 0, n = nums.size(); i < n * 2 - 1; ++i) {
            while (!s.empty() && nums[s.top()] < nums[i % n]) {
                res[s.top()] = nums[i % n];
                s.pop();
            }
            s.push(i % n);
        }

        return res;
    }
};