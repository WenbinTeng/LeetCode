#include <stack>
#include <vector>

class Solution {
  public:
    int totalSteps(std::vector<int> &nums) {
        int res = 0;
        std::stack<std::pair<int, int>> s;

        for (const auto num : nums) {
            int maxT = 0;

            while (!s.empty() && s.top().first <= num) {
                maxT = std::max(maxT, s.top().second);
                s.pop();
            }

            if (!s.empty())
                ++maxT;
            res = std::max(res, maxT);
            s.push({num, maxT});
        }

        return res;
    }
};