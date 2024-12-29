#include <vector>
#include <string>
#include <algorithm>
#include <ranges>

class Solution {
   public:
    std::string rankTeams(std::vector<std::string>& votes) {
        int m = votes[0].length();
        std::string res = votes[0];
        std::vector<std::vector<int>> cnts(26, std::vector<int>(m));

        for (std::string& vote : votes) {
            for (int i = 0; i < m; i++) {
                cnts[vote[i] - 'A'][i]--;
            }
        }

        ranges::sort(res, {}, [&](char a) { return std::make_pair(cnts[a - 'A'], a); });

        return res;
    }
};