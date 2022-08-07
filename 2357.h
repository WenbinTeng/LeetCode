#include <vector>
#include <queue>

class Solution {
public:
    int minimumOperations(std::vector<int>& nums) {
        int res = 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (const auto num : nums)
        {
            if (num != 0) pq.push(num);
        }

        while (!pq.empty())
        {
            int size = pq.size();
            int x = pq.top();
            std::priority_queue<int, std::vector<int>, std::greater<int>> temp;

            for (int i = 0; i < size; ++i)
            {
                int top = pq.top() - x;
                if (top != 0) temp.push(top);
                pq.pop();
            }

            pq = temp;
            ++res;
        }

        return res;
    }
};