#include <limits.h>

#include <vector>

class Solution {
  public:
    int minimumFinishTime(std::vector<std::vector<int>> &tires, int changeTime,
                          int numLaps) {
        std::vector<int> minTime(18, 1e+9);
        std::vector<int> dp(numLaps + 1, 1e+9);

        for (const auto &tire : tires) {
            long long sum = 0;
            long long prd = tire[0];

            for (int x = 1; x < 18; ++x) {
                if (prd > changeTime + tire[0])
                    break;

                sum += prd;
                prd *= tire[1];
                minTime[x] = std::min(minTime[x], (int)sum);
            }
        }

        dp[0] = -changeTime;

        for (int i = 1; i <= numLaps; ++i) {
            for (int j = 1; j <= std::min(i, 17); ++j) {
                dp[i] = std::min(dp[i], dp[i - j] + minTime[j]);
            }
            dp[i] += changeTime;
        }

        return dp[numLaps];
    }
};