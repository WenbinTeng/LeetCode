#include <vector>
#include <queue>

class Solution {
public:
    int minOperations(std::vector<int>& nums, int k) {
        int res = 0;
        std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

        for (auto num : nums) {
            pq.push(num);
        }

        while (pq.size() >= 2 && pq.top() < k) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(x * 2 + y);
            res++;
        }

        return res;
    }
};