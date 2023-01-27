#include <queue>
#include <vector>

class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        std::priority_queue<int> pq;

        for (const auto num : nums) {
            pq.push(num);
        }

        for (int i = 0; i < k - 1; ++i) {
            pq.pop();
        }

        return pq.top();
    }
};