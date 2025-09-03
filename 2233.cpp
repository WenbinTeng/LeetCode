#include <queue>
#include <vector>

class Solution {
  public:
    int maximumProduct(std::vector<int> &nums, int k) {
        int res = 1;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const auto num : nums) {
            pq.push(num);
        }

        for (int i = 0; i < k; ++i) {
            auto num = pq.top();
            pq.pop();
            pq.push(num + 1);
        }

        while (!pq.empty()) {
            res = ((long long)res * pq.top()) % (int)(1e+9 + 7);
            pq.pop();
        }

        return res;
    }
};