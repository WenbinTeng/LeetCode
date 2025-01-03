#include <vector>
#include <queue>

class Solution {
public:
    long long maximumTotalSum(std::vector<int>& maximumHeight) {
        long long res = 0;
        int height = INT_MAX;
        std::priority_queue<int> pq;

        for (auto height : maximumHeight) {
            pq.push(height);
        }

        while (!pq.empty()) {
            if (height <= 0)
                return -1;
            int maxHeight = pq.top();
            pq.pop();
            height = std::min(height, maxHeight);
            res += height;
            height--;
        }

        return res;
    }
};