#include <string>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    long long distinctNames(std::vector<std::string> &ideas) {
        long long res = 0;
        std::unordered_map<std::string, int> group;
        std::vector<std::vector<int>> cnt(26, std::vector<int>(26, 0));

        for (const auto &idea : ideas) {
            group[idea.substr(1)] |= 1 << (idea[0] - 'a');
        }

        for (auto [_, mask] : group) {
            for (int i = 0; i < 26; ++i) {
                if ((mask >> i & 1) == 0) {
                    for (int j = 0; j < 26; ++j) {
                        if ((mask >> j & 1) == 1) {
                            ++cnt[i][j];
                        }
                    }
                } else {
                    for (int j = 0; j < 26; ++j) {
                        if ((mask >> j & 1) == 0) {
                            res += cnt[i][j];
                        }
                    }
                }
            }
        }

        return res * 2;
    }
};