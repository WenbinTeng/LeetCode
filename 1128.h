#include <unordered_map>
#include <vector>

class Solution {
public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes) {
        int res = 0;
        std::unordered_map<int, int> um;

        for (const auto &domino : dominoes) {
            int a = std::max(domino[0], domino[1]);
            int b = std::min(domino[0], domino[1]);
            um[a * 10 + b]++;
        }

        for (const auto &[_, cnt] : um) {
            res += cnt * (cnt - 1) / 2;
        }

        return res;
    }
};