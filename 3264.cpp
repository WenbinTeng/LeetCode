#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> getFinalState(std::vector<int> &nums, int k,
                                   int multiplier) {
        std::vector<int> res(nums.size());
        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>,
                            std::greater<std::pair<int, int>>>
            pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        for (int i = 0; i < k; i++) {
            auto [x, index] = pq.top();
            pq.pop();
            pq.push({x * multiplier, index});
        }

        while (!pq.empty()) {
            auto [x, index] = pq.top();
            pq.pop();
            res[index] = x;
        }

        return res;
    }
};