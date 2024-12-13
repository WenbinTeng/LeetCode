#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, int multiplier) {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }

        while (k--) {
            auto [n, i] = pq.top();
            pq.pop();
            pq.push({n * multiplier, i});
        }

        while (!pq.empty()) {
            auto [n, i] = pq.top();
            pq.pop();
            nums[i] = n;
        }

        return nums;
    }
};