#include <queue>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        std::vector<int> res;
        std::priority_queue<std::pair<int, int>> pq;

        for (int i = 0; i < k; ++i) {
            pq.push({nums[i], i});
        }

        res.push_back(pq.top().first);

        for (int i = k; i < nums.size(); ++i) {
            pq.push({nums[i], i});
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }

        return res;
    }
};