#include <vector>

class Solution {
public:
    std::vector<bool> canEat(std::vector<int> &candiesCount, std::vector<std::vector<int>> &queries) {
        std::vector<bool> res;
        std::vector<long long> prefixSum = {candiesCount[0]};
        for (int i = 1; i < candiesCount.size(); i++) {
            prefixSum.push_back(prefixSum[i - 1] + candiesCount[i]);
        }

        for (const auto &iter : queries) {
            res.push_back(!(iter[1] + 1 > prefixSum[iter[0]] || (long long)(iter[1] + 1) * iter[2] < (iter[0] == 0 ? 1 : prefixSum[iter[0] - 1] + 1)));
        }

        return res;
    }
};