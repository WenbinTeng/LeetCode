#include <algorithm>
#include <vector>

class Solution {
  public:
    int maxEnvelopes(std::vector<std::vector<int>> &envelopes) {
        if (envelopes.empty())
            return 0;

        std::sort(envelopes.begin(), envelopes.end(),
                  [](std::vector<int> &a, std::vector<int> &b) {
                      return a[0] < b[0];
                  });

        std::vector<int> dp(envelopes.size(), 1);

        dp[0] = 1;

        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] &&
                    envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};