#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
        std::vector<int> ans0;
        std::vector<int> ans1;
        std::unordered_set<int> us;
        std::unordered_map<int, int> um;

        for (const auto match : matches)
        {
            us.insert(match[0]);
            us.insert(match[1]);
            ++um[match[1]];
        }

        for (const auto player : us)
        {
            if (um[player] == 0)
            {
                ans0.push_back(player);
            }
            else if (um[player] == 1)
            {
                ans1.push_back(player);
            }
        }

        std::sort(ans0.begin(), ans0.end());
        std::sort(ans1.begin(), ans1.end());

        return {ans0, ans1};
    }
};