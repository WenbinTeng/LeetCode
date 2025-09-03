#include <vector>

class Solution {
  public:
    std::vector<bool>
    pathExistenceQueries(int n, std::vector<int> &nums, int maxDiff,
                         std::vector<std::vector<int>> &queries) {
        std::vector<int> connectedPart(n);
        for (int i = 1; i < n; i++) {
            connectedPart[i] =
                connectedPart[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }

        std::vector<bool> res;
        for (auto &q : queries) {
            res.push_back(connectedPart[q[0]] == connectedPart[q[1]]);
        }
        return res;
    }
};