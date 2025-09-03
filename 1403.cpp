#include <cmath>
#include <queue>
#include <vector>

class Solution {
  public:
    std::vector<int> minSubsequence(std::vector<int> &nums) {
        int sum = 0;
        std::vector<int> res;
        std::priority_queue<int, std::vector<int>, std::less<int>> pq;

        for (const auto num : nums) {
            sum += num;
            pq.push(num);
        }

        sum = std::floor(sum / 2.0);

        while (!pq.empty() && sum >= 0) {
            res.push_back(pq.top());
            sum -= pq.top();
            pq.pop();
        }

        return res;
    }
};