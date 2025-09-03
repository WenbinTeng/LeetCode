#include <algorithm>
#include <unordered_map>
#include <vector>

class Solution {
  public:
    std::vector<int>
    findingUsersActiveMinutes(std::vector<std::vector<int>> &logs, int k) {
        int cnt = 1;
        std::vector<int> res(k);

        std::sort(logs.begin(), logs.end());

        for (int i = 1; i < logs.size(); ++i) {
            if (logs[i][0] == logs[i - 1][0]) {
                if (logs[i][1] != logs[i - 1][1]) {
                    ++cnt;
                }
            } else {
                ++res[cnt - 1];
                cnt = 1;
            }
        }

        if (cnt > 0)
            ++res[cnt - 1];

        return res;
    }
};